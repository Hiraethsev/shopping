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

    cout << "\t\t\t\t                 �޸���Ʒ��Ϣ                  " << endl;
    cout << endl << endl;
    
    string str[100];
    while (1)
    {
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             �޸ĵ���Ʒ���ͣ�              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  ���Ӳ�Ʒ                  **" << endl;
        cout << "\t\t\t\t  **             2.  �߹�                      **" << endl;
        cout << "\t\t\t\t  **             3.  ��ʳ                      **" << endl;
        cout << "\t\t\t\t  **             4.  ��ױ                      **" << endl;
        cout << "\t\t\t\t  **             5.  �ľ�                      **" << endl;
        cout << "\t\t\t\t  **             6.  ��װ                      **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t ��ѡ��";  cin >> h;

        if (0 < h && h < 7)  break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               �������,����������                  \n" << endl;
        }
    }
    Product* t = first;
    Product* p = NULL;
    if (h == 7)
    {
        while (1)
        {
            
            cout << "\t\t\t\t    ��������Ʒ���ƣ�"; getchar(); getline(cin, str[0]);
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
                    cout << "\t\t\t\t  û�д���Ʒ,�Ƿ���������y/n��"; ch = getchar();
                    if (ch == 'N' || ch == 'n' || ch == 'y' || ch == 'Y')break;
                    else cout << "\t\t\t\t  �����������²�����" << endl;
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
        case 1:type = "���Ӳ�Ʒ"; break;
        case 2:type = "�߹�"; break;
        case 3:type = "��ʳ"; break;
        case 4:type = "��ױ"; break;
        case 5:type = "�ľ�"; break;
        case 6:type = "��װ"; break;
        }


        
        cout << "\n\t\t\t\t   ��Ʒ�����ƣ�" << endl;

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
        cout << "\n\t\t\t\t  ��ѡ���޸ĵ���Ʒ��"; cin >> d;
    }
   
    int f;
    while (1)
    {
        system("cls");
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             �޸ĵ���Ʒ���ԣ�              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  ��Ʒ���                  **" << endl;
        cout << "\t\t\t\t  **             2.  ��Ʒ������                **" << endl;
        cout << "\t\t\t\t  **             3.  ��Ʒ�ۼ�                  **" << endl;
        cout << "\t\t\t\t  **             4.  ��Ʒ������                **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t ��ѡ����Ҫ�޸ĵ����ԣ�";  cin >> f;
  
        if (0 < f && f < 5) break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               �������,����������                  \n" << endl;
        }
    }
    int code, number;
    double sell, buy;
    switch (f)
    {
        cout << endl;
    case 1:cout << "\t\t\t\t ��Ʒ��Ÿ�Ϊ��"; cin >> code; break;
    case 2:cout << "\t\t\t\t ��Ʒ�����۸�Ϊ��"; cin >> buy; break;
    case 3:cout << "\t\t\t\t ��Ʒ�ۼ۸�Ϊ��"; cin >> sell; break;
    case 4:cout << "\t\t\t\t ��Ʒ��������Ϊ��"; cin >> number; break;
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
   
    cout << "\t\t\t\t                   �޸ĳɹ�                  \n" << endl;
    
    //���޸ĺ����Ʒ��Ϣ�����ļ�
    ofstream outfile("����.dat", ios::out);
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
