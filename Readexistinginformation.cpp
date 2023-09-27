#include"inputinformation.cpp"

using namespace std;


void RetrieveInformation(GoodsList &L)
{
    GoodsList p,q;
    int i,num;
    FILE * myfile=fopen("D:\\ccnu\\c++\\goods.txt","r");
    
    if(myfile==NULL)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }

    InitList(L);
    q=L;

    rewind(myfile);
    num=Exportnum();
    for(i=1;i<=num;i++)
    {
         p=(GoodsList)malloc(sizeof(SupermarketProduct));
         fscanf(myfile,"%s%s",p->name,p->number);
         fscanf(myfile,"%f,%f,%d,%d,%d,%d",&p->openprice,&p->sellprice,&p->amount,&p->date.year,&p->date.month,&p->date.day);
         q->next=p;
         q=q->next;
    }
     p->next=NULL;

    fclose(myfile);
    
}
