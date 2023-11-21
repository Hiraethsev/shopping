#include"Product.h"
#include<iomanip>
#include<fstream>
#include<cstdio>


void Product_p::recommend()
{
	Product* t = first;
	Product* p = first;

	t = first;
	while (t)
	{
		t->comment = t->sales_volume * 0.8;
		if (t->shopping_car == "0")
		{
			t->G_T = t->comment + double(t->search_volume) * 2;
		}
		else
		{
			t->G_T = t->comment + double(t->search_volume) * 2 + double(t->shopping) * 2;
		}
		t = t->next;
	}

	t = first;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if (t->next->G_T > t->G_T)
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}

	t = first;
	int o = 0;
	while (t)
	{
		t->order_number = o + 1;
		t->order_number_1 = to_string(o + 1);
		t = t->next;
		o++;
	}

	Product* u = first;
	Product* v = first;
	t = first;
	int i = 1;
	system("cls");
	
	int d = 0, j = 0, l = 0;
	string ch = "0", ge = "0";
	int min = 0, max = 0;
	int y = 0;
	int m = 0;
	while (t)
	{
		system("color F4");
		string dd;
		//y = 0;
		if (t->product_number - t->sales_volume > 0) dd = "有货";
		else dd = "无货";

		if ((i - 1) % 5 == 0)
		{
			max = min = i;
	
			cout << "\t\t\t\t **                                           **" << endl;
			cout << "\t\t\t\t **                 商品信息                  **" << endl;
			cout << "\t\t\t\t **                                           **" << endl;
	
		}
		if (i > max)max = i;

		if (i < min)min = i;
		cout << setiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(1);

		cout << " \t\t\t\t   ┌-----------------------------------------┐" << endl;
		cout << " \t\t\t\t   │" << "  NO." << setw(2) << i << "  " << setw(24) << t->product_name << "        │" << endl;
		cout << " \t\t\t\t   │-----------------------------------------│" << endl;
		cout << " \t\t\t\t   │" << "      ￥" << setw(6) << t->sell_price << "             "  << setw(5)<<t->sales_volume << "人付款"  << "   │" << endl;
		cout << " \t\t\t\t   │" << "       " << dd <<"                              │" << endl;
		cout << " \t\t\t\t   └-----------------------------------------┘" << endl;
		int q = 0;
		if ((i % 5 == 0 && t->next != NULL) || t->next == NULL)
		{
			while (1)
			{
				cout << "\t\t\t\t            如果购买请输入商品序号                   \n" << endl;
				cout << "\t\t\t\t               t--返回主菜单                   \n" << endl;
				cout << "\t\t\t\t           s--上一页   x--下一页                  \n" << endl;
				cout << "\t\t\t\t              请选择："; 
			
				if (ch == "0") { getchar(); getline(cin, ch); }
				else if (y == 1 || y == 2 || m == 1 || m == 2)
				{
					getchar();
					getline(cin, ch);
				}
				else if (m == 9)
				{
					getchar();
					getline(cin, ch);
				}
				else
				{

					getline(cin, ch);
				}

				//y = 0;
				if (ch == "s" || ch == "t" || ch == "x" || ch == "t" || min <= atoi(ch.c_str()) && atoi(ch.c_str()) <= max)
				{

					if (min <= atoi(ch.c_str()) && atoi(ch.c_str()) <= max)
					{
						ge = ch;
						ch = "1";
					

					}
					else
					{
						if (ch == "s") ch = "125";
						else if (ch == "t") ch = "160";
						else ch = "126";
						system("cls");
					}
					break;
				}
				else cout << "\n\t\t\t\t  操作错误！重新操作" << endl;


			}
			y = 0;

			switch (atoi(ch.c_str()))
			{

			case 125:
				if (i % 5 == 0)
				{
					if (i - 9 < 0)i = i - 4;
					else i = i - 9;
				}
				else
				{
					if (i < 5) i = 1;
					else
					{
						i = i - i % 5 - 4;
					}
				}
				v = first;
				while (v)
				{
					if (v->order_number == i)t = v;
					v = v->next;
				}
				break;
			case 126:break;
			case 1:
			{
				u = first;
				while (u)
				{
					if (u->order_number_1 == ge)
					{

						while (1)
						{
							cout << "\t\t\t\t  -----------------------------------------------" << endl;
							cout << "\t\t\t\t  **                                           **" << endl;
							cout << "\t\t\t\t  **              1.购买                       **" << endl;
							cout << "\t\t\t\t  **              2.加入购物车                 **" << endl;
							cout << "\t\t\t\t  **                                           **" << endl;
							cout << "\t\t\t\t  -----------------------------------------------" << endl;
							cout << "\t\t\t\t              请选择：";  cin >> y;
							 m = y;
							if (y == 1 || y == 2)break;
							else cout << "\t\t\t\t  操作错误！重新操作" << endl;
						}
						switch (y)
						{
						case 1:u->sales_volume = u->sales_volume + 1;  cout << "\n\t\t\t\t  下单成功！" << endl; break;
						case 2:u->shopping = u->shopping + 1; u->shopping_car = u->product_name;  cout << "\n\t\t\t\t  成功加入购物车" << endl; break;
						}

					}
					u = u->next;
				}
				break;
			}

			}
			if (ch == "125")continue;
			if (ch == "160")break;
		}
		if (y == 1 || y == 2)
		{
			y = 0;
			char h = '0';
			while (1)
			{
				cout << "\t\t\t\t  是否继续浏览（y/n）"; getchar(); h = getchar();
				if (h == 'y' || h == 'n') { system("cls"); break; }
				else cout << "\t\t\t\t  操作错误，重新操作！" << endl;
			}
			if (h == 'n')
				break;

		}
		t = t->next;
		i++;
	}

	//将修改后的商品信息读入文件
	ofstream outfile("数据.dat", ios::out);
	t = first;
	while (t)
	{
		outfile << t->product_type << " " << t->product_name << " " << t->product_code << " "
			<< t->buy_price << " " << t->sell_price << " " << t->product_number << " "
			<< t->comment << " " << t->sales_volume << " " << t->search_volume << " "
			<< t->S_T << " " << t->G_T << " " << t->shopping_car
			<< " " << t->shopping << " " << t->order_number << " " << t->order_number_1 << endl;
		t = t->next;
	}
	outfile.close();
}