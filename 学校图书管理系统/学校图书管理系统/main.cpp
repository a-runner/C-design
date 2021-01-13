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
	cout << "正处于系统的登陆状态：" << endl;
	cout << "欢迎进入 学校图书管理系统！！！" << endl;
}

int main()
{
	string ID, pass; OpLjw op; Books book;
	while (1)
	{	
		display1();
		//老师 图书管理员 系统管理员的信息都放在teacher.txt文本文件中
		cout << "请输入读者的身份：（1—学生，2—老师, 3—图书管理员，4—系统管理员）" << endl;
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
		//case '2':cout << "请输入要进行的操作（1—增加，2—修改，3—查询，4—统计）：" << endl;
		//	char cc; cin >> cc; cin.get();
		//	switch (cc)
		//	{
		//	case '1':cin >> book; break;//book.add_books(); break;
		//	case '2':book.modify_books(); break;
		//	case '3':book.check_info(); break;
		//	case '4':book.ststistic(); break;
		//	}
		//	 break;
		//case '3':cout<<"请输入要进行的操作（1—用户增加，2—用户删除，3—权限管理）："<<endl;
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