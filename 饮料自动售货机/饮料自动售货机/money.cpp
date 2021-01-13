#include<iostream>
#include"currency.h"
using namespace std;

double Money::sale[5] = { 10,5,2,1,0.5 };
double Money::ss[5] = { 2,2,3,5,1.5 };
int Money::trade(int* s,int *r)
{
	double total = 0; 
	double total2 = 0;
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		if (r[i] > 0)
		{
			total2 += r[i]*sale[i];
		}
	}
	cout << "接收到的总计：" << total2<<endl;
	for (int i = 0; i < 5; i++)
	{
		if (s[i] > 0)
		{
			total += ss[i]*s[i];
		}
	}
	if (total2 < total)
	{
		cout << "应付款" << total << endl;
		cout << "还差" << total - total2 << endl<<"请再次输入零钱:"<<endl;
		for (int i = 0; i < 5; i++)
			cin >> a[i];
		cin.get();
		for (int i = 0; i < 5; i++)
		{
			if (s[i] > 0)
			{
				total2 += a[i]*sale[i];
			}
		}
		if (total2 < total)
		{
			cout << "交易失败！！！" << endl;
			return 0;
		}
	}
	cout << "交易成功！ \n退还零钱：" << endl << total2 - total<< endl;
	return 0;
}