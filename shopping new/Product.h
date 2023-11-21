
#include<iostream>
#include<string>
using namespace std;
 

class Product
{
	friend class Commoduty_p;                       
public:
	Product() {}
	Product(string, string, int, double, double,int, double = 0, 
		int = 0, int = 0,double =0,double =0,string ="0",int =0, int =0,string="0");  
	void swap();
	 


	string product_type;   //商品类型
	string product_name;   //商品名称
	int product_code;      //商品编号
	double buy_price;      //进货价
	double sell_price;     //售价
	int product_number;  //进货数量
	double comment;       //好评量
	int sales_volume;     //销售量
	int search_volume;    
	double S_T;         
	double G_T;          
	string shopping_car;  
	int shopping;         
	int order_number;     
	string order_number_1; 
	Product* next;
	
	
};


class Product_p
{
public:
	Product_p();
	void add();                
	void delet();               
	void revise();             
	void input_list();         
	void user_search();       
	void recommend();          
	void inventory();          
	void best_selling_list();     
	void money();              
protected:
	Product* first;          
	Product* last;          

};


