#include "Product.h"


void user_menu()
{
	int i = 0;
	Product_p p;

	while (1)
	{
		
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
		case 3:exit(1); break;
		}
	}

}