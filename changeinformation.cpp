#include"searchforinformation.cpp"

void InputChangeInformation(GoodsList &L)
{
    int num,i;
    GoodsList p;
    FILE * myfile=fopen("D:\\����ʦ����ѧ\\���\\c++\\goods.txt","w+");

    
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
    cout<<"������Ҫ�޸ĵ���Ʒ���ƣ�"<<endl;
    scanf("%s",line);
    while(p)
    {    
        if(strcmp(line,p->name)==0)
    {
        ExportExistOneInformation(p);
        cout<<"�Ƿ�Ҫ�޸ĸ���Ʒ����(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"������Ҫ�޸ĵ���Ʒ��������(1-����,2-�ۼ�,3-���,4-��������)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"�������½���"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"���������ۼ�"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"�������¿��"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"��������������"<<endl;
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
    cout<<"û�и���Ʒ"<<endl;
    


}

void ChangeByNumber(GoodsList &L)
{
    GoodsList p;
    char line[10];
    int a=1;
    int flag1=0,type=1;

    p=L->next;
    cout<<"������Ҫ�޸ĵ���Ʒ��ţ�"<<endl;
    scanf("%s",line);
    while(p)
    {    
        if(strcmp(line,p->name)==0)
    {
        ExportExistOneInformation(p);
        cout<<"�Ƿ�Ҫ�޸ĸ���Ʒ����(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"������Ҫ�޸ĵ���Ʒ��������(1-����,2-�ۼ�,3-���,4-��������)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"�������½���"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"���������ۼ�"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"�������¿��"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"��������������"<<endl;
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
    cout<<"û�и���Ʒ"<<endl;
    


}


void ChangeByAmount(GoodsList &L)
{
    GoodsList p;
    int i,j;
    int a=1;
    int flag1=0,type=1;

    p=L->next;
    cout<<"������Ҫ���ҵ���Ʒ�Ŀ����Сֵ�����ֵ��"<<endl;
    scanf("%d %d",&i,&j);
    while(p)
    {    
        if(p->amount>=i&&p->amount<=j)
    {
        ExportExistOneInformation(p);
        cout<<"�Ƿ�Ҫ�޸ĸ���Ʒ����(1/0)?"<<endl;
        scanf("%d",&flag1);
        while(flag1)
        {
            cout<<"������Ҫ�޸ĵ���Ʒ��������(1-����,2-�ۼ�,3-���,4-��������)"<<endl;
            scanf("%d",&type);
            switch(type)
            {
                case 0:
                flag1=0;
                break;
                case 1:
                cout<<"�������½���"<<endl;
                 scanf("%f",&p->openprice);
                break; 
                case 2:
                cout<<"���������ۼ�"<<endl;
                 scanf("%f",&p->sellprice);
                break;
                case 3:
                cout<<"�������¿��"<<endl;
                 scanf("%d",&p->amount);
                break;
                case 4:
                cout<<"��������������"<<endl;
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
    cout<<"û�и���Ʒ"<<endl;
    


}


