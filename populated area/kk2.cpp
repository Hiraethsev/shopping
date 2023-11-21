#include <iostream>
#include <vector>

using namespace std;


typedef struct
{
    string start;
    string end;
    float value;
    
} onelement;



typedef struct
{
    string name;
    int status;

} pointstatus;

int Part(onelement *elements, int left, int right){
        onelement stroage=elements[left];
        float value=elements[left].value;

        while(left<right){
            while(left<right&&elements[right].value>=value)
            --right;

            if(left<right)
            elements[left++]=elements[right];

            while (left < right && elements[left].value <= value)
                ++left;

            if (left < right)
                elements[right--] = elements[left];

               
        }

        elements[left] = stroage;
        return left;
}

void QSort(onelement *elements,int left,int right){
    if(left<right){
        int middle=Part(elements,left,right);
        QSort(elements, left, middle-1);
        QSort(elements, middle+1,right);
    }

}
void Sort(int n, vector<pointstatus> &names, onelement *elements,int num)
{
    vector<string> point;
    vector<onelement> edgeset;

    QSort(elements,0,num);

    for (int i = 0; i<=num; i++)
    {
        
        int startstatus=-1,endstatus=-1;
        int startflag=1,endflag=1;

        for(int j=0;j<n;j++){

            if(startflag)
            if(names[j].name==elements[i].start){
                startstatus = j;
                startflag=0;
            }

            if (endflag)
                if (names[j].name == elements[i].end)
                {
                    endstatus = j;
                    endflag = 0;
                }
        }

       
        if (names[startstatus].status != names[endstatus].status){
            int oldstatus = names[startstatus].status; for (int i = 0; i < n; i++)
            if (names[i].status == oldstatus)
            names[i].status = names[endstatus].status;

            startflag = 1;
            endflag = 1;
            if(!point.empty()){
                for (string m : point){
                    if (startflag)
                        if (m == elements[i].start)
                        startflag = 0;

                    if (endflag)
                        if (m == elements[i].end)
                            endflag = 0;
                }
            }
            if(startflag)
                point.push_back(elements[i].start);

            if(endflag)
                point.push_back(elements[i].end);

            edgeset.push_back(elements[i]);
        }
        int ed = edgeset.size();
        if(ed>=n-1)
            break;
        int le = point.size();
        if (le >= n)
            break;  
    }

    float length=0;
    cout<<"最短的选择路径是："<<endl;
    for (auto t : edgeset){
        cout<<"("<<t.start<<","<<t.end<<")  ";
        length += t.value;
    }
    cout<<endl<<"最短的长度是"<<length;
    
}

int main()
{
    int n;
    string str,str1;
    vector<pointstatus> names;
    onelement *elements;
    cout << "请输入居民区的数量：";
    cin >> n;
    elements = new onelement[n*(n-1)/2];

    cout << "请输入居民区的名称：";
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        names.push_back({str,i});
    }

    cout <<endl<<"请输入居民区之间路径的权重:(输入#表示输入完毕)" << endl;
    cout << endl<< "请输入居民区的名称以及它们之间的路径权重："<<endl;
    int k=0;

        while(1)
        { 
            cin >> str;
            if (str == "#")
            break;
            cin >> str1 >> elements[k].value;
            elements[k].start = str;
            elements[k].end = str1;
            k++;

        }

    Sort(n,names,elements,k-1);
    delete[] elements;
    return 0;
}
