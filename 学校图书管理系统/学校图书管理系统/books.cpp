#include"operate.h"
#include<string>
#include<cstring>
#include <time.h>
#include<fstream>
#include <sstream>
#include<cstdio>
#include <sys/types.h>
#include <io.h>
#include<iostream>
#include"books.h"

string charToStr3(const char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
template <class T> string m_toStr2(T tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}
Books::Books()
{
	num = 0;
	strcpy_s(name, 21, "");
	strcpy_s(type, 11, "");
}
void Books::add_books()
{
	ofstream fout; char ch;
	fout.open("books/books.txt", ios_base::out | ios_base::app);
	while (1)
	{
		cout << "是否开始添加书目？（Y or N）" << endl;
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y') {
			cout << "请输入添加书的名字：" << endl; cin >> name;
			cout << "请输入添加书的种类：" << endl; cin >> type;
			cout << "请输入添加书的数量：" << endl; cin >> num;
			fout << "名字："; fout.width(20); fout << name << "  " << "种类："; fout.width(10); fout << type;
			fout << "  " << "库存："; fout.width(6); fout << num<<endl;
			cout << name << "  添加成功！" << endl;
		}
		else break;
	}
}
//istream& operator>>(istream& cin, const Books& books)
//{
//	ofstream fout; char ch; char name[20], type[10]; int num;
//	fout.open("books/books.txt", ios_base::out | ios_base::app);
//	while (1)
//	{
//		cout << "是否开始添加书目？（Y or N）" << endl;
//		cin >> ch; cin.get();
//		if (ch == 'Y' || ch == 'y') {
//			cout << "请输入添加书的名字：" << endl; cin >> name;
//			cout << "请输入添加书的种类：" << endl; cin >> type;
//			cout << "请输入添加书的数量：" << endl; cin >> num;
//			fout << "名字："; fout.width(20); fout << books.name << "  " << "种类："; fout.width(10); fout << type;
//			fout << "  " << "库存："; fout.width(6); fout << num << endl;
//			cout << name << "  添加成功！" << endl;
//		}
//		else break;
//	}
//	return cin;
//}
int checkData2(const char* fileName, char* content)
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
string reData2(const char* fileName, char* content)
{
	ifstream in;
	in.open(fileName);
	int i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		i++;
		if (tempStr.find(content) != std::string::npos)
		{
			in.close();
			return tempStr;
		}
	}
	in.close();
	return "";
}
void modifyContentInFile3(const char* fileName, int lineNum, const char* content)
{
	ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if (lineNum != i)
		{
			tempStr += charToStr3(line);
		}
		else
		{
			tempStr += charToStr3(content);
		}
		tempStr += '\n';
	}
	in.close();
	ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
}
void trim9(string& s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}
void Books::modify_books()
{
	char ch; char cc[20], nn[20],tp[10]; int k, i,count; string re, na, ty, nu; ostringstream fout;
	while (1)
	{
		cout << "是否开始修改书目？（Y or N）" << endl;
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y') {
			cout << "请输入想修改的书的名字：" << endl;
			cin >> cc; cin.get();
			k = checkData2("books/books.txt", cc);
			if (k == 0) {
				cout << "您想要修改的书信息不存在！！" << endl;
				continue;
			}
			//获得原有的信息
			re = reData2("books/books.txt", cc);
			na = re.substr(6, 20); ty = re.substr(34, 10);
			nu = re.substr(52, 6); trim9(ty); trim9(na); trim9(nu);
			cout << "请输入要修改的信息（1—名字，2—种类，3—数量）：" << endl;
			cin >> ch; cin.get();
			switch (ch)
			{
			case '1':cout << "请输入新的名字：" << endl; cin >> nn; cin.get();
				i = checkData2("books/books.txt", nn);
				if (i != 0)
				{
					cout << endl;
					cout << "输入的用户名出现重复！！" << endl;
					cout << "操作中制" << endl << endl;
				}
				else na = m_toStr2(nn);
				break;
			case '2':cout << "请输入新的种类：" << endl;
				cin >> tp; cin.get(); ty = m_toStr2(tp);
				break;
			case '3':cout << "请输入新的库存数量：" << endl;
				cin >> count; cin.get(); nu = m_toStr2(count);
				break;
			}
			fout << "名字："; fout.width(20); fout << na << "  " << "种类："; fout.width(10); fout << ty;
			fout << "  " << "库存："; fout.width(6); fout << nu;
			cout << name << "  添加成功！" << endl;
			modifyContentInFile3("books/books.txt", k, fout.str().data());
			cout << "书目信息修改完成！！！" << endl;
		}
		else break;
	}
}
void Books::check_info()
{
	char name[20]; int k;
	cout << "请输入您想要查看的书目名字：" << endl;
	cin >> name; cin.get();
	k = checkData2("books/books.txt", name);
	if (k == 0) {
		cout << "您想要修改的书信息不存在！！" << endl;
	}
	else {
		string re = reData2("books/books.txt", name);
		cout << endl << name << "  的信息：" << endl << endl;
		cout << re << endl<<endl;
	}
}
void star1()
{
	for (int i = 0; i < 50; i++)
		cout << '*';
	cout << endl;
}
void display(const char* file)
{
	ifstream in; string temp;
	in.open(file);
	while (getline(in, temp))
	{
		cout << temp << endl;
	}
}
template <class Type>
Type stringToNum4(const string& str) {
	istringstream iss(str);
	Type num = 0;
	iss >> num;
	return num;
}
void Books::ststistic()
{
	string file;
	cout << "下面即将显示 图书借还统计信息：" << endl;
	star1();
	file = "state_data/stastic_data.txt";
	display(file.data());
	star1();
	cout << "是否需要显示特定 图书借阅者？（Y or N）" << endl;
	char ch; cin >> ch; cin.get();
	if (ch == 'y' || ch == 'Y')
	{
		cout << "请输入想要查看借阅人的书目名字：" << endl;
		char na[20]; cin >> name; cin.get();
		file= "state_data/"+m_toStr2(na)+".txt";
		cout << endl;
		display(file.data());
		cout << endl << "展示完毕...." << endl;
	}
}