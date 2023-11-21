#include"Product.h"
#include<fstream>

//������ļ���������ĳ�Ա����
void Product_p::input_list()
{
	string type, name, shop,ord;
	int code, number,sale,search,shop_p,order;
	double buy, sell, comme, S, G;

	ifstream infile("����.dat");

	//�ж��ļ��Ƿ�������
	if (!infile)
	{
		cout << "\t\tû�����ݣ�";
		exit(1);
	}

	//�ж��Ƿ�����ļ�β
	while (!infile.eof())
	{
		
		infile >> type >> name >> code >> buy
			>> sell >> number >> comme >> sale >> search >> S >> G >> shop >> shop_p >> order >> ord;

		Product* t = new Product(type, name, code, buy, sell, number, comme, sale,
			search, S, G, shop,shop_p, order,ord);    
		Product* p = first;

		int d = 0;
		//�жϸ���Ʒ��Ϣ�Ƿ��Ѿ�����
		while (p)
		{
			if ((p->product_name == t->product_name) && (p->product_code == t->product_code))
			{
				d = 1;
				break;
			}
			p = p->next;
		}

		//�ж��Ƿ��ظ���������
		if (d == 0)
		{
			if (first == NULL)
			{
				first = last = t;
			}
			else
			{
				last->next = t;
				last = last->next;
			}
		}
	}
}
