#include<iostream>
#include"commodity.h"
using namespace std;

int Goods::amount[5] = { 10,10,10,10,10 };
int* Goods::sell(int* s)
{
	int mt[5] = { 0,0,0,0,0 };
	cout << "正在出货，请稍等。。。" << endl;   //提示信息
	for (int i = 0; i < 5; i++)
	{
		if (s[i] > 0)
		{
			if (amount[i] < s[i])
			{
				begin:
				cout << "您想要买的"<<gd[i]<<"数量不足，是否需要购买其他饮料？（Y/N）" << endl;
				cin.get(ch);
				if (ch=='Y'||ch=='y')
				{
					cout << "请输入想替换的饮料编号（1-coca, 2-pepsi, 3-juice, 4-coffee, 5-water）和数量：" << endl;
					int a, b;
					cin >> a >> b;
					if (b > amount[a])
						goto begin;
					cin.get();
					cout << endl;
					cout << "您，已替换为: " << b << '-' << gd[a] << endl;
					amount[a] -= b;
					mt[a] += b;
					continue;
				}
				else {
					cout << "跳过" << gd[i];
					continue;
				}
				
			}
			mt[i] += s[i];
			amount[i] -= s[i];
			cout <<"出货: "<< s[i] << " * " << gd[i] << endl;
		}
	}
	return mt;
}

Goods::Goods()
{
}