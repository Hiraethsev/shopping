#include"Product.h"
#include<fstream>
//using namespace std;


void Product_p::revise()
{
    string type;
    int h;
    int d = 0;
    system("cls");
    cout << endl << endl;

    cout << "\t\t\t\t                 修改商品信息                  " << endl;
    cout << endl << endl;
    
    string str[100];
    while (1)
    {
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             修改的商品类型：              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  电子产品                  **" << endl;
        cout << "\t\t\t\t  **             2.  蔬果                      **" << endl;
        cout << "\t\t\t\t  **             3.  零食                      **" << endl;
        cout << "\t\t\t\t  **             4.  美妆                      **" << endl;
        cout << "\t\t\t\t  **             5.  文具                      **" << endl;
        cout << "\t\t\t\t  **             6.  服装                      **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t 请选择：";  cin >> h;

        if (0 < h && h < 7)  break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               输入错误,请重新输入                  \n" << endl;
        }
    }
    Product* t = first;
    Product* p = NULL;
    if (h == 7)
    {
        while (1)
        {
            
            cout << "\t\t\t\t    请输入商品名称："; getchar(); getline(cin, str[0]);
            t = first;
            int g = 0;
            while (t)
            {
                if (t->product_name == str[0])
                {
                    g = 1;
                    d = 1;
                    break;
                }
                t = t->next;
            }
            char ch;
            if (g != 1) 
            {
                while (1)
                {
                    cout << "\t\t\t\t  没有此商品,是否还有搜索（y/n）"; ch = getchar();
                    if (ch == 'N' || ch == 'n' || ch == 'y' || ch == 'Y')break;
                    else cout << "\t\t\t\t  操作错误，重新操作！" << endl;
                }
                if (ch == 'N' || ch == 'n') return;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        switch (h)
        {
        case 1:type = "电子产品"; break;
        case 2:type = "蔬果"; break;
        case 3:type = "零食"; break;
        case 4:type = "美妆"; break;
        case 5:type = "文具"; break;
        case 6:type = "服装"; break;
        }


        
        cout << "\n\t\t\t\t   商品的名称：" << endl;

        string str[100];

        while (t)
        {
            if (t->product_type == type)
            {
                cout << "\t\t\t\t   " << d + 1 << "." << t->product_name << endl;
                str[d] = t->product_name;
            }
            t = t->next;
            d++;
        }
        cout << "\n\t\t\t\t  请选择修改的商品："; cin >> d;
    }
   
    int f;
    while (1)
    {
        system("cls");
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             修改的商品属性：              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  商品编号                  **" << endl;
        cout << "\t\t\t\t  **             2.  商品进货价                **" << endl;
        cout << "\t\t\t\t  **             3.  商品售价                  **" << endl;
        cout << "\t\t\t\t  **             4.  商品进货量                **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t 请选择需要修改的属性：";  cin >> f;
  
        if (0 < f && f < 5) break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               输入错误,请重新输入                  \n" << endl;
        }
    }
    int code, number;
    double sell, buy;
    switch (f)
    {
        cout << endl;
    case 1:cout << "\t\t\t\t 商品编号改为："; cin >> code; break;
    case 2:cout << "\t\t\t\t 商品进货价改为："; cin >> buy; break;
    case 3:cout << "\t\t\t\t 商品售价改为："; cin >> sell; break;
    case 4:cout << "\t\t\t\t 商品进货量改为："; cin >> number; break;
    }
    t = first;
    while (t)
    {
        if (t->product_name == str[d - 1])
        {
            switch (f)
            {
            case 1:t->product_code=code; break;
            case 2:t->buy_price = buy; break;
            case 3:t->sell_price = sell; break;
            case 4:t->product_number = number; break;
            }
            break;
        }
        t = t->next;
    }
   
    cout << "\t\t\t\t                   修改成功                  \n" << endl;
    
    //将修改后的商品信息读入文件
    ofstream outfile("数据.dat", ios::out);
    t = first;
    while (t)
    {
        outfile << t->product_type << " " << t->product_name << " " << t->product_code << " "
            << t->buy_price << " " << t->sell_price << " " << t->product_number << " "
            << t->comment << " " << t->sales_volume << " " << t->search_volume << " "
            << t->S_T << " " << t->G_T << " " << t->shopping_car 
            << " " << t->shopping << " " << t->order_number << " " << t->order_number_1 << endl;
        t = t->next;
    }
    outfile.close();

}
