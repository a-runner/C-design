#pragma once
#ifndef CURRENCY_H_
#define CURRENCY_H_
class Money
{
public:
	int trade(int* s,int* r);
private:
	double receive;    //�յ���Ǯ��
	double re;    //���ص���Ǯ��Ŀ
	static double sale[5];
	static double ss[5];
};
#endif // !CURRENCY_H_

