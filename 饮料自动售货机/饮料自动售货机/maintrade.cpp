#include<iostream>
#include"commodity.h"
#include"currency.h"

using namespace std;

int main()
{
	while (true) {
		cout << "��ӭ���� �Զ��ջ�����" << endl;
		int s[5];
		cout << "������ �������Ҫ��������ϱ�ţ�1-coca, 2-pepsi, 3-juice, 4-coffee, 5-water������������" << endl;
		for (int i = 0; i < 5; i++)
		{
			cin >> s[i];
		}
		cin.get();
		Goods sa;
		int* q = sa.sell(s);
		cout << "�밴����ֵ�����ӦǮ������1-10��2-5��3-2��4-1��5-0.5����" << endl;
		int mo[5];
		for (int i = 0; i < 5; i++)
		{
			cin >> mo[i];
		}
		cin.get();
		Money M;
		M.trade(s, mo);
		cout << endl << endl << endl;
		for (int i = 0; i < 70; i++)
			cout << '*';
		cout << endl;
	}
	return 0;
}