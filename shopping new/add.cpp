
#include"Product.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//定义添加商品信息的成员函数
void Product_p::add()
{
	system("cls");
	string type, name;
	int code, number;
	double buy, sell;
	cout << endl << endl;
	
	cout << "\t\t\t\t                 添加商品信息                  " << endl;
	cout << endl << endl;
	int h;
	while (1)
	{
		
		cout << "\t\t\t\t  -----------------------------------------------" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t  **             添加的商品类型：              **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t  **             1.  电子产品                  **" << endl;
		cout << "\t\t\t\t  **             2.  蔬果                      **" << endl;
		cout << "\t\t\t\t  **             3.  零食                      **" << endl;
		cout << "\t\t\t\t  **             4.  美妆                      **" << endl;
		cout << "\t\t\t\t  **             5.  文具                      **" << endl;
		cout << "\t\t\t\t  **             6.  服装                      **" << endl;
		cout << "\t\t\t\t  **                                           **" << endl;
		cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
		cout << "\t\t\t\t 请选择：";  cin >> h;

		if (0 < h && h < 7) break;
		else
		{
			system("cls");
			cout << "\t\t\t\t               输入错误,请重新输入                  \n" << endl;
		}
	}
	switch (h)
	{
	case 1:type = "电子产品"; break;
	case 2:type = "蔬果"; break;
	case 3:type = "零食"; break;
	case 4:type = "美妆"; break;
	case 5:type = "文具"; break;
	case 6:type = "服装"; break;
	}

	cout << "\t\t\t\t 商品名称：";
	getchar(); 
	getline(cin, name);

	while (1)
	{
		cout << "\t\t\t\t 商品编号："; cin >> code;
		if (code > 0)break;
	}
	
	while (1)
	{
		cout << "\t\t\t\t 进货价："; cin >> buy;
		if (buy > 0)
			break;
		else cout << "\t\t\t\t输入错误" << endl;
	}
	
	while (1)
	{
		cout << "\t\t\t\t 售价："; cin >> sell;
		if (sell > 0)break;
		else cout << "\t\t\t\t 输入错误" << endl;
	}
	while (1)
	{
		cout << "\t\t\t\t 商品的数量："; cin >> number;
		if (sell > 0) break;
		else cout << " \t\t\t\t输入错误" << endl;
	}

	Product* t = new Product(type, name, code, buy, sell, number);   
	Product* p = first;

	//判断该商品是否已经输入
	while (p)
	{
		if ((p->product_name== t->product_name) && (p->product_code== t->product_code))
		{
			
			cout <<"\t\t\t\t\t\t\t"<< p->product_name << "的信息已录入" << endl;
			return;
		}
		p = p->next;
	}

	//将商品信息读入文件
	ofstream outfile("数据.dat", ios::app);
	outfile << t->product_type << " " << t->product_name << " " << t->product_code << " "
		<< t->buy_price << " " << t->sell_price << " " << t->product_number << " "
		<< t->comment << " " << t->sales_volume << " " << t->search_volume << " "
		<< t->S_T << " " << t->G_T << " " << t->shopping_car 
		<< " " << t->shopping << " " << t->order_number << " " << t->order_number_1 << endl;
	
	outfile.close();

	//读入链表
	if (first == NULL)
	{
		first = last = t;
		cout << "\t\t\t\t                   添加成功                  \n" << endl;
	}
	else
	{
		last->next = t;
		last = last->next;
		cout << "\t\t\t\t                   添加成功                  \n" << endl;
	}

}
