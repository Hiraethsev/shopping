#include"Product.h"
#include<fstream>

//定义删除商品信息的成员函数
void Product_p::delet()
{
    system("cls");
    string type,Name = "00";
    
    cout << endl << endl;
    cout << "\t\t\t\t                 删除商品信息                  " << endl;
    cout << endl << endl;
    int h;
    while (1)
    {
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             删除的商品类型：              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  电子产品                  **" << endl;
        cout << "\t\t\t\t  **             2.  蔬果                      **" << endl;
        cout << "\t\t\t\t  **             3.  零食                      **" << endl;
        cout << "\t\t\t\t  **             4.  美妆                      **" << endl;
        cout << "\t\t\t\t  **             5.  文具                      **" << endl;
        cout << "\t\t\t\t  **             6.  服装                      **" << endl;
        cout << "\t\t\t\t  **             7.  搜索                      **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t 请选择：";  cin >> h;
        cout << endl;
 
        if (0 < h && h < 8)  break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               输入错误,请重新输入                  \n" << endl;
        }
   
    }
    switch (h)
    {
    case 1:type = "电子产品"; break;
    case 2:type = "蔬果"; break;
    case 3:type = "零食"; break;
    case 4:type = "美妆"; break;
    case 5:type = "文具"; break;
    case 6:type = "服装"; break;
    }
    
    Product* t = first;
    Product* p = NULL;
    string str[100];
    int d = 0, f = 0;
   
    if (h == 7)
    {
        while (1)
        {
            cout << "\t\t\t\t    删除的商品的名称：";
            getchar();
            getline(cin, Name);
            int m = 0;
            while (t)
            {
                if (t->product_name == Name)
                {
                    str[0] = Name;
                    m = 1;
                    d = 1;
                    break;
                }
                t = t->next;
            }
            if (m == 1) break;
            else
            {
                while (1)
                {
                    cout << "\t\t\t\t    没有此商品,是否继续搜索（y/n）" << endl;
                    char ch;
                    ch = getchar();
                    if (ch == 'n' || ch == 'N') return;
                    else if (ch == 'Y' || ch == 'y') break;
                    else cout << "\t\t\t\t    操作错误，重新操作！" << endl;
                }
            }
        }
        
    }
    else
    {
        t = first;
        d = 0;
        while (t)
        {
            if (t->product_type == type)
            {
                cout << "\t\t\t\t   " << d + 1 << "." << t->product_name << endl;
                str[d] = t->product_name;
                f = d+1;
                d++;
            }
            t = t->next;
            
        }
        while (1)
        {
            cout << "\n\t\t\t\t    请选择删除的商品："; cin >> d; d = d - 1;
            if (0 <= d && d < f)break;
            else cout << "\t\t\t\t    操作错误，重新操作！" << endl;
            
        }
       
    }
   

    
    t = first;

    while (t)
    {
        if (t->product_name == str[d])
        {
            if (!p)
            {
                first = first->next;
                
                cout << "\n\t\t\t\t    成功删除该商品" << endl;
                delete t;
            }
            else
            {
                p->next = t->next;
                cout << "\n\t\t\t\t    成功删除该商品" << endl;
                delete t;                                   
            }
            break;
        }
        p = t;
        t = t->next;
    }
   
    
    
    //将删除后的商品信息读入文件
    ofstream outfile("数据.dat", ios::out);
    t = first;
    while (t)
    {
        outfile << t->product_type << " " << t->product_name << " " << t->product_code << " "
            << t->buy_price << " " << t->sell_price << " " << t->product_number << " "
            << t->comment << " " << t->sales_volume << " " << t->search_volume << " "
            << t->S_T << " " << t->G_T << " " 
            << t->shopping_car << " " << t->shopping << " " << t->order_number << " " << t->order_number_1 << endl;
        t = t->next;
    }
    outfile.close();
}