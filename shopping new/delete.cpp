#include"Product.h"
#include<fstream>

//����ɾ����Ʒ��Ϣ�ĳ�Ա����
void Product_p::delet()
{
    system("cls");
    string type,Name = "00";
    
    cout << endl << endl;
    cout << "\t\t\t\t                 ɾ����Ʒ��Ϣ                  " << endl;
    cout << endl << endl;
    int h;
    while (1)
    {
        cout << "\t\t\t\t  -----------------------------------------------" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             ɾ������Ʒ���ͣ�              **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t  **             1.  ���Ӳ�Ʒ                  **" << endl;
        cout << "\t\t\t\t  **             2.  �߹�                      **" << endl;
        cout << "\t\t\t\t  **             3.  ��ʳ                      **" << endl;
        cout << "\t\t\t\t  **             4.  ��ױ                      **" << endl;
        cout << "\t\t\t\t  **             5.  �ľ�                      **" << endl;
        cout << "\t\t\t\t  **             6.  ��װ                      **" << endl;
        cout << "\t\t\t\t  **             7.  ����                      **" << endl;
        cout << "\t\t\t\t  **                                           **" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t ��ѡ��";  cin >> h;
        cout << endl;
 
        if (0 < h && h < 8)  break;
        else
        {
            system("cls");
            cout << "\t\t\t\t               �������,����������                  \n" << endl;
        }
   
    }
    switch (h)
    {
    case 1:type = "���Ӳ�Ʒ"; break;
    case 2:type = "�߹�"; break;
    case 3:type = "��ʳ"; break;
    case 4:type = "��ױ"; break;
    case 5:type = "�ľ�"; break;
    case 6:type = "��װ"; break;
    }
    
    Product* t = first;
    Product* p = NULL;
    string str[100];
    int d = 0, f = 0;
   
    if (h == 7)
    {
        while (1)
        {
            cout << "\t\t\t\t    ɾ������Ʒ�����ƣ�";
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
                    cout << "\t\t\t\t    û�д���Ʒ,�Ƿ����������y/n��" << endl;
                    char ch;
                    ch = getchar();
                    if (ch == 'n' || ch == 'N') return;
                    else if (ch == 'Y' || ch == 'y') break;
                    else cout << "\t\t\t\t    �����������²�����" << endl;
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
            cout << "\n\t\t\t\t    ��ѡ��ɾ������Ʒ��"; cin >> d; d = d - 1;
            if (0 <= d && d < f)break;
            else cout << "\t\t\t\t    �����������²�����" << endl;
            
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
                
                cout << "\n\t\t\t\t    �ɹ�ɾ������Ʒ" << endl;
                delete t;
            }
            else
            {
                p->next = t->next;
                cout << "\n\t\t\t\t    �ɹ�ɾ������Ʒ" << endl;
                delete t;                                   
            }
            break;
        }
        p = t;
        t = t->next;
    }
   
    
    
    //��ɾ�������Ʒ��Ϣ�����ļ�
    ofstream outfile("����.dat", ios::out);
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