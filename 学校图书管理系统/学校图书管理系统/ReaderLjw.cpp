#include"User.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<io.h>
#include<cstdio>
#include<sys/types.h>
using namespace std;

ReaderLjw::ReaderLjw()
{}
ReaderLjw::~ReaderLjw()
{
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
int checkData1(const char* fileName, const char* content)
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
int countData(const char* fileName, const char* content)
{
	ifstream in;
	in.open(fileName);
	int k, i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		k = tempStr.find(content);
		if (k != -1)
		{
			i++;
		}
	}
	in.close();
	return i;
}
string reDataCount(const char* fileName, const char* content,int t)
{
	ifstream in;
	in.open(fileName);
	int i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		if (tempStr.find(content) != std::string::npos)
		{
			i++;
			if (i == t) {
				in.close();
				return tempStr;
			}
		}
	}
	in.close();
	return "";
}
void modifyContentInFile(const char* fileName, int lineNum, const char* content)
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
ReaderLjw::ReaderLjw(int t) :type(t), power(1)
{
	borrowed = 0;
	if (t == 1)  //读者为学生
	{
		borrow_capasity = 10;
		max_days = 30;
	}
	else if (t == 2 || t==3||t==4)
	{
		borrow_capasity = 30;
		max_days = 100;
	}
	else
	{
		cout << "不属于本系统服务范畴！！！" << endl;
	}
}
void re_name_file(string fileName1, string fileName2)
{
	ifstream in;
	in.open(fileName1);
	ofstream ou;
	ou.open(fileName2);
	string tempStr, content = "";
	while (getline(in, tempStr))
	{
		content += tempStr;
		content += '\n';
	}
	in.close();
	ou << content;
	ou.close();
	string sss = "DEL /f C:\\Users\\10918\\source\\repos\\学校图书管理系统\\学校图书管理系统\\" + fileName1;
	system(sss.data());
}
void trim(string& s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}
template <class Type>
Type stringToNum1(const string& str) {
	stringstream iss;
	iss << str;
	Type num = 0;
	iss >> num;
	return num;
}
string reData5(const char* fileName, char* content)
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
int rename(char* name1, char* name2)
{
	string ID, tm;
	long hFile = 0; //句柄
	struct _finddata_t fileInfo;
	string path = "state_data/"; string type = ".txt";
	string pathName;
	if ((hFile = _findfirst(pathName.assign(path).append("\\*.*").c_str(), &fileInfo)) == -1)
	{
		return 1;
	}
	do
	{
		const char* s = fileInfo.name;
		const char* t = type.data();

		if (strstr(s, t))
		{
			ifstream in; int a[1024]{ 0 }; int i = 0;
			string filen = fileInfo.name;
			filen = "state_data/" + filen;
			//cout << filen << endl;
			in.open(filen);
			string tempStr;
			int k = checkData1(filen.data(), name1);
			if (k != 0)
			{
				//oo.width(20); oo << ID; oo << "  "; oo.width(64); oo << tm;
				tempStr = reData5(filen.data(), name1);
				ID = charToStr(name2);
				tm = tempStr.substr(22, 64);
				trim(ID); trim(tm);
				ostringstream st;
				st << setw(20) << ID << setw(64) << tm;
				modifyContentInFile(filen.data(), k, st.str().data());
			}
			in.close(); //关闭流
		}
	} while (_findnext(hFile, &fileInfo) == 0);
	return 0;
}
void ReaderLjw::modify_info(int k)
{
	int a = 1; string filename;
	if (type == 1)  //选择需要打开的文本文件
		filename = "customer/student.txt";
	else filename = "customer/teacher.txt";
	cout << "请输入你想修改的信息：（1—用户名，2—密码）" << endl;
	char cc; int tt; cin >> cc; cin.get(); string name, pa, name2; name2 = ID; trim(name2);
	switch (cc)
	{
	case '1':cout << "请输入新的用户名：" << endl;
		cin >> name; cin.get();
		//排除重复的用户名
		tt = checkData1(filename.data(), name.data());
		//cout << "******" << tt << endl;
		if (tt == 0)
		{
			strcpy_s(ID, 20, name.data());
			//cout << "****" << ID<<pa << "***" << Password << endl;
		}
		if (tt != 0)
		{
			cout << endl;
			cout << "输入的用户名出现重复！！" << endl;
			cout << "操作中制" << endl << endl;
			a = 0;
		}
		else {
			re_name_file("statistic\\" + name2 + ".txt", "statistic\\" + name + ".txt");
			re_name_file("statistic\\" + name2 + "back.txt", "statistic\\" + name + "back.txt");
			//修改state_data每个文件下旧名字
			rename(name2.data(), name.data());
		}
		break;
	case '2':
		cout << "请输入新的密码：" << endl;
		cin >> pa; cin.get(); strcpy_s(Password, 21, pa.data());
		//cout << "****" << pa << "***" << Password << endl;
		break;
	}
	if (a == 1) {
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "用户名："; fout.width(20); fout << ID; fout << "  " << "密码："; fout.width(20); fout << Password << "  " << "用户属性："; fout.width(5); fout << type;
		fout << "  " << "权限："; fout.width(6); fout << power;
		fout << "  " << "最大借阅数目："; fout.width(6); fout << borrow_capasity;
		fout << "  " << "最大借阅天数："; fout.width(6);fout << max_days;
		fout << "  " << "已借阅数目："; fout.width(6);fout << borrowed;
		cout << fout.str().data() << endl;
		modifyContentInFile(filename.data(), k, fout.str().data());//stringToNum<char*>(ss.str())
	}
}
void star2()
{
	for (int i = 0; i < 50; i++)
		cout << '*';
	cout << endl;
}
char* getTime()   //获取当前时间
{
	time_t t = time(nullptr);
	struct tm nowTime;
	localtime_s(&nowTime, &t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &nowTime);
	return tmp;
}
string simplify(string a)  //将时间化为简洁格式
{
	string b;
	b = a.substr(0, 4) + a.substr(5, 2) + a.substr(8, 2);
	return b;
}
bool isLeap(int year) {
	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}
