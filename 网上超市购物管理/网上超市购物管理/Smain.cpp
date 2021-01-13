#include<iostream>
#include<fstream>
#include<string>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ� 
using namespace std;
#include"Customer.h"
#define _CRT_SECURE_NO_WARNINGS
#include"ProductLiujw.h"
#include"Store.h"
template <class T> string m_toStr1(T tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}

template <class Type>
Type stringToNum(const string& str) {
	stringstream iss;
	iss << str;
	Type num=0;
	iss >> num;
	return num;
}
//����ʱ��ͳ��
int date_satic()
{
	cout << "����������Ҫ��ѯ����ݺ��·ݣ�" << endl;
	string year, month;
	cin >> year >> month;
	cin.get();
	string path= "statistics/" + year + "/" + month+".txt";
	ifstream fin(path);
	string lineData;
	//��ʼͳ����Ϣ
	double sum_dis=0;
	double sum_total=0;
	int i = 0;
	string a[4] = {"���аٻ�","��ˮ����","����ˮ��","ϴ���ջ�"}; string b[4]; double c[15] = { 0 }; double d[15] = { 0 };
	while (getline(fin,lineData))
	{
		int pos1 = lineData.find(' ',0);
		string st = lineData.substr(0, pos1); 
		int pos2 = lineData.find(' ', pos1 + 1);
		int num = stringToNum<int>(lineData.substr(pos1 + 1, pos2 - pos1 - 1));
		pos1 = lineData.find(' ', pos2+2);
		double total= stringToNum<double>(lineData.substr(pos2 + 2, pos1 - pos2 - 2));
		pos2 = lineData.find(' ', pos1+2);
		double disc = stringToNum<double>(lineData.substr(pos1 + 2, pos2 - pos1 - 2));
		pos1 = lineData.find(' ', pos2+2);
		string typee = lineData.substr(pos2 + 2, pos1 - pos2 - 2);
		for (i = 0; i < 4; i++)
		{
			if (m_toStr1(a[i]) == m_toStr1(typee))
			{
				b[i] += st + "  " + "������" +m_toStr1(num) + "  " + "�ܽ�" +m_toStr1( total) + "  �ۿۣ�" + m_toStr1(disc) + '\n';
			}
		}
		sum_dis += (1-disc)*total;
		sum_total += total;
	}
	cout << "\n\n" << endl;
	cout << "������� " << year << " �� " << month << " �� " << "��ͳ����Ϣ��" << endl;
	cout << "�����ܶ" << sum_total << endl<<endl;
	cout << "������Ʒͳ�ƣ�" << endl<<endl;
	for (i = 0; i < 4; i++)
	{
		cout << a[i] << endl << endl;
		cout << b[i] << endl<<endl;
	}
	fin.close();
	return 0;
}
void display_menue()
{
	ifstream fin("product.txt");
	string line;
	while (getline(fin, line))
	{
		cout << line << endl;
	}
}
void display_option()
{
	for (int i = 0; i < 70; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "1����������Ʒ��" << endl;
	cout << "2�����鿴�˵���" << endl;
	cout << "********************************************" << endl;
	cout << "3������Ʒ����" << endl;
	cout << "4������Ա����" << endl;
	cout << "5����ͳ��" << endl;
	cout << "6�����˳�" << endl;
}
int main()
{
	while (true) {
		display_option();  //չʾ ѡ��
		char ch;
		cout << "������ ���룺" << endl;
		cin >> ch; cin.get();
		switch (ch)
		{
		case '1':cout << "���Ƿ��ǻ�Ա����P�����߼���Ա��O������ͨ��Ա��N������ͨ�˿ͣ�" << endl;
			cin >> ch; cin.get();
			if (ch == 'N' || ch == 'n')
			{
				char ch1;
				CustomerLjw ord;
				ord.display1();
				string shopping_list,shopping_list11;
				string shopping_list2, shopping_list21;
				string shopping_list3, shopping_list31;
				display_menue();
				Product_Ljw pro;
				cout << "���Ƿ�ʼ������Ʒ����Y/N��" << endl; 
				cin >> ch1;
				while (ch1=='Y'||ch1=='y') {
					pro.reset(1);
					shopping_list += pro.display(1);
					shopping_list11 += pro.display12(1);
					shopping_list2 += pro.display(0.98);
					shopping_list21 += pro.display12(0.98);
					shopping_list3 += pro.display(0.95);
					shopping_list31 += pro.display12(0.95);
					ord.costs += pro.total();
					cout << "���Ƿ����������Ʒ����Y/N��" << endl;
					cin >> ch1; cin.get();
				}
				ord.display2();
				//ord.upgrade(stringToNum<char*>(shopping_list), stringToNum<char*>(shopping_list2), stringToNum<char*>(shopping_list3));
				ord.upgrade(shopping_list, shopping_list2, shopping_list3, shopping_list11, shopping_list21, shopping_list31);
			}
			else if (ch == 'O' || ch == 'o')
			{
				cout << "����������������" << endl;
				string name;
				cin >> name; cin.get();
				ofstream fout("customer/" + name+".txt");
				char ch1;
				cout << "���Ƿ�ʼ������Ʒ����Y/N��" << endl;
				cin >> ch1;
				General_MemeberLjw ord;
				strcpy_s(ord.name, 21, name.data());
				ord.display3();
				string shopping_list,shopping_list12;
				string shopping_list2,shopping_list22;
				display_menue();
				Product_Ljw pro;
				while (ch1=='y'||ch1=='Y') {
					pro.reset(0.98);
					shopping_list += pro.display(0.98);
					shopping_list2 += pro.display(0.95);
					shopping_list12 += pro.display12(0.98);
					shopping_list22 += pro.display12(0.95);
					ord.costs += pro.total();
					fout << pro.display(0.98);
					cout << "���Ƿ�ʼ������Ʒ����Y/N��" << endl;
					cin >> ch1; cin.get();
				}
				/*ofstream ffout("CUS/" + name + ".txt", ios_base::app || ios_base::out);
				ffout << shopping_list << endl;
				ffout.close();*/
				ord.display4();
				ord.upgrade(shopping_list, shopping_list2,shopping_list12,shopping_list22);
				ord.display4();
			}
			else if (ch == 'P' || ch == 'p')
			{
				cout << "����������������" << endl;
				string name;
				cin >> name; cin.get();
				ofstream fout("customer/" + name);
				char ch1;
				cout << "���Ƿ�ʼ������Ʒ����Y/N��" << endl;
				cin >> ch1; cin.get();
				Senior_MemberLjw ord;
				ord.display5();
				string shopping_list;
				display_menue();
				Product_Ljw pro;
				while (ch1=='y'||ch1=='Y') {
					pro.reset(0.95);
					shopping_list += pro.display(0.95);
					ord.costs += pro.total();
					fout << pro.display(0.95);
					cout << "���Ƿ�ʼ������Ʒ����Y/N��" << endl;
					cin >> ch1; cin.get();
				}
				ord.display6();
			}
			break;
		case '2': {cout << "����������Ҫ�鿴�˵��� �˿�������" << endl;
			string na1; cin >> na1; cin.get();
			cout << "���潫Ҫ��ʾ" << na1 << " ��һ��Ĺ����¼��" << endl;
			ifstream fin1{ "customer/" + na1 };
			string line1;
			while (getline(fin1, line1))
			{
				cout << line1 << endl;
			}
			fin1.close();
			break; }
		case '3': {cout << "���������Ʒ�������" << endl;
			Store SS;
			cout << "����������Ҫ���Ĺ��ܱ�ţ�1������ӣ�2�����޸ģ�3����ɾ����4������ѯ,5������治����Ʒ����" << endl;
			char c;
			cin >> c; cin.get();
			switch (c)
			{
			case '1':SS.add_product(); break;
			case '2':SS.modify_product(); break;
			case '3':SS.del_product(); break;
			case '4':SS.check_product(); break;
			case '5':cout << "��������Ҫ��ѯ�������ڶ��ٵ���Ʒ��" << endl;
				int bbc; cin >> bbc; cin.get();
				SS.check_num_product(bbc); break;
			}
			break; }
		case '4':cout << "��������Ա������棺" << endl;
			Store SS;
			cout << "����������Ҫ���Ĺ��ܱ�ţ�1������ѯ��2�����޸ģ�3����ɾ��,4������Ա������" << endl;
			char d;
			cin >> d; cin.get();
			switch (d)
			{
			case '1':SS.check_name(); break;
			case '2':SS.modify_name(); break;
			case '3':SS.del_name(); break;
			case '4':SS.delete_info();
				SS.del_no_buy();
				break;
			}
			break;
		case '5':cout << "������ʾͳ�����ݣ�" << endl;
			date_satic(); break;
		case '6':cout << "�˻ص����˵�������" << endl;
			break;
		default:cout << "�����ַ��޷�ƥ�䣬���������룡����" << endl;
			break;
		}
	}
}