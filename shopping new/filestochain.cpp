#include"Product.h"
#include<fstream>

//定义从文件到到链表的成员函数
void Product_p::input_list()
{
	string type, name, shop,ord;
	int code, number,sale,search,shop_p,order;
	double buy, sell, comme, S, G;

	ifstream infile("数据.dat");

	//判断文件是否有数据
	if (!infile)
	{
		cout << "\t\t没有数据，";
		exit(1);
	}

	//判断是否读到文件尾
	while (!infile.eof())
	{
		
		infile >> type >> name >> code >> buy
			>> sell >> number >> comme >> sale >> search >> S >> G >> shop >> shop_p >> order >> ord;

		Product* t = new Product(type, name, code, buy, sell, number, comme, sale,
			search, S, G, shop,shop_p, order,ord);    
		Product* p = first;

		int d = 0;
		//判断该商品信息是否已经输入
		while (p)
		{
			if ((p->product_name == t->product_name) && (p->product_code == t->product_code))
			{
				d = 1;
				break;
			}
			p = p->next;
		}

		//判断是否重复读入链表
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
