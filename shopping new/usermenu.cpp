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
		case 3:exit(1); break;
		}
	}

}