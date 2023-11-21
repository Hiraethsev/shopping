

using namespace std;

void InitList(GoodsList &L)
{
    L=(GoodsList)malloc(sizeof(SupermarketProduct));
    if(!L)
    exit(OVERFLOW);
    L->next=NULL;
}

int Exportnum()
 {
    int num=0;
    FILE *numfile=fopen("D:\\华中师范大学\\编程\\c++\\num.txt","r");
     if(numfile==NULL)
    {
        cerr<<"can't open!"<<endl;
        exit(1);
    }
    fscanf(numfile,"%d",&num);
    fclose(numfile);
    return(num);

 }

void CheckInformation(GoodsList &p,int i)
{
    while((p->openprice>=p->sellprice))
    { 
        int j=0;
        cout<<"商品进价大于或等于售价，请确认商品进价为"<<p->openprice<<" 售价为"<<p->sellprice<<endl;
        cout<<"如果进价输入错误请按1,售价输入错误请按2,全部输入错误请按3,确认无误请按0"<<endl;
        cin>>j;
        switch(j)
        {
            case 1:   cout<<"请输入商品"<<i<<"进价"<<endl;
                      cin>>p->openprice;
                      break;
            case 2:    cout<<"请输入商品"<<i<<"售价"<<endl;
                     cin>>p->sellprice;    
                     break;
            case 3:    cout<<"请输入商品"<<i<<"进价"<<endl;
                       cin>>p->openprice;
                        cout<<"请输入商品"<<i<<"售价"<<endl;
                        cin>>p->sellprice;
                        break;
           default:break;
        }
        if(j==0)
        break;

    }
}

void ChangeNum(int num)
{
    int sum;
    FILE *numfile=fopen("D:\\华中师范大学\\编程\\c++\\num.txt","r");
     if(numfile==NULL)
    {
        cerr<<"can't open!"<<endl;
        exit(1);
    }
    if(fscanf(numfile,"%d",&sum)!=EOF)
    {
        sum=sum+num;
    }
    else
    sum=num;
    fclose(numfile);

    numfile=fopen("D:\\华中师范大学\\编程\\c++\\num.txt","w");
     if(numfile==NULL)
    {
        cerr<<"can't open!"<<endl;
        exit(1);
    }
    fprintf(numfile,"%d",sum);
    fclose(numfile);
}


void InputInformation(GoodsList &L)
{
    int num,i;
    GoodsList p,q;
    FILE * myfile=fopen("D:\\华中师范大学\\编程\\c++\\goods.txt","a");

    
    if(myfile==NULL)
    {
        cerr<<"File open or create error!"<<endl;
        exit(1);
    }

    cout<<"请输入新进货的商品种数:";
    cin>>num;
    InitList(L);
    q=L;
    
    for(i=1;i<=num;i++)
    {
        
        p=(GoodsList)malloc(sizeof(SupermarketProduct));
        cout<<endl<<"请输入商品"<<i<<"的信息："<<endl;
        cout<<"请输入商品"<<i<<"的名字"<<endl;
        cin>>p->name;
        cout<<"请输入商品"<<i<<"的编号（其中第一位为商品种类代码）"<<endl;
        cin>>p->number;
        cout<<"请输入商品"<<i<<"进价"<<endl;
        cin>>p->openprice;
        cout<<"请输入商品"<<i<<"售价"<<endl;
        cin>>p->sellprice;
        CheckInformation(p,i);
        cout<<"请输入商品"<<i<<"进货数量"<<endl;
        cin>>p->amount;
        cout<<"请输入商品"<<i<<"的生产日期"<<endl;
        cin>>p->date.year>>p->date.month>>p->date.day;
        cout<<"商品"<<i<<"信息输入完毕"<<endl;
        fprintf(myfile,"%s %s %f,%f,%d,%d,%d,%d",p->name,p->number,p->openprice,p->sellprice,p->amount,p->date.year,p->date.month,p->date.day);
        q->next=p;
        q=q->next;
    }
     ChangeNum(num);
     p->next=NULL;
    fclose(myfile);


}

 

void ExportExistInformation(GoodsList &L)
{
     GoodsList p;
     int i=1;
     p=L->next;
     while(p)
     {
        cout<<endl<<"以下是商品"<<i<<"的信息"<<endl;
        cout<<"名字是 "<<p->name<<endl;
        cout<<"编号（其中第一位为商品种类代码）是 "<<p->number<<endl;
        cout<<"进价是 "<<p->openprice<<endl;
        cout<<"售价是"<<p->sellprice<<endl;
        cout<<"库存量为"<<p->amount<<endl;
        cout<<"生产日期是"<<p->date.year<<" ";
        cout<<setfill('0')<<setw(2)<<p->date.month<<" "<<setw(2)<<p->date.day<<endl;
        p=p->next;
        i++;
     }
}

void DestroyList(GoodsList &L)
{
    GoodsList  q;
    while(L)
    {
    q=L->next;
    free(L);
    L=q;
    }
}

