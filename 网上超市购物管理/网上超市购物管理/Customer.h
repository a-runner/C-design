#pragma once
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include<string>
using namespace std;
class CustomerLjw
{
public:
	int serial=1;
	double costs=0;
	char time_T[64];
	void upgrade(string shopp,string shopp2,string shopp3,string shopp4,string shopp5,string shopp6);   //升级普通会员
	void display1();
	void display2();
	string ID;
	CustomerLjw();
};
class General_MemeberLjw:public CustomerLjw
{
	double total_money;
	char number[16];
	double dis = 0.98;
public:
	char name[20]{};
	int serial = 2;
	int points;
	void upgrade(string shopp, string shopp2,string shopp3,string shopp4);  //升级高级会员
	void display3();
	void display4();
};
class Senior_MemberLjw :public General_MemeberLjw
{
	double dis = 0.95;
public:
	int serial = 3;
	void display5();
	void display6();
	string sec_ID;
};
#endif // !CUSTOMER_H_