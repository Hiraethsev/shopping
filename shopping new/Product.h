
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
	 


	string product_type;   //��Ʒ����
	string product_name;   //��Ʒ����
	int product_code;      //��Ʒ���
	double buy_price;      //������
	double sell_price;     //�ۼ�
	int product_number;  //��������
	double comment;       //������
	int sales_volume;     //������
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


