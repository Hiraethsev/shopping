#include"Product.h"
#include<iomanip>
#include<fstream>
#include<cstdio>

//����Ӫ������ĳ�Ա����
void Product_p::money()
{
	system("color F0");
	Product* t = first;
	double Money1 = 0, Money2 = 0;
	while (t)
	{
		Money1 = Money1 + t->sell_price;
		Money2 += t->buy_price;
		t = t->next;
	}

	cout << "\t\t\t\t                  Ӫ�����                  " << endl;
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  **        Ԥ��Ӫҵ�"<< setw(3)<<Money1 << "Ԫ              **" << endl;
	cout << "\t\t\t\t  **        Ԥ������" << setw(3) << Money1 - Money2 << "Ԫ                 **" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t ------------------------------------------------" << endl << endl;

	int h;
	while (1)
	{
		cout << endl;
		cout << "\t\t\t\t               1--�������˵�                   \n" << endl;
		cout << "\t\t\t\t               2--�˳�ϵͳ                     \n" << endl;
		cout << "\t\t\t\t               ��ѡ��";
		 cin >> h;
		if (h == 1 || h == 2) break;
		else cout << "\t\t\t\t  �����������²���" << endl;
	}
	if (h == 2) exit(1);
}