int diff_year(string& a, string& b)
{
	//定义好平年和闰年每月的天数
	int monthDays[13][2] = {
		{0,0},{31,31},{28,29},{30,30},{31,31},{30,30},
		{31,31},{30,30},{31,31},{30,30},{31,31},{30,30},
		{31,31}
	};
	int time1, year1, month1, days1;
	int time2, year2, month2, days2;
	int numbers = 1;
	time1 = stringToNum1<int>(a);
	time2 = stringToNum1<int>(b);
	if (time1 > time2) {
		int temp = time1;
		time1 = time2;
		time2 = temp;
	}
	//拆解日期，分为年，月，号
	year1 = time1 / 10000; month1 = time1 / 100 % 100; days1 = time1 % 100;
	year2 = time2 / 10000; month2 = time2 / 100 % 100; days2 = time2 % 100;
	//第一个日期 累加到 第二个日期
	while (year1 < year2 || month1 < month2 || days1 < days2) {
		days1++;// 在第一个日期基础上  加一天
		//加一天后，相应的月，年可能也要做一定的变化
		if (days1 == monthDays[month1][isLeap(year1)] + 1) {//当前号超过当前月最高天数：月份加1，号变成下月的1号
			month1++;
			days1 = 1;
		}
		if (month1 == 13) {//月份超过12个月 ：年份加1,月份变成下年的1月
			year1++;
			month1 = 1;
		}
		numbers++;
	}
	//cout << numbers << endl;
	return numbers;
}
string reData1(const char* fileName, char* content)
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
void ReaderLjw::mdy_book(char* na,int o,int tt)
{
	string p = ID; trim(p);
	ofstream fout; char tm[64]; strcpy_s(tm, 20, getTime());

	ostringstream stt; int n = 0; 
	if (o == 1) {        //借阅图书 **.txt
		stt.clear();
		fout.open("statistic/" + p + ".txt", ios::app | ios::out);
		stt << "名字："; stt.width(20); stt << na << "  " << "类别："; stt.width(6); stt << type; stt << "  " << "状态："; stt.width(8); stt << "借阅中";
		stt << "  " << "借阅日期："; stt.width(64);
		stt << tm; 
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << stt.str().data() << endl;
		fout.close();
		n = -1;

		//统计借阅信息
		ofstream oo;
		oo.open("state_data/" + charToStr(na) + ".txt", ios::app | ios::out);
		oo.setf(ios_base::left, ios_base::adjustfield);
		oo.width(20); oo << ID; oo << "  "; oo.width(64); oo << tm;
		oo << '\n';
		oo.close();
	}
	else if (o == 2)   //归还图书 **back.txt
	{
		stt.clear();
		fout.open("statistic/" + p + "back.txt", ios::app | ios::out);
		stt << "名字："; stt.width(20); stt << na << "  " << "类别："; stt.width(6);stt<<type; stt << "  " << "状态："; stt.width(8); stt << "已归还";
		stt << "  " << "归还日期："; stt.width(64);
		stt << tm; 
		fout << stt.str().data() << endl; n = 1;
		//*******判断是否逾期归还*********
		//首先获得借阅时间
		ifstream in; string filename = "statistic/" + p + ".txt";
		in.open("statistic/" + p + "back.txt");
		string re=reDataCount(filename.data(), na, tt);
		string time = re.substr(70, 64); trim(time); string timeNow = charToStr(tm);
		int sub_num = diff_year(time,timeNow);
		if (sub_num > max_days) {
			star2();
			cout << "图书归还已逾期，需要缴纳费用！！！" << endl;
			star2();
		}

		//统计借阅信息
		string path = "state_data/" + charToStr(na)+".txt";
		int line = checkData1( path.data(), ID);
		DelLineData(path.data() , line);
		fout.close();
	}

	//改变customer里面的borred信息
	string filename;
	if (type == 1)
		filename = "customer/student.txt";
	else filename = "customer/teacher.txt";
	int tt1 = checkData1(filename.data(), ID);
	//cout << max_days << "*****" << borrowed << endl;
	ostringstream ffout;
	ffout.setf(ios_base::left, ios_base::adjustfield);
	ffout << "用户名："; ffout.width(20); ffout << ID; ffout << "  " << "密码："; ffout.width(20); ffout << Password << "  " << "用户属性："; ffout.width(5); ffout << type;
	ffout << "  " << "权限："; ffout.width(6); ffout << power;
	ffout << "  " << "最大借阅数目："; ffout.width(6); ffout << (borrow_capasity+n);
	ffout << "  " << "最大借阅天数："; ffout.width(6);ffout << max_days;
	ffout << "  " << "已借阅数目："; ffout.width(6);ffout << (borrowed - n);
	modifyContentInFile(filename.data(), tt1, ffout.str().data());
}
void ReaderLjw::borrowBook()
{
	OpLjw op;
	cout << "下面将显示(不多于50本)现有图书：" << endl;
	star2();
	ifstream in; int k = 0;
	in.open("books/books.txt");
	string tempStr, content = "";
	while (getline(in, tempStr))
	{
		if (k < 50)
		{
			content += tempStr;
			content += '\n';
		}
		else { break; }
		k++;
	}
	in.close();
	cout << content; star2();
	char na[20]; char Q[3] = { 'q' };
	int kk1,kk2, left; string con1,con2;
	while (1)
	{
		left = (borrow_capasity - borrowed);
		cout << "目前还可以借阅的图书数目：" << left << endl << endl;
		cout << "请选择想要借阅的书名字(q-退出选择页面)" << endl;
		cin >> na; cin.get();
		if (strcmp(na, Q) == 0) break;
		else if (left > 0) {
			k = checkData1("books/books.txt", na);
			con1 = "state_data/" + charToStr(na) + ".txt";
			con1 = "state_data/" + charToStr(na) + "back.txt";
			//判断是否重复借阅
			kk1 = countData(con1.data(), ID);
			kk2= countData(con2.data(), ID);
			if (k != 0 && (kk1==kk2))
			{
				op.mdy_book_stat(na, k, 1);  //更改图书的状态 
				mdy_book(na, 1, 0);     //更改顾客的 借阅图书
				op.stastic_borr(na);
				borrowed++;
			}
			else if (k == 0) {
				cout << "抱歉，您选择的图书不存在！！！" << endl;
			}
			else if (!(kk1 == kk2))
				cout << "抱歉，该书处于您的借阅状态中......" << endl;
		}
	}
}
void ReaderLjw::disBorr()
{
	//查找statistic内部的借阅信息
	ifstream in;
	in.open("statistic/"+charToStr(ID)+".txt");
	string tempStr,content,content2;
	while (getline(in, tempStr))
	{
		content += tempStr;
		content += '\n';
	}
	in.close();
	in.open("statistic/" + charToStr(ID) + "back.txt");
	while (getline(in, tempStr))
	{
		content2 += tempStr;
		content2 += '\n';
	}
	in.close();
	star2();
	cout << "借阅记录：" << endl<<endl;
	cout << content << endl;
	cout << "归还记录：" << endl<<endl;
	cout << content2 << endl;
	star2();
}
//归还图书
void ReaderLjw::giveback()
{	//查找要归还的书是否在借阅书单中
	OpLjw op;
	char name[20]; string  filename1,filename2;
	while (1) {
		cout << "请输入要归还的书的名字(q—退出)：" << endl;
		 cin >> name; cin.get(); char Q[3] = { 'q' };
		if (strcmp(name, Q) == 0) break;
		else {
			filename1 = "statistic/" + charToStr(ID) + ".txt";
			filename2 = "statistic/" + charToStr(ID) + "back.txt";
			int tt = countData(filename1.data(), name);
			int tk = countData(filename2.data(), name);
			if(tt>tk){
				op.mdy_book_stat(name, tt, 2);
				mdy_book(name, 2,tt);
				op.stastic_back(name);
			}
			else {
				cout << "不存在未归还的该图书" << endl;
			}
		}
	}
}
void ReaderLjw::renew_user()
{
	ofstream fout(".txt", ios_base::app);
	fout << "用户名：" << setw(20) << ID << "  " << "密码：" << setw(20) << Password << "  " << "用户属性：" << setw(5) << '1';
	fout << "  " << "最大借阅数目：" << setw(6) << borrow_capasity;
	fout << "  " << "最大借阅天数：" << setw(6) << max_days;
	fout << "  " << "已借阅数目：" << setw(6) << borrowed;
	fout << '\n';
	fout.close();
}