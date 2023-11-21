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
		cout << "\t\t\t\t  **            超市商品管理系统               **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t  **             1.  管理员                    **" << endl;
		cout << "\t\t\t\t  **             2.  用户                      **" << endl;
		cout << "\t\t\t\t  **             3.  退出                      **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
		cout << "\t\t\t\t  请输入操作的序号：";  cin >> z;
		if (z == 1 || z == 2) break;
		else if (z == 3) exit(1);
		else   cout << "\t\t\t\t  操作错误，重新操作" << endl;
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
			cout << "\t\t\t\t  请输入管理员账号："; cin >> acc;
			if (acc == account)
			{
				while (1)
				{
					cout << endl;
					cout << "\t\t\t\t  请输入管理员密码："; cin >> d;
					if (d == pass)
					{
						system("cls");
						menu();
						break;
					}
					else cout << "\t\t\t\t  密码错误，请重新输入！" << endl;
				}
			}
			else cout << "\t\t\t\t  不存在该管理员，请重新输入！" << endl;
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
			cout << "\t\t\t\t  **              用户主菜单                   **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **             1.  查看商品                  **" << endl;
			cout << "\t\t\t\t  **             2.  搜索                      **" << endl;
			cout << "\t\t\t\t  **             3.  退出                      **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
			cout << "\t\t\t\t  请输入操作的序号：";  cin >> i;
			if (0 < i && i < 4) break;
			else cout << "操作错误，重新操作" << endl;
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
			cout << "\t\t\t\t  **              管理员主菜单                 **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **             1.  添加商品信息              **" << endl;
			cout << "\t\t\t\t  **             2.  删除商品                  **" << endl;
			cout << "\t\t\t\t  **             3.  修改商品信息              **" << endl;
			cout << "\t\t\t\t  **             4.  库存情况                  **" << endl;
			cout << "\t\t\t\t  **             5.  商品销量                  **" << endl;
			cout << "\t\t\t\t  **             6.  营收情况                  **" << endl;
			cout << "\t\t\t\t  **             7.  退出                      **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
			cout << "\t\t\t\t  请输入操作的序号：";  cin >> k;
			if (0 < k && k < 8) break;
			else cout << "操作错误，重新操作" << endl;
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
				  cout << "\t\t\t\t 是否继续添加（y/n）"; 
				  getchar();
				  q = getchar();
				  if (q == 'y' || q == 'n')break;
				  else cout << "\t\t\t\t操作错误，重新操作！" << endl;
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
					cout << "\t\t\t\t 是否继续删除（y/n）"; getchar(); q = getchar();
					if (q == 'y' || q == 'n')break;
					else cout << "\t\t\t\t操作错误，重新操作！" << endl;
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
				cout << "\t\t\t\t 是否继续修改（y/n）"; getchar(); q = getchar();
				if (q == 'y' || q == 'n')break;
				else cout << "\t\t\t\t操作错误，重新操作！" << endl;
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