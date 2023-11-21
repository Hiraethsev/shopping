#include"Product.h"
#include<iomanip>


void Product_p::best_selling_list()
{

	system("cls");
	system("color F0");
	Product* t = first;
	Product* p = first;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if (t->next->sales_volume>t->sales_volume)
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  **                 ��Ʒ����                  **" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	cout << "\t\t\t\t     ���  " << "      ����" << "        ���� " << endl;
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	
	t = first;
	int i = 1;
	while (t)
	{
		if (t->sales_volume > 0)
		{
			cout << setiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(1);
			cout << "\t\t\t\t    " << setw(3) << i << "  " << setw(15) << t->product_name << "      "
				<< t->sales_volume << endl;
			cout << "\t\t\t\t  -----------------------------------------------" << endl;
		}
			
		
		if (t->next == NULL)
		{
			int h;
			while (1)
			{
				cout << "\t\t\t\t               1--�������˵�                   \n" << endl;
				cout << "\t\t\t\t               2--�˳�ϵͳ                     \n" << endl;
				cout << "\t\t\t\t               ��ѡ��";  cin >> h;
				
				if (h == 1 || h == 2) break;
				else  cout << "\t\t\t\t  �����������²���" << endl;
			}
			if (h == 1) break;
			else exit(1);
		}
		t = t->next;
		i++;
	}
}