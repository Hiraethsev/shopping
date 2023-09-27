#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#include<iomanip>
#include<fstream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1


typedef int Status;// Status是函数的类型,其值是函数结果状态代码，如OK等


struct dating
{
  int year;
  int month;
  int day;  
};




struct SupermarketProduct
{
    char name[30];
    char number[10];
    float openprice;//进价
    float sellprice;//售价
    int amount;
    dating date;

SupermarketProduct *next;

};

typedef SupermarketProduct *GoodsList;

