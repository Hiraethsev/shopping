  #include"Product.h"
#include<iostream>
#include<string>

using namespace std;

void menu();
void user_menu_u();
void mainmenu();

int main()
{
	mainmenu();
	return 0;
}

void mainmenu()
{
	const string account = "ccnu";
	const string pass="077";
	
	int z = 0;
	while (1)
	{
		system("color F0");
		cout << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t  -----------------------------------------------" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t  **            ������Ʒ����ϵͳ               **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t  **             1.  ����Ա                    **" << endl;
		cout << "\t\t\t\t  **             2.  �û�                      **" << endl;
		cout << "\t\t\t\t  **             3.  �˳�                      **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
		cout << "\t\t\t\t  �������������ţ�";  cin >> z;
		if (z == 1 || z == 2) break;
		else if (z == 3) exit(1);
		else   cout << "\t\t\t\t  �����������²���" << endl;
	}
	switch (z)
	{
	case 1:
	{
		string acc = "";
		string d = "";
		while (1)
		{
			cout << endl;
			cout << "\t\t\t\t  ���������Ա�˺ţ�"; cin >> acc;
			if (acc == account)
			{
				while (1)
				{
					cout << endl;
					cout << "\t\t\t\t  ���������Ա���룺"; cin >> d;
					if (d == pass)
					{
						system("cls");
						menu();
						break;
					}
					else cout << "\t\t\t\t  ����������������룡" << endl;
				}
			}
			else cout << "\t\t\t\t  �����ڸù���Ա�����������룡" << endl;
		}
		
		
		break;
	}
	case 2: system("cls"); user_menu_u(); break;
	}
}

void user_menu_u()
{
	Product_p p;

	p.input_list();
	while (1)
	{
		int i = 0;
		while (1)
		{
			system("color F0");
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t  -----------------------------------------------" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **              �û����˵�                   **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **             1.  �鿴��Ʒ                  **" << endl;
			cout << "\t\t\t\t  **             2.  ����                      **" << endl;
			cout << "\t\t\t\t  **             3.  �˳�                      **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
			cout << "\t\t\t\t  �������������ţ�";  cin >> i;
			if (0 < i && i < 4) break;
			else cout << "�����������²���" << endl;
		}
		switch (i)
		{
		case 1:p.recommend(); break;
		case 2:p.user_search(); break;
		case 3:system("cls");  mainmenu(); break;
		}
	}
	
}
void menu()
{
	Product_p p;
	p.input_list();
	while (1)
	{
		int k = 0;
		while(1){
			system("color F0");
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t  -----------------------------------------------" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **              ����Ա���˵�                 **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **             1.  �����Ʒ��Ϣ              **" << endl;
			cout << "\t\t\t\t  **             2.  ɾ����Ʒ                  **" << endl;
			cout << "\t\t\t\t  **             3.  �޸���Ʒ��Ϣ              **" << endl;
			cout << "\t\t\t\t  **             4.  ������                  **" << endl;
			cout << "\t\t\t\t  **             5.  ��Ʒ����                  **" << endl;
			cout << "\t\t\t\t  **             6.  Ӫ�����                  **" << endl;
			cout << "\t\t\t\t  **             7.  �˳�                      **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
			cout << "\t\t\t\t  �������������ţ�";  cin >> k;
			if (0 < k && k < 8) break;
			else cout << "�����������²���" << endl;
		}
		switch (k)
		{
		case 1:
		{
			char q = '0';
			while (1)
		    {
			  system("cls");
			  p.add();
			  while (1)
			  {
				  cout << "\t\t\t\t �Ƿ������ӣ�y/n��"; 
				  getchar();
				  q = getchar();
				  if (q == 'y' || q == 'n')break;
				  else cout << "\t\t\t\t�����������²�����" << endl;
			  }
			  if (q == 'n') break;
		    }
			
			break;
		}
		case 2:
		{
			char q = '0';
			while (1)
			{
				p.delet();
				while (1)
				{
					cout << "\t\t\t\t �Ƿ����ɾ����y/n��"; getchar(); q = getchar();
					if (q == 'y' || q == 'n')break;
					else cout << "\t\t\t\t�����������²�����" << endl;
				}
				if (q == 'n') break;
			}

			break; 
		}
			 
		case 3:
		{
			char q = '0';
		while (1)
		{
			p.revise();
			while (1)
			{
				cout << "\t\t\t\t �Ƿ�����޸ģ�y/n��"; getchar(); q = getchar();
				if (q == 'y' || q == 'n')break;
				else cout << "\t\t\t\t�����������²�����" << endl;
			}
			if (q == 'n') break;
		}

		break; }
			 break;
		case 4:p.inventory(); break;
		case 5:p.best_selling_list(); break;
		case 6:system("cls"); p.money(); break;
		case 7:system("cls"); mainmenu(); break;
		}
		
	}
}