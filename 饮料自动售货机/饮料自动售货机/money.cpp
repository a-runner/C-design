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
	cout << "���յ����ܼƣ�" << total2<<endl;
	for (int i = 0; i < 5; i++)
	{
		if (s[i] > 0)
		{
			total += ss[i]*s[i];
		}
	}
	if (total2 < total)
	{
		cout << "Ӧ����" << total << endl;
		cout << "����" << total - total2 << endl<<"���ٴ�������Ǯ:"<<endl;
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
			cout << "����ʧ�ܣ�����" << endl;
			return 0;
		}
	}
	cout << "���׳ɹ��� \n�˻���Ǯ��" << endl << total2 - total<< endl;
	return 0;
}