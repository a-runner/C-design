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
		cout << "�Ƿ�ʼ�����Ŀ����Y or N��" << endl;
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y') {
			cout << "���������������֣�" << endl; cin >> name;
			cout << "���������������ࣺ" << endl; cin >> type;
			cout << "������������������" << endl; cin >> num;
			fout << "���֣�"; fout.width(20); fout << name << "  " << "���ࣺ"; fout.width(10); fout << type;
			fout << "  " << "��棺"; fout.width(6); fout << num<<endl;
			cout << name << "  ��ӳɹ���" << endl;
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
//		cout << "�Ƿ�ʼ�����Ŀ����Y or N��" << endl;
//		cin >> ch; cin.get();
//		if (ch == 'Y' || ch == 'y') {
//			cout << "���������������֣�" << endl; cin >> name;
//			cout << "���������������ࣺ" << endl; cin >> type;
//			cout << "������������������" << endl; cin >> num;
//			fout << "���֣�"; fout.width(20); fout << books.name << "  " << "���ࣺ"; fout.width(10); fout << type;
//			fout << "  " << "��棺"; fout.width(6); fout << num << endl;
//			cout << name << "  ��ӳɹ���" << endl;
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
		cout << "�Ƿ�ʼ�޸���Ŀ����Y or N��" << endl;
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y') {
			cout << "���������޸ĵ�������֣�" << endl;
			cin >> cc; cin.get();
			k = checkData2("books/books.txt", cc);
			if (k == 0) {
				cout << "����Ҫ�޸ĵ�����Ϣ�����ڣ���" << endl;
				continue;
			}
			//���ԭ�е���Ϣ
			re = reData2("books/books.txt", cc);
			na = re.substr(6, 20); ty = re.substr(34, 10);
			nu = re.substr(52, 6); trim9(ty); trim9(na); trim9(nu);
			cout << "������Ҫ�޸ĵ���Ϣ��1�����֣�2�����࣬3����������" << endl;
			cin >> ch; cin.get();
			switch (ch)
			{
			case '1':cout << "�������µ����֣�" << endl; cin >> nn; cin.get();
				i = checkData2("books/books.txt", nn);
				if (i != 0)
				{
					cout << endl;
					cout << "������û��������ظ�����" << endl;
					cout << "��������" << endl << endl;
				}
				else na = m_toStr2(nn);
				break;
			case '2':cout << "�������µ����ࣺ" << endl;
				cin >> tp; cin.get(); ty = m_toStr2(tp);
				break;
			case '3':cout << "�������µĿ��������" << endl;
				cin >> count; cin.get(); nu = m_toStr2(count);
				break;
			}
			fout << "���֣�"; fout.width(20); fout << na << "  " << "���ࣺ"; fout.width(10); fout << ty;
			fout << "  " << "��棺"; fout.width(6); fout << nu;
			cout << name << "  ��ӳɹ���" << endl;
			modifyContentInFile3("books/books.txt", k, fout.str().data());
			cout << "��Ŀ��Ϣ�޸���ɣ�����" << endl;
		}
		else break;
	}
}
void Books::check_info()
{
	char name[20]; int k;
	cout << "����������Ҫ�鿴����Ŀ���֣�" << endl;
	cin >> name; cin.get();
	k = checkData2("books/books.txt", name);
	if (k == 0) {
		cout << "����Ҫ�޸ĵ�����Ϣ�����ڣ���" << endl;
	}
	else {
		string re = reData2("books/books.txt", name);
		cout << endl << name << "  ����Ϣ��" << endl << endl;
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
	cout << "���漴����ʾ ͼ��軹ͳ����Ϣ��" << endl;
	star1();
	file = "state_data/stastic_data.txt";
	display(file.data());
	star1();
	cout << "�Ƿ���Ҫ��ʾ�ض� ͼ������ߣ���Y or N��" << endl;
	char ch; cin >> ch; cin.get();
	if (ch == 'y' || ch == 'Y')
	{
		cout << "��������Ҫ�鿴�����˵���Ŀ���֣�" << endl;
		char na[20]; cin >> name; cin.get();
		file= "state_data/"+m_toStr2(na)+".txt";
		cout << endl;
		display(file.data());
		cout << endl << "չʾ���...." << endl;
	}
}