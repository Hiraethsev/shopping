#include"Readexistinginformation.cpp"

using namespace std;


void ExportExistOneInformation(GoodsList p)
{
    if(p)
    {
        cout<<endl<<"��������Ʒ����Ϣ"<<endl;
        cout<<"������ "<<p->name<<endl;
        cout<<"��ţ����е�һλΪ��Ʒ������룩�� "<<p->number<<endl;
        cout<<"������ "<<p->openprice<<endl;
        cout<<"�ۼ���"<<p->sellprice<<endl;
        cout<<"�����Ϊ"<<p->amount<<endl;
        cout<<"����������"<<p->date.year<<" ";
        cout<<setfill('0')<<setw(2)<<p->date.month<<" "<<setw(2)<<p->date.day<<endl;
    }
}

void SearchByName(GoodsList &L)
{
    GoodsList p;
    char line[30];
    int a=1;

    p=L->next;
    cout<<"������Ҫ���ҵ���Ʒ���ƣ�"<<endl;
    scanf("%s",line);
    while(p)
    {
        if(strcmp(line,p->name)==0)
    {
        ExportExistOneInformation(p);
        a=0;
    }
        p=p->next;
    }
    if(a)
    cout<<"û�и���Ʒ"<<endl;
   
} 



void SearchByNumber(GoodsList &L)
{
    GoodsList p;
    char line[10];
    int a=1;

    p=L->next;
    cout<<"������Ҫ���ҵ���Ʒ��ţ�"<<endl;
    scanf("%s",line);
    while(p)
    {
        if(strcmp(line,p->number)==0)
    {
        ExportExistOneInformation(p);
        a=0;
    }
        p=p->next;
    }
    if(a)
    cout<<"û�и���Ʒ"<<endl;

} 

void SearchByAmount(GoodsList &L)
{
    GoodsList p;
    int i,j;
    int a=1;

    p=L->next;
    cout<<"������Ҫ���ҵ���Ʒ�Ŀ����Сֵ�����ֵ:"<<endl;
    scanf("%d %d",&i,&j);
    while(p)
    {
        if(p->amount>=i&&p->amount<=j)
        {
            ExportExistOneInformation(p);
            a=0;
        }
        p=p->next;
    }
    if(a)
    cout<<"û�и���Ʒ"<<endl;
}

