#include<iostream>
#include<string>
#include<cstring>
#include <time.h>
#include<fstream>
#include <sstream>
#include"operate.h"
#include"User.h"
#include"books.h"
using namespace std;

void star()
{
	for (int i = 0; i < 50; i++)
		cout << '*';
	cout << endl;
}
template <class Type>
Type stringToNum(const string& str) {
	stringstream iss;
	iss << str;
	Type num = 0;
	iss >> num;
	return num;
}
int checkData(const char* fileName, char* content)
{
	ifstream in;
	in.open(fileName);
	int k, i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		k = tempStr.find(content);
		i++;
		if (k != -1)
		{
			return i;
		}
	}
	in.close();
	return 0;
}
void display1()
{
	star();
	cout << "������ϵͳ�ĵ�½״̬��" << endl;
	cout << "��ӭ���� ѧУͼ�����ϵͳ������" << endl;
}

int main()
{
	string ID, pass; OpLjw op; Books book;
	while (1)
	{	
		display1();
		//��ʦ ͼ�����Ա ϵͳ����Ա����Ϣ������teacher.txt�ı��ļ���
		cout << "��������ߵ���ݣ���1��ѧ����2����ʦ, 3��ͼ�����Ա��4��ϵͳ����Ա��" << endl;
		char cc; cin >> cc; cin.get(); int n = 0;
		if (cc == '1')
			n = 1;
		else if (cc == '2')
			n = 2;
		else if (cc == '3')
			n = 3;
		else if (cc == '4')
			n = 4;
		//ReaderLjw reader(n);
		op.log_in(n);
		//case '2':cout << "������Ҫ���еĲ�����1�����ӣ�2���޸ģ�3����ѯ��4��ͳ�ƣ���" << endl;
		//	char cc; cin >> cc; cin.get();
		//	switch (cc)
		//	{
		//	case '1':cin >> book; break;//book.add_books(); break;
		//	case '2':book.modify_books(); break;
		//	case '3':book.check_info(); break;
		//	case '4':book.ststistic(); break;
		//	}
		//	 break;
		//case '3':cout<<"������Ҫ���еĲ�����1���û����ӣ�2���û�ɾ����3��Ȩ�޹�����"<<endl;
		//	char cc; cin >> cc; cin.get();
		//	switch (cc)
		//	{
		//	case '1':op.add_user(); break;
		//	case '2':break;
		//	case '3':break;
		//	}
		//	break;
		//}
	}
	return 0;
}