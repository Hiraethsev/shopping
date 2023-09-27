#include"s0.h"

#include"changeinformation.cpp"

int main()
{
    GoodsList L;
    int i,j,sign=1,flag=1,a=1,num=0;

    while(sign)
    {
    cout<<"请输入选择的模式(0/1/2/3/4)"<<endl;
    cout<<"1.输入新的商品信息"<<endl;
    cout<<"2.读取已有的商品信息"<<endl;
    cout<<"3.查找已有的商品信息"<<endl;
    cout<<"4.修改已有的商品信息"<<endl;
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
        cout<<"已有"<<num<<"个商品信息"<<endl;
        RetrieveInformation(L);
        ExportExistInformation(L);
        DestroyList(L);
        break;
        
        case 3:
        {
        RetrieveInformation(L);
        while(flag)
        {
            
            cout<<endl<<"请输入选择查找商品的模式(0/1/2/3/4)"<<endl;
            cout<<"1.用名字查找商品信息"<<endl;
            cout<<"2.用编号查找商品信息"<<endl;
            cout<<"3.库存查找"<<endl;
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
            
            cout<<endl<<"请输入选择修改商品的模式(0/1/2/3/4)"<<endl;
            cout<<"1.用名字查找商品信息"<<endl;
            cout<<"2.用编号查找商品信息"<<endl;
            cout<<"3.库存查找"<<endl;
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