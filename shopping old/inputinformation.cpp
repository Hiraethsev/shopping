

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
    FILE *numfile=fopen("D:\\����ʦ����ѧ\\���\\c++\\num.txt","r");
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
        cout<<"��Ʒ���۴��ڻ�����ۼۣ���ȷ����Ʒ����Ϊ"<<p->openprice<<" �ۼ�Ϊ"<<p->sellprice<<endl;
        cout<<"���������������밴1,�ۼ���������밴2,ȫ����������밴3,ȷ�������밴0"<<endl;
        cin>>j;
        switch(j)
        {
            case 1:   cout<<"��������Ʒ"<<i<<"����"<<endl;
                      cin>>p->openprice;
                      break;
            case 2:    cout<<"��������Ʒ"<<i<<"�ۼ�"<<endl;
                     cin>>p->sellprice;    
                     break;
            case 3:    cout<<"��������Ʒ"<<i<<"����"<<endl;
                       cin>>p->openprice;
                        cout<<"��������Ʒ"<<i<<"�ۼ�"<<endl;
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
    FILE *numfile=fopen("D:\\����ʦ����ѧ\\���\\c++\\num.txt","r");
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

    numfile=fopen("D:\\����ʦ����ѧ\\���\\c++\\num.txt","w");
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
    FILE * myfile=fopen("D:\\����ʦ����ѧ\\���\\c++\\goods.txt","a");

    
    if(myfile==NULL)
    {
        cerr<<"File open or create error!"<<endl;
        exit(1);
    }

    cout<<"�������½�������Ʒ����:";
    cin>>num;
    InitList(L);
    q=L;
    
    for(i=1;i<=num;i++)
    {
        
        p=(GoodsList)malloc(sizeof(SupermarketProduct));
        cout<<endl<<"��������Ʒ"<<i<<"����Ϣ��"<<endl;
        cout<<"��������Ʒ"<<i<<"������"<<endl;
        cin>>p->name;
        cout<<"��������Ʒ"<<i<<"�ı�ţ����е�һλΪ��Ʒ������룩"<<endl;
        cin>>p->number;
        cout<<"��������Ʒ"<<i<<"����"<<endl;
        cin>>p->openprice;
        cout<<"��������Ʒ"<<i<<"�ۼ�"<<endl;
        cin>>p->sellprice;
        CheckInformation(p,i);
        cout<<"��������Ʒ"<<i<<"��������"<<endl;
        cin>>p->amount;
        cout<<"��������Ʒ"<<i<<"����������"<<endl;
        cin>>p->date.year>>p->date.month>>p->date.day;
        cout<<"��Ʒ"<<i<<"��Ϣ�������"<<endl;
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
        cout<<endl<<"��������Ʒ"<<i<<"����Ϣ"<<endl;
        cout<<"������ "<<p->name<<endl;
        cout<<"��ţ����е�һλΪ��Ʒ������룩�� "<<p->number<<endl;
        cout<<"������ "<<p->openprice<<endl;
        cout<<"�ۼ���"<<p->sellprice<<endl;
        cout<<"�����Ϊ"<<p->amount<<endl;
        cout<<"����������"<<p->date.year<<" ";
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

