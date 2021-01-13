#pragma once
#ifndef PRODUCTLIUJW_H_
#define PRODUCTLIUJW_H_
#include <string>
#include <time.h>
using namespace std;

//店铺商品信息 product.txt
//顾客购物记录在 customer.txt

char* getTime2();   //获取当前时间

class Product_Ljw
{
private:
	int serial;   //商品编号
	double in_price;  //进价
	double out_price;  //售价
	int stock;    //库存
	char provider[50];
	char time[64];  //时间
	int buy_num;  //购买的数量
	double sum;  //购买金额
public:
	char name[25];  //商品名字
	char type[20];  //商品种类
	void insert(const char*);  //插入商品记录（顾客或店铺）
	string display(double dis);   //菜单页面输出商品信息
	string display12(double dis);
	double total();   //计算单项商品总金额
	Product_Ljw();   
	void add_pro();
	void reset(double dis);   //初始化成员值
};
#endif // !PRODUCTLIUJW_H_

