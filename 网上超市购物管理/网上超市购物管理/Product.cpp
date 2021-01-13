#include <string>
#include<cstring>
#include <time.h>
#include<fstream>
#include <sstream>
#include<iostream>
#include"ProductLiujw.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

char* getTime2()   //获取当前时间
{
	time_t t = time(nullptr);
	struct tm nowTime;
	localtime_s(&nowTime, &t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &nowTime);
	return tmp;
}
string charToStr(const char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
void DelLineData(const char* fileName, int lineNum)
{
	ifstream in;
	in.open(fileName);

	string strFileData = "";
	int line = 1;
	char lineData[1024] = { 0 };
	while (in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
		}
		else
		{
			strFileData += charToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();

	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}
void modifyContentInFile(const char* fileName, int lineNum,const char* content)
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
			tempStr += charToStr(line);
		}
		else
		{
			tempStr += charToStr(content);
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
int checkData(const char* fileName, char* content)
{
	ifstream in;
	in.open(fileName);
	int i = 0, k;
	string tempStr;
	while (getline(in,tempStr))
	{
		i++;
		k = tempStr.find(content);
		if (k!=-1)
		{
			return i;
		}
	}
	in.close();
	return 0;
}
template <class T> string m_toStr(T tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}
void Product_Ljw::insert(const char* s)
{
	if (s == "product.txt")
	{
		int r = checkData("product.txt", name);
		string con;
		con = m_toStr(serial) + "  " + m_toStr(name) + "  " + m_toStr(in_price) + "  " + m_toStr(out_price) + "  " + m_toStr(stock) + "  " +m_toStr(type)+"  "+ m_toStr(provider) + "  " + m_toStr(time);
		const char* p = con.data();
		if (r != 0)
		{
			con = m_toStr(r) + "  " + m_toStr(name) + "  " + m_toStr(in_price) + "  " + m_toStr(out_price) + "  " + m_toStr(stock) + "  " + m_toStr(type) + "  " + m_toStr(provider) + "  " + m_toStr(time);
			p = con.data();
			cout << "数据已存在，即将更新数据，请稍后..." << endl;
			modifyContentInFile("product.txt", r, p);
		}
		else {
			ofstream fout;
			fout.open("product.txt", ios::app|ios::out);
			cout << "即将添加数据，请稍后..." << endl;
			fout <<p << endl;
			fout.close();
		}
		cout << name << "入库成功！！" << endl;
	}
	else {    //更新顾客购物单
		ofstream fout;
		fout.open(s,ios_base::out|ios_base::app);
		string con;
		con = m_toStr(time)+"  " + m_toStr(name) + "  " +m_toStr(buy_num)+ " * " + m_toStr(out_price) ;
		const char* p = con.data();
		fout << con << endl;
		cout << con << endl;
	}
}
double Product_Ljw::total()
{
	return buy_num * out_price;
}
string Product_Ljw::display(double dis)
{
	return m_toStr(time)+" "+ m_toStr(name) + "  " +"售价："+ m_toStr(out_price) + "  " +"数量："+ m_toStr(buy_num) + "  " +"金额："+ m_toStr(dis*total())+'\n';
}
string Product_Ljw::display12(double dis)
{
	return m_toStr(name) + " " + m_toStr(buy_num) + "  " + m_toStr(total()) + "  " + m_toStr(dis) + "  " + m_toStr(type)+'\n' ;
}
Product_Ljw::Product_Ljw()
{}
string reData(const char* fileName, char* content)
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
template <class Type>
Type stringToNum(const string& str) {
	stringstream iss;
	iss << str;
	Type num=0;
	iss >> num;
	return num;
}
void Product_Ljw::add_pro()
{
	ifstream in("product.txt");
	int i = 1;
	string tempStr;
	while (getline(in, tempStr))
	{
		i++;
	}
	in.close();
	serial = i;
	cout << "请输入添加的商品 名字：" << endl;
	cin >> name; cin.get();
	cout << "请输入添加的商品 进价：" << endl;
	cin >> in_price; cin.get();
	cout << "请输入添加的商品 售价：" << endl;
	cin >> out_price; cin.get();
	cout << "请输入添加的商品 库存：" << endl;
	cin >> stock; cin.get();
	cout << "请输入添加的商品 种类：" << endl;
	cin >> type; cin.get();
	cout << "请输入添加的商品 提供商：" << endl;
	cin >> provider; cin.get();
	strcpy_s(time,20, getTime2());
}
void Product_Ljw::reset(double dis)
{
	cout << "请输入要购买的 商品名称和数量：" << endl;
	char c[20];
	cin >> c;
	cin >> buy_num;
	cin.get();
	string st = reData("product.txt", c);
	if (st != "") {
		int pos1 = st.find("  ", 0);
		string ss = st.substr(0, pos1);
		serial = stringToNum<int>(ss);
		int pos2 = st.find("  ", pos1 + 2);
		ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
		//char* name1 = stringToNum<char*>(ss);
		strcpy_s(name,26, ss.data());
		pos1 = st.find("  ", pos2 + 2);
		ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		in_price = stringToNum<double>(ss);
		pos2 = st.find("  ", pos1 + 2);
		ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
		out_price = stringToNum<double>(ss);
		pos1 = st.find("  ", pos2 + 2);
		ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		stock = stringToNum<int>(ss);
		pos2 = st.find("  ", pos1 + 2);
		ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
		strcpy_s(type, 21, ss.data());
		//char* nn = stringToNum<char*>(ss);
		pos1 = st.find("  ", pos2 + 2);
		ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		strcpy_s(provider,51, ss.data());
		/*pos1 = st.find("  ", pos2 + 2);
		string ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		char* nn = stringToNum<char*>(ss);*/
		strcpy_s(time,20, getTime2());
		//int* a = re_date(time);
		//写入统计数据
		/*string en =  m_toStr(name) + "  " + m_toStr(buy_num) + "  " + m_toStr(total()) + "  " + m_toStr(total() * (1-dis));*/
		/*int year = a[0]; int month = a[1];
		string path = "statistics/" + m_toStr(year) + "/" + m_toStr(month);*/

		/*ofstream fout(path);
		fout << en << endl;
		fout.close();*/
	}
	else {
		cout << "很抱歉，您想买的" << c << "不存在!" << endl;
	}
}