#include"s0.h"

#include"changeinformation.cpp"

int main()
{
    GoodsList L;
    int i,j,sign=1,flag=1,a=1,num=0;

    while(sign)
    {
    cout<<"������ѡ���ģʽ(0/1/2/3/4)"<<endl;
    cout<<"1.�����µ���Ʒ��Ϣ"<<endl;
    cout<<"2.��ȡ���е���Ʒ��Ϣ"<<endl;
    cout<<"3.�������е���Ʒ��Ϣ"<<endl;
    cout<<"4.�޸����е���Ʒ��Ϣ"<<endl;
    cin>>i;
    switch(i)
    {
        case 1:
        InputInformation(L);
        ExportExistInformation(L);
        DestroyList(L);
        break;

        case 2:
        num=Exportnum();
        cout<<"����"<<num<<"����Ʒ��Ϣ"<<endl;
        RetrieveInformation(L);
        ExportExistInformation(L);
        DestroyList(L);
        break;
        
        case 3:
        {
        RetrieveInformation(L);
        while(flag)
        {
            
            cout<<endl<<"������ѡ�������Ʒ��ģʽ(0/1/2/3/4)"<<endl;
            cout<<"1.�����ֲ�����Ʒ��Ϣ"<<endl;
            cout<<"2.�ñ�Ų�����Ʒ��Ϣ"<<endl;
            cout<<"3.������"<<endl;
            cin>>j;
            switch(j)
            {
                case 1:
                SearchByName(L);
                break;
                case 2:
                SearchByNumber(L);
                break;
                case 3:
                SearchByAmount(L);
                break;
                case 0:
                flag=0;
                break;
       
            }
        }
        DestroyList(L);
        break;
        }
         case 4:
            {
        RetrieveInformation(L);
        while(a)
        {
            
            cout<<endl<<"������ѡ���޸���Ʒ��ģʽ(0/1/2/3/4)"<<endl;
            cout<<"1.�����ֲ�����Ʒ��Ϣ"<<endl;
            cout<<"2.�ñ�Ų�����Ʒ��Ϣ"<<endl;
            cout<<"3.������"<<endl;
            cin>>j;
            switch(j)
            {
                case 1:
                ChangeByName(L);
                break;
                case 2:
                ChangeByNumber(L);
                break;
                case 3:
                ChangeByAmount(L);
                break;
                case 0:
                a=0;
                break;
       
            }
        }
        DestroyList(L);
        break;
        }
        case 0:
        a=0;
        break;
    }
    }
    return 0;
}