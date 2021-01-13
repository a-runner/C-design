#pragma once
#ifndef CURRENCY_H_
#define CURRENCY_H_
class Money
{
public:
	int trade(int* s,int* r);
private:
	double receive;    //收到的钱数
	double re;    //返回的零钱数目
	static double sale[5];
	static double ss[5];
};
#endif // !CURRENCY_H_

