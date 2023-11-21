#include"Readexistinginformation.cpp"

using namespace std;


void ExportExistOneInformation(GoodsList p)
{
    if(p)
    {
        cout<<endl<<"以下是商品的信息"<<endl;
        cout<<"名字是 "<<p->name<<endl;
        cout<<"编号（其中第一位为商品种类代码）是 "<<p->number<<endl;
        cout<<"进价是 "<<p->openprice<<endl;
        cout<<"售价是"<<p->sellprice<<endl;
        cout<<"库存量为"<<p->amount<<endl;
        cout<<"生产日期是"<<p->date.year<<" ";
        cout<<setfill('0')<<setw(2)<<p->date.month<<" "<<setw(2)<<p->date.day<<endl;
    }
}

void SearchByName(GoodsList &L)
{
    GoodsList p;
    char line[30];
    int a=1;

    p=L->next;
    cout<<"请输入要查找的商品名称："<<endl;
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
    cout<<"没有该商品"<<endl;
   
} 



void SearchByNumber(GoodsList &L)
{
    GoodsList p;
    char line[10];
    int a=1;

    p=L->next;
    cout<<"请输入要查找的商品编号："<<endl;
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
    cout<<"没有该商品"<<endl;

} 

void SearchByAmount(GoodsList &L)
{
    GoodsList p;
    int i,j;
    int a=1;

    p=L->next;
    cout<<"请输入要查找的商品的库存最小值和最大值:"<<endl;
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
    cout<<"没有该商品"<<endl;
}

