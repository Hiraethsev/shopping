#include"Product.h"
#include<fstream>
#include<iomanip>


void Product_p::user_search()
{
	system("color F0");
	system("cls");
	int h = 0;
	cout << endl << endl << endl << endl ;
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  **                   搜索                    **" << endl;
	cout << "\t\t\t\t  **                                           **" << endl;
	cout << "\t\t\t\t  -----------------------------------------------" << endl;
	
	while (1)
	{
		cout << "\t\t\t\t               1.根据商品名称搜索：                   \n" << endl;
		cout << "\t\t\t\t               2.根据商品类型搜索：                    \n" << endl;
		cout << "\t\t\t\t               请选择搜索类型：";  cin >> h;

		if (h == 1 || h == 2) break;
		else cout << "\t\t\t\t  操作错误！重新操作" << endl;
	}
	int w = 0;
	Product* t = first;
	if (h == 1)
	{
		while (1)
		{
			string str;
			while (1)
			{

				cout << "\n\t\t\t\t  请输入商品名称："; getchar(); getline(cin, str);
				int f = 0;
				t = first;
				while (t)
				{
					if (t->product_name == str)
					{
						t->search_volume = t->search_volume + 1;
						f = 1;
						break;
					}
					t = t->next;
				}
				char ch;
				if (f == 1) break;
				else
				{
					while (1)
					{
						cout << "\t\t\t\t  没有此商品，是否还搜索？（y/n）"; ch = getchar();
						if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N') break;
						else cout << "\t\t\t\t  操作错误！重新操作" << endl;
					}
				}
				if (ch == 'n' || ch == 'N') return;
			}
			t = first;

			while (t)
			{
				if (t->product_name == str)
				{
					int i = 1;
					system("color F0");
					string dd;
					if (t->product_number - t->sales_volume > 0) dd = "有货";
					else dd = "无货";
					cout << setiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(1);
					cout << " \t\t\t\t   ┌-----------------------------------------┐" << endl;
					cout << " \t\t\t\t   │" << "  NO." << setw(2) << i << "  " << setw(24) << t->product_name << "        │" << endl;
					cout << " \t\t\t\t   │-----------------------------------------│" << endl;
					
					cout << " \t\t\t\t   │" << "      ￥" << setw(6) << t->sell_price << "             " << setw(5) << t->sales_volume << "人付款" << "   │" << endl;
					cout << " \t\t\t\t   └-----------------------------------------┘" << endl;
				}
				t = t->next;
			}

			char gg='0';
			while (1)
			{
				cout << "\t\t\t\t 是否还搜索？（y/n）"; gg = getchar();
				if (gg == 'y' || gg == 'Y' || gg == 'n' || gg == 'N') break;
				else cout << "\t\t\t\t 操作错误！重新操作" << endl;
			}
			if (gg == 'N' || gg == 'n')break;
			
		}
		
		
	}
	else
	{
		string type;
		int h = 0;
		while (1)
		{
			cout << "\t\t\t\t  -----------------------------------------------" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **              商品类型：                   **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t  **             1.  电子产品                  **" << endl;
			cout << "\t\t\t\t  **             2.  蔬果                      **" << endl;
			cout << "\t\t\t\t  **             3.  零食                      **" << endl;
			cout << "\t\t\t\t  **             4.  美妆                      **" << endl;
			cout << "\t\t\t\t  **             5.  文具                      **" << endl;
			cout << "\t\t\t\t  **             6.  服装                      **" << endl;
			cout << "\t\t\t\t  **                                           **" << endl;
			cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
			cout << "\n\t\t\t\t 请选择搜索类型："; cin >> h;
			if (0 < h && h < 7)  break;
			else cout << "\t\t\t\t               输入错误                  \n" << endl;
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
		Product* t = first;
		while (t)
		{
			if (t->product_type == type)
			{
				if (t->shopping_car == "0")
				{
					t->S_T = t->sales_volume * 1 + t->comment * 3 + double(t->search_volume) * 2;
				}
				else
				{
					t->S_T = t->sales_volume * 1 + t->comment * 3 + double(t->search_volume) * 2 + 3 * double(t->shopping);
				}
				t->comment = t->sales_volume * 0.8;
		    }
			
			t = t->next;
		}
		t = first;
		Product* p = first;

		while (p->next)
		{
			t = first;
			while (t->next)
			{
				if (t->next->S_T > t->S_T)
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
		w = 1;
		system("cls");
		
		int d = 0, j = 0, l = 0;
		string ch = "0", ge = "0";
		int min = 0, max = 0;
		int y = 0;
		while (t)
		{
			system("color F4");
			string dd;

			if (t->product_number - t->sales_volume > 0) dd = "有货";
			else dd = "无货";
			if ((w-1)% 5 == 0)
			{
				
				max = min = w;
			}
			if (w > max)max = w;

			if (w < min)min = w;
			if (t->product_type == type)
			{
				if ((w - 1) % 5 == 0) cout << "\n\t\t\t\t  <<===============搜索结果===================>>\n" << endl;
				cout << setiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(1);
				cout << " \t\t\t\t   ┌-----------------------------------------┐" << endl;
				cout << " \t\t\t\t   │" << "  NO." << setw(2) << i << "  " << setw(24) << t->product_name << "        │" << endl;
				cout << " \t\t\t\t   │-----------------------------------------│" << endl;
				cout << " \t\t\t\t   │" << "      ￥" << setw(6) << t->sell_price << "             " << setw(5) << t->sales_volume << "人付款" << "   │" << endl;
				cout << " \t\t\t\t   └-----------------------------------------┘" << endl;
				w++;
			}
			
			int q = 0;
			//y = 0;
			if ((i % 5 == 0 && t->next != NULL) || t->next == NULL)
			{
				while (1)
				{

					cout << "\t\t\t\t            如果购买请输入商品序号                   \n" << endl;
					cout << "\t\t\t\t               t--返回主菜单                   \n" << endl;
					cout << "\t\t\t\t           s--上一页   x--下一页                  \n" << endl;
					cout << "\t\t\t\t              请选择：";

		
					if (ch == "0") {getchar(); getline(cin, ch); }
					else if (y == 1 || y == 2)
					{
						getchar(); getline(cin, ch);
						
					}
					else if (ch == "125" || ch == "126" || ch == "129") 
					{ getline(cin, ch); }
					else 
					{
						getchar();getline(cin, ch);
					}

					if (ch=="t"||ch == "s" || ch == "x" || min <= atoi(ch.c_str()) && atoi(ch.c_str()) <= max)
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
					else { ch = "129"; cout << "\n\t\t\t\t  操作错误！重新操作" << endl;
					}

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
								cout << "\t\t\t\t              请选择：";
								cin >> y;
								if (y == 1 || y == 2)break;
								else { cout << "\n\t\t\t\t  操作错误！重新操作" << endl; }
							}
							switch (y)
							{
							case 1:u->sales_volume = u->sales_volume + 1; cout << "\n\t\t\t\t 下单成功！" << endl; break;
							case 2:u->shopping = u->shopping + 1; u->shopping_car = u->product_name; cout << "\n\t\t\t\t 成功加入购物车" << endl; break;
							}

						}
						u = u->next;
					}
					break;
				}

				}
				if (ch == "125")continue;
				if (ch == "160") break;

			}
			if (y == 1 || y == 2)
			{
				y = 0;
				char h = '0';
				while (1)
				{
					cout << "\t\t\t\t  是否继续浏览（y/n）";
					
					getchar(); h = getchar();
					if (h == 'y' || h == 'n') { system("cls"); break; }
					else cout << "\t\t\t\t  操作错误，重新操作！" << endl;
				}
				if (h == 'n')
					break;

			}
			t = t->next;
			i = w;
		}

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