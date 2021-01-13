#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <io.h>
#include <direct.h>
#include<iomanip>
#include"Customer.h"
using namespace std;

template <class T> string m_ToStr(const T& tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}
string random_ID()
{
	string ii = "";
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < 6; i++)
	{
		string str_s = m_ToStr(rand() % 100);
		ii = ii + str_s;
	}
	return ii;
}
template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}
CustomerLjw::CustomerLjw()
{
}
template <class T> string m_toStr5(T tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}
//定义函数  解析日期，作为 文件名
int* re_date(char* time)
{
	int a[2];
	string tempStr(m_toStr5(time));
	int p = tempStr.find('-', 0);
	a[0] = stringToNum<int>(tempStr.substr(0, p));   //获取 年份
	a[1] = stringToNum<int>(tempStr.substr(p + 1, 2)); //获取 月份
	return a;
}
char* getTime8()   //获取当前时间
{
	time_t t = time(nullptr);
	struct tm nowTime;
	localtime_s(&nowTime, &t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &nowTime);
	return tmp;
}
//判断并创建文件夹
void jus_mk(string a)
{
	string dir = a;
	if (_access(dir.c_str(), 0) == -1)
	{
		//cout << dir << " is not existing" << endl;
		//cout << "now make it" << endl;
		int flag = _mkdir(dir.c_str());
		if (flag == 0)
		{
			cout << a+"  生成成功！" << endl;
		}
		else {
			cout << a+"  生成失败！" << endl;
		}
	}

}
//存储顾客信息的文件 cus_people.txt
void CustomerLjw::upgrade(string shopp,string shopp2,string shopp3,string shopp4,string shopp5,string shopp6)
{
	if (costs > 999&&costs<1999)
	{
		cout << "您好，添加基本信息后可以成为 普通 会员，享有九八折优惠！！（Y/N）" << endl;
		char ch;
		ID =random_ID();
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y')
		{
			char Pname[20], tel[16]; int pos = costs * 0.98;
			cout << "请输入一些基本信息：" << endl;
			cout << "姓名：" << endl;
			cin >> Pname; cin.get();
			cout << "请输入电话号码：" << endl;
			cin >> tel; cin.get();
			ofstream fout("cus_people.txt",ios_base::app);
			fout <<"流水号："<< setw(12) << ID<<"  "<<"姓名："<<setw(12)<<Pname << "  " <<"会员属性："<<setw(5)<<'2';
			fout << "  " <<"电话号码："<< setw(20) << tel;
			fout << "  " << "会员积分：" << setw(12) << pos; fout << '\n';
			fout.close();
			cout << '\n' << endl;
			cout << "ID:" << ID;
			cout << "合计价格（无折扣）：" << costs*0.98 << endl;
			cout << "欢迎下次再来！！！" << endl;
			string ccc = "CUS/"; string ddd = ".txt";
			ofstream ffout(ccc + m_ToStr(Pname) + ddd,ios_base::app|ios_base::out);
			shopp2 = shopp2.substr(0, shopp2.length() - 1);
			ffout << shopp2<<endl;
			ffout.close();

			//统计数据
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path,ios_base::app);
			shopp5 = shopp5.substr(0, shopp5.length() - 1);
			fffout << shopp5 << endl;
			fffout.close();
		}
		else {
			//统计数据
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path, ios_base::app);
			shopp4 = shopp4.substr(0, shopp4.length() - 1);
			fffout << shopp4 << endl;
			fffout.close();
			cout << "好遗憾，您将失去九八折的优惠！！！" << endl;
		}
	}
	else if(costs>1999){
		cout << "您好，添加基本信息后可以成为 高级 会员，享有九五折优惠！！（Y/N）" << endl;
		char ch;
		string sec = "";
		sec = random_ID();
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y')
		{
			char Pname[20], tel[16]; int pos = costs * 0.95;
			cout << "请输入一些基本信息：" << endl;
			cout << "姓名：" << endl;
			cin >> Pname; cin.get();
			cout << "请输入电话号码：" << endl;
			cin >> tel; cin.get();
			ofstream fout("cus_people.txt", ios_base::out | ios_base::app);
			fout.setf(ios_base::left, ios_base::adjustfield);
			fout << "流水号：" << setw(12) << ID << "  " << "姓名：" << setw(12) << Pname << "  " << "会员属性：" << setw(5) << '3';
			fout << "  " << "电话号码：" << setw(20) << tel;
			fout << "  " << "会员积分：" << setw(12) << pos; fout << '\n';
			fout.close();
			cout << "ID:" << ID;
			cout << "合计价格（无折扣）：" << costs*0.95 << endl;
			cout << "欢迎下次再来！！！" << endl;
			string ccc = "CUS/"; string ddd = ".txt";
			ofstream ffout(ccc + m_ToStr(Pname) + ddd, ios_base::app );
			shopp3 = shopp3.substr(0, shopp3.length() - 1);
			ffout << shopp3 << endl;
			ffout.close();

			//统计数据
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path, ios_base::app);
			shopp6 = shopp6.substr(0, shopp6.length() - 1);
			fffout << shopp6 << endl;
			fffout.close();
		}
		else {
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path, ios_base::app);
			shopp5 = shopp5.substr(0, shopp5.length() - 1);
			fffout << shopp5 << endl;
			fffout.close();
			cout << "好遗憾，您将失去九五折的优惠！！！" << endl;
		}
	}else{}
}
void CustomerLjw::display1()
{
	string ii="";
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < 6; i++)
	{
		int p = rand() % 100;
		 string str_s= m_ToStr(p);
		 ii = ii + str_s;
	}
	ID = ii;
	cout << "流水号：" << ii << endl;
}
void CustomerLjw::display2()
{
	cout << "ID:" << ID;
	cout << "合计价格（无折扣）：" << costs << endl;
	cout << "欢迎下次再来！！！" << endl;
}
//General_MemeberLjw::General_MemeberLjw():CustomerLjw()
//{
//}
//General_MemeberLjw::~General_MemeberLjw()
//{
//	ofstream fout("VIP.txt");
//	string a = "普通会员  ";
//	string b = "高级会员  ";
//	fout << a << m_ToStr(VIP1cos) << endl;
//	fout << b << m_ToStr(VIP2cos) << endl;
//}
//Senior_MemberLjw::Senior_MemberLjw() :General_MemeberLjw()
//{
//}
//Senior_MemberLjw::~Senior_MemberLjw()
//{
//	ofstream fout("VIP.txt");
//	string a = "普通会员  ";
//	string b = "高级会员  ";
//	fout << a << m_ToStr(VIP1cos) << endl;
//	fout << b << m_ToStr(VIP2cos) << endl;
//}
void General_MemeberLjw::display3()
{
	ID = random_ID();
	cout << "普通 会员代码：" << ID << name << endl;
}
void General_MemeberLjw::display4()
{
	cout << "ID:" << ID;
	cout << "合计价格（九八折）：" << dis*costs << endl;
	cout << "欢迎下次再来！！！" << endl;
}
void Senior_MemberLjw::display5()
{
	ID = random_ID();
	cout << "高级 会员代码：" << ID << name << endl;
}
void Senior_MemberLjw::display6()
{
	cout << "\n\n";
	cout << "ID:" << ID;
	cout << "合计价格（九五折）：" << dis * costs << endl;
	cout << "欢迎下次再来！！！" << endl;
}
int checkData2(const char* fileName, const char* content)
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
			return i;
		}
	}
	in.close();
	return 0;
}
string re_reri2(int n)
{
	ifstream fin("product.txt");
	int i = 0;
	string tempStr;
	while (getline(fin, tempStr))
	{
		i++;
		if (i == n)
		{
			/*	int p=tempStr.find(' ',0);
				return  stringToNum<int>(tempStr.substr(0, p));*/
			fin.close();
			return tempStr;
		}
	}
	fin.close();
	return 0;

}
string re_reri6(int n)
{
	ifstream fin("cus_people.txt");
	int i = 0;
	string tempStr;
	while (getline(fin, tempStr))
	{
		i++;
		if (i == n)
		{
			/*	int p=tempStr.find(' ',0);
				return  stringToNum<int>(tempStr.substr(0, p));*/
			fin.close();
			return tempStr;
		}
	}
	fin.close();
	return 0;

}
string charToStr4(const char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
void modifyContentInFile5(const char* fileName, int lineNum, const char* content)
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
			tempStr += charToStr4(line);
		}
		else
		{
			tempStr += charToStr4(content);
			//tempStr += '\n';
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
void General_MemeberLjw::upgrade(string shopp,string shopp2,string shopp3,string shopp4)
{
	if (costs > 999)
	{
		cout << "您好,您即将成为 高级 会员，享有九五折优惠！！（Y/N）" << endl;
		char ch;
		cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y')
		{
			dis = 0.95;
			int e = checkData2("cus_people.txt", name);
			string content = re_reri6(e);
			string ID_n = content.substr(8, 12);
			string Pna = content.substr(28, 12);
			string s = content.substr(52, 5);
			string phone = content.substr(69, 20);
			string poin = content.substr(101, 12);
			ostringstream ss;
			ss.setf(ios_base::left, ios_base::adjustfield);
			ss << "流水号："; ss.width(12);
			ss << ID_n; ss << "  " << "姓名："; ss.width(12); ss << Pna; ss << "  " << "会员属性："; ss.width(5); ss << '3';
			ss << "  " << "电话号码：";
			ss.width(20);
			ss << phone; ss << "  " << "会员积分："; ss.width(12);
			ss << poin;
			cout << endl << endl;
			modifyContentInFile5("cus_people.txt", e, ss.str().data());

			string a4 = "CUS/"; string a5 = ".txt"; string a6 = a4 + m_ToStr(name) + a5;
			ofstream ffout(a6, ios_base::app);
			shopp2 = shopp2.substr(0, shopp2.length() - 1);
			ffout << shopp2 << endl;
			ffout.close();

			//统计数据
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path, ios_base::app);
			shopp4 = shopp4.substr(0, shopp4.length() - 1);
			fffout << shopp4 << endl;
			fffout.close();
		}
		else {
			cout << "好遗憾，您将失去九五折的优惠！！！" << endl;
			string a4 = "CUS/"; string a5 = ".txt"; string a6 = a4 + m_ToStr(name) + a5;
			ofstream ffout(a6, ios_base::app | ios_base::out);
			shopp = shopp.substr(0, shopp.length() - 1);
			ffout << shopp << endl;
			ffout.close();
			
			//统计数据
			strcpy_s(time_T, 20, getTime8());
			//int* a = re_date(time_T);
			int year = re_date(time_T)[0]; int month = re_date(time_T)[1];
			string path = "statistics/" + m_toStr5(year) + "/";
			jus_mk(path);
			path += m_toStr5(month) + ".txt";
			ofstream fffout(path, ios_base::app);
			shopp3 = shopp3.substr(0, shopp3.length() - 1);
			fffout << shopp3 << endl;
			fffout.close();
		}
	}
}
