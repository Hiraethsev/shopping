#include"searchforinformation.cpp"

void InputChangeInformation(GoodsList &L)
{
    int num,i;
    GoodsList p;
    FILE * myfile=fopen("D:\\华中师范大学\\编程\\c++\\goods.txt","w+");

    
    if(myfile==NULL)
    {
        cerr<<"File open or create error!"<<endl;
        exit(1);
    }

    num=Exportnum();
    p=L->next;
    
    for(i=1;i<=num;i++)
    {
        fprintf(myfile,"%s %s %f,%f,%d,%d,%d,%d",p->name,p->number,p->openprice,p->sellprice,p->amount,p->date.year,p->date.month,p->date.day);
        p=p->next;
    }  
    fclose(myfile);

}



void ChangeByName(GoodsList &L)
{
    GoodsList p;
    char line[30];
    int a=1;
    int flag1=0,type=1;

    p=L->next;
    cout<<"请输入要修改的商品名称："<<endl;
    scanf("%s",line);
    while(p)
    {    
        if(strcmp(line,p->name)==0)
    {
        ExportExistOneInformation(p);
        cout<<"是否要修改该商品数据(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"请输入要修改的商品数据类型(1-进价,2-售价,3-库存,4-生产日期)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"请输入新进价"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"请输入新售价"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"请输入新库存"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"请输入生产日期"<<endl;
                 scanf("%d %d %d",&p->date.year,&p->date.month,&p->date.day);
                break;

            }

        }

        a=0;
    }
        p=p->next;
    }
    InputChangeInformation(L);
    if(a)
    cout<<"没有该商品"<<endl;
    


}

void ChangeByNumber(GoodsList &L)
{
    GoodsList p;
    char line[10];
    int a=1;
    int flag1=0,type=1;

    p=L->next;
    cout<<"请输入要修改的商品编号："<<endl;
    scanf("%s",line);
    while(p)
    {    
        if(strcmp(line,p->name)==0)
    {
        ExportExistOneInformation(p);
        cout<<"是否要修改该商品数据(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"请输入要修改的商品数据类型(1-进价,2-售价,3-库存,4-生产日期)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"请输入新进价"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"请输入新售价"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"请输入新库存"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"请输入生产日期"<<endl;
                 scanf("%d %d %d",&p->date.year,&p->date.month,&p->date.day);
                break;

            }

        }

        a=0;
    }
        p=p->next;
    }
    InputChangeInformation(L);
    if(a)
    cout<<"没有该商品"<<endl;
    


}


void ChangeByAmount(GoodsList &L)
{
    GoodsList p;
    int i,j;
    int a=1;
    int flag1=0,type=1;

    p=L->next;
    cout<<"请输入要查找的商品的库存最小值和最大值："<<endl;
    scanf("%d %d",&i,&j);
    while(p)
    {    
        if(p->amount>=i&&p->amount<=j)
    {
        ExportExistOneInformation(p);
        cout<<"是否要修改该商品数据(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"请输入要修改的商品数据类型(1-进价,2-售价,3-库存,4-生产日期)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"请输入新进价"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"请输入新售价"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"请输入新库存"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"请输入生产日期"<<endl;
                 scanf("%d %d %d",&p->date.year,&p->date.month,&p->date.day);
                break;

            }

        }

        a=0;
    }
        p=p->next;
    }
    InputChangeInformation(L);
    if(a)
    cout<<"没有该商品"<<endl;
    


}


