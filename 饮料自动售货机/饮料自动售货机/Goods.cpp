#include<iostream>
#include"commodity.h"
using namespace std;

int Goods::amount[5] = { 10,10,10,10,10 };
int* Goods::sell(int* s)
{
	int mt[5] = { 0,0,0,0,0 };
	cout << "���ڳ��������Եȡ�����" << endl;   //��ʾ��Ϣ
	for (int i = 0; i < 5; i++)
	{
		if (s[i] > 0)
		{
			if (amount[i] < s[i])
			{
				begin:
				cout << "����Ҫ���"<<gd[i]<<"�������㣬�Ƿ���Ҫ�����������ϣ���Y/N��" << endl;
				cin.get(ch);
				if (ch=='Y'||ch=='y')
				{
					cout << "���������滻�����ϱ�ţ�1-coca, 2-pepsi, 3-juice, 4-coffee, 5-water����������" << endl;
					int a, b;
					cin >> a >> b;
					if (b > amount[a])
						goto begin;
					cin.get();
					cout << endl;
					cout << "�������滻Ϊ: " << b << '-' << gd[a] << endl;
					amount[a] -= b;
					mt[a] += b;
					continue;
				}
				else {
					cout << "����" << gd[i];
					continue;
				}
				
			}
			mt[i] += s[i];
			amount[i] -= s[i];
			cout <<"����: "<< s[i] << " * " << gd[i] << endl;
		}
	}
	return mt;
}

Goods::Goods()
{
}