#pragma once
#ifndef COMMODITY_H_
#define COMMODITY_H_
#include<cstring>
#include<iostream>
//������Ʒ��
class Goods
{
public:
	int* sell(int *);
	Goods();
private:
	static int amount[5];  //����������ϵ�����
	int sale[5];
	char ch;
	const char gd[5][8]= { "coca", "pepsi", "juice", "coffee", "water" };
};
#endif