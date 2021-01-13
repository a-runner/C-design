#pragma once
#ifndef COMMODITY_H_
#define COMMODITY_H_
#include<cstring>
#include<iostream>
//定义商品类
class Goods
{
public:
	int* sell(int *);
	Goods();
private:
	static int amount[5];  //定义各种饮料的数量
	int sale[5];
	char ch;
	const char gd[5][8]= { "coca", "pepsi", "juice", "coffee", "water" };
};
#endif