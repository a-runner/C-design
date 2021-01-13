#include<iostream>
#include<string>
#include<stdlib.h>
#include <io.h>
#include<ctime>
//#include<dirent.h>
#include <vector>
#include <sys/types.h>
#include <algorithm>
#include<fstream>
#include <sstream>
#include<cstdio>
#include"Store.h"
#include"ProductLiujw.h"

using namespace std;
char* getTime11()   //��ȡ��ǰʱ��
{
	time_t t = time(nullptr);
	struct tm nowTime;
	localtime_s(&nowTime, &t);
	char tmp[64];
	//strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &nowTime);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", &nowTime);
	return tmp;
}
//char* getTime1()   //��ȡ��ǰʱ��
//{
//	time_t t = time(nullptr);
//	struct tm nowTime;
//	localtime_s(&nowTime, &t);
//	char tmp[64];
//	strftime(tmp, sizeof(tmp), "%Y-%m-%d", &nowTime);
//	/*time_t timep;
//	time(&timep);
//	char tmp[64];
//	strftime(tmp, sizeof(tmp), "%Y-%m-%d", localtime(&timep));*/
//	return tmp;
//}
string charToStr1(const char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
void DelLineData1(const char* fileName, int lineNum)
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
			strFileData += charToStr1(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();

	//д���ļ�
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}
void modifyContentInFile1(const char* fileName, int lineNum, const char* content)
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
			tempStr += charToStr1(line);
		}
		else
		{
			tempStr += charToStr1(content);
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
int checkData1(const char* fileName,const char* content)
{
	ifstream in;
	in.open(fileName);
	int i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		i++;
		if (tempStr.find(content)!=std::string::npos)
		{
			in.close();
			return i;
		}
	}
	in.close();
	return 0;
}
template <class T> string m_toStr(T tmp)
{
	stringstream ss;
	ss << tmp;
	return ss.str();
}
template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num=0;
	iss >> num;
	return num;
}
void check_display1(const char* filename, int linenum)
{
	ifstream in;
	in.open(filename);
	int i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		i++;
		if (i==linenum)
		{
			cout << tempStr << endl;
			break;
		}
	}
	in.close();
}
void Store::check_name()
{
	string content;
	cout << "����������Ҫ��ѯ�Ļ�Ա ������" << endl;
	cin >> content;
	cin.get();
	int re = checkData1("cus_people.txt", content.data());//stringToNum<char*>(content)
	if (re == 0)
	{
		cout << "����Ҫ��ѯ����Ϣ�����ڣ�����" << endl;
	}
	else {
		cout << content << "  �Ļ�����Ϣ��" << endl;
		check_display1("cus_people.txt", re);
	}
}
void trim(string& s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}
void re_name_file(string fileName1, string fileName2)
{
	ifstream in;
	in.open(fileName1);
	ofstream ou;
	ou.open(fileName2);
	string tempStr,content="";
	while (getline(in, tempStr))
	{
		content += tempStr;
	}
	in.close();
	ou << content;
	ou.close();
	string sss = "DEL /f C:\\Users\\10918\\source\\repos\\���ϳ��й������\\���ϳ��й������\\" + fileName1;
	system(sss.data());
}
void Store::modify_name()
{
	string content;
	cout << "����������Ҫ�޸ĵĻ�Ա ������" << endl;
	cin >> content;
	cin.get();
	int re = checkData1("cus_people.txt",content.data());
	ifstream in;
	in.open("cus_people.txt");
	int i = 0;
	string tempStr;
	while (getline(in, tempStr))
	{
		i++;
		if (i == re)
		{
			content = tempStr;
			break;
		}
	}
	string ID_n = content.substr(8, 12);
	string Pna = content.substr(28, 12);
	string s = content.substr(52, 5);
	string phone = content.substr(69, 20);
	string poin = content.substr(101, 12);
	cout << "������Ҫ�޸ĵ���Ϣ��ţ�1-������2-�绰���룬3-���֣���" << endl;
	char ch;
	string Pna5 = Pna;
	cin >> ch;
	cin.get();
	switch(ch)
	{
	case '1':cout << "�������µ� ���֣�" << endl; trim(Pna5);
		cin >> Pna; cin.get(); re_name_file("CUS\\"+Pna5+".txt","CUS\\"+Pna+".txt");
		break;
	case '2':cout << "�������µ� �绰���룺" << endl;
		cin >> phone; cin.get();
		break;
	case '3':cout << "�������µ� ���֣�" << endl;
		cin >> poin; cin.get();
		break;
	default:
		break;
	}
	ostringstream ss;
	ss.setf(ios_base::left, ios_base::adjustfield);
	ss << "��ˮ�ţ�"; ss.width(12);
	ss << ID_n; ss << "  " << "������"; ss.width(12); ss << Pna; ss << "  " << "��Ա���ԣ�"; ss.width(5); ss <<  s;
	ss << "  " << "�绰���룺";
	ss.width(20);
	ss << phone; ss << "  " << "��Ա���֣�"; ss.width(12);
	ss << poin;
	cout << endl<<endl;
	modifyContentInFile1("cus_people.txt", re, ss.str().data());//stringToNum<char*>(ss.str())
	cout << "�޸���Ϣ�ɹ�����" << endl;
}
void Store::del_name()
{
	string content;
	cout << "����������Ҫɾ���Ļ�Ա ������" << endl;
	cin >> content;
	cin.get();
	int re = checkData1("cus_people.txt", content.data());//stringToNum<char*>(content)
	DelLineData1("cus_people.txt", re); trim(content);
	//string sss = "DEL /f C:\\Users\\10918\\source\\repos\\���ϳ��й������\\���ϳ��й������\\CUS\\" + content+".txt";
	string sss = "DEL /f CUS\\" + content + ".txt";
	system(sss.data());
	cout << "��Ա��" << content << " ��Ϣɾ���ɹ�������" << endl;
}
void Store::del_no_buy()
{
	/*int a[12];
	int j = 0;*/
	ifstream in;
	in.open("cus_people.txt");
	string tempStr;
	int i = 0;
	while (getline(in, tempStr))
	{
		i++;
		string Pna = tempStr.substr(28, 12);
		ifstream fin; trim(Pna);
		fin.open("CUS/"+Pna+".txt");
		string tempstr;
		getline(fin, tempstr);
		if (tempstr == "")
		{
			fin.close();
			//string a11 = "CUS/"; string a22 = ".txt"; string a33 = a11 + Pna + a33;
			//if (remove(a33.data()) == 0)  //stringToNum < char*>(a33)
			//{
				//a[j] = i; j++;
			DelLineData1("cus_people.txt", i);
			string sss = "DEL /f C:\\Users\\10918\\source\\repos\\���ϳ��й������\\���ϳ��й������\\CUS\\" + Pna + ".txt";
			//string sss = "DEL /f CUS\\" + Pna + ".txt";
			system(sss.data());
			cout <<"��Ա "<< Pna << "����Ϣɾ���ɹ�������" << endl;
			/*}
			else {
				cout << Pna << "����ϢĿǰ������ɾ��������" << endl;
			}*/
		}
		else { fin.close(); }
	}
}
string simplify(string a)
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
	//�����ƽ�������ÿ�µ�����
	int monthDays[13][2] = {
		{0,0},{31,31},{28,29},{30,30},{31,31},{30,30},
		{31,31},{30,30},{31,31},{30,30},{31,31},{30,30},
		{31,31}
	};
	int time1, year1, month1, days1;
	int time2, year2, month2, days2;
	int numbers = 1;
	time1 = stringToNum<int>(a);
	time2 = stringToNum<int>(b);
	if (time1 > time2) {
		int temp = time1;
		time1 = time2;
		time2 = temp;
	}
	//������ڣ���Ϊ�꣬�£���
	year1 = time1 / 10000; month1 = time1 / 100 % 100; days1 = time1 % 100;
	year2 = time2 / 10000; month2 = time2 / 100 % 100; days2 = time2 % 100;
	//��һ������ �ۼӵ� �ڶ�������
	while (year1 < year2 || month1 < month2 || days1 < days2) {
		days1++;// �ڵ�һ�����ڻ�����  ��һ��
		//��һ�����Ӧ���£������ҲҪ��һ���ı仯
		if (days1 == monthDays[month1][isLeap(year1)] + 1) {//��ǰ�ų�����ǰ������������·ݼ�1���ű�����µ�1��
			month1++;
			days1 = 1;
		}
		if (month1 == 13) {//�·ݳ���12���� ����ݼ�1,�·ݱ�������1��
			year1++;
			month1 = 1;
		}
		numbers++;
	}
	//cout << numbers << endl;
	return numbers;
}
int Store::delete_info()
{
	//��ȡtxt
	//vector<string> file_name;
	//string path = "CUS/";

	////��ȡ�ļ�����
	//DIR* pDir;
	//struct dirent* ptr;
	//if (!(pDir = opendir(path.c_str())))
	//	return 0;
	//while ((ptr = readdir(pDir)) != 0) {
	//	if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
	//		file_name.push_back(path + "/" + ptr->d_name);  //�ļ�·�������ص�file_name��vector��
	//}
	//closedir(pDir);
	long hFile = 0; //���
	struct _finddata_t fileInfo;
	string path = "CUS/"; string type = ".txt";
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
			filen = "CUS/" + filen;
			cout << filen << endl;
			in.open(filen);
			int n = 0;
			string tim;
			string time_now;
			string tempStr;
			char ttime[64];
			while (getline(in, tempStr))
			{
				if (tempStr != "") {
					n++;
					tim = tempStr.substr(0, 11);
					strcpy_s(ttime, 20, getTime11());
					time_now = m_toStr(ttime);
					trim(tim); trim(time_now);
					tim = simplify(tim);
					time_now = simplify(time_now);
					if (diff_year(tim, time_now) > 365)
					{
						//DelLineData1(filen.data(), n);
						a[i] = n;
						i++;
					}
				}
			}
			in.close(); //�ر���
			for (int i = 0,j=0; a[i] != 0;i++,j++)
			{
				DelLineData1(filen.data(), a[i]-j);
				cout << "ɾ�� " << fileInfo.name << " һ����Ϣ��" << endl;
			}
		}
	} while (_findnext(hFile, &fileInfo) == 0);
	return 0;
}
void Store::add_product()
{
	char ch;
	cout << "�뿪ʼ�����Ʒ��Ϣ����Y/N��" << endl;
	cin.get(ch); cin.get();
	while (ch == 'Y' || ch == 'y')
	{
		Product_Ljw prod;
		prod.add_pro();
		prod.insert("product.txt");
		cout << "�ɹ���������Ʒ��" << prod.name << endl;
		cout << "�������ʼ�����Ʒ��Ϣ����Y/N��" << endl;
		cin.get(ch); cin.get();
	}
}
string re_reri1(int n)
{
	ifstream fin("product.txt");
	int i = 0;
	string tempStr;
	while (getline(fin, tempStr))
	{
		i++;
		if (i==n)
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
void Store::modify_product()
{
	cout << "������Ҫ��ѯ����Ʒ�� ���֣�" << endl;
	char na[20];
	cin >> na;
	int e = checkData1("product.txt", na);
	string st = re_reri1(e);
	cout << "������Ҫ�޸ĵ���Ϣ��ţ�1-���֣�2-���ۣ�3-�ۼۣ�4-��棬5-���̣���" << endl;
	char ch;
	cin >> ch;
	cin.get();
	int serial=0; double in_price = 0; double out_price = 0; int stock = 0; 

	if (st != "") {
		int pos1 = st.find("  ", 0);
		string ss = st.substr(0, pos1);
		serial = stringToNum<int>(ss);
		int pos2 = st.find("  ", pos1 + 2);
		/*ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
		char* name1 = stringToNum<char*>(ss);*/
		//strcpy_s(name, 25, name1);
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
		string stype = st.substr(pos1 + 2, pos2 - pos1 - 2);
		pos1 = st.find("  ", pos2 + 2);
		ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		//strcpy_s(nn,stringToNum<char*>(ss));

		//strcpy_s(provider, nn);
		/*pos1 = st.find("  ", pos2 + 2);
		string ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
		char* nn = stringToNum<char*>(ss);*/
		//strcpy_s(time, getTime2());

		switch (ch)
		{
		case '1':cout << "�������µ� ���֣�" << endl;
			cin >> na; cin.get();
			break;
		case '2':cout << "�������µ� ���ۣ�" << endl;
			cin >> in_price; cin.get();
			break;
		case '3':cout << "�������µ� �ۼۣ�" << endl;
			cin >> out_price; cin.get();
			break;
		case '4':cout << "�������µ� ��棺" << endl;
			cin >> stock; cin.get();
			break;
		case '5':cout << "�������µ� ���̣�" << endl;
			cin >> ss; cin.get();
			break;
		default:
			break;
		}
		char time[64];
		strcpy_s(time,20, getTime2());
		string aa = m_toStr(serial) + "  " + m_toStr(na) + "  " + m_toStr(in_price) + "  " + m_toStr(out_price) + "  " + m_toStr(stock) +"  "+m_toStr(stype)+ "  " + ss + "  " + m_toStr(time)+'\n';
		modifyContentInFile1("product.txt", e, aa.data());
		cout << "��Ϣ�޸���ɣ���" << endl;
	}
	else {
		cout << "�ܱ�Ǹ�������޸ĵ�" << na << "������!" << endl;
	}
}
void DelLinePro1(const char* fileName, int lineNum)
{
	ifstream in;
	in.open(fileName);

	string strFileData = "";
	int line = 1;
	string st="";
	int serial = 0; double in_price = 0; double out_price = 0; int stock = 0;
	
	while (getline(in,st))
	{
		if (lineNum > line) { strFileData += st; strFileData += '\n'; }
		if (lineNum == line) { }
		if (lineNum<line) {
			int pos1 = st.find("  ", 0);
			string ss = st.substr(0, pos1);
			serial = stringToNum<int>(ss);
			int pos2 = st.find("  ", pos1 + 2);
			ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
			string na = ss;
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
			string stype = st.substr(pos1 + 2, pos2 - pos1 - 2);
			pos1 = st.find("  ", pos2 + 2);
			ss = st.substr(pos2 + 2, pos1 - pos2 - 2);
			char time[64];
			strcpy_s(time, 20, getTime2());
			strFileData+= m_toStr(serial-1) + "  " + m_toStr(na) + "  " + m_toStr(in_price) + "  " + m_toStr(out_price) + "  " + m_toStr(stock) + "  " + m_toStr(stype) + "  " + ss + "  " + m_toStr(time)+'\n';
		}
		line++;
	}
	in.close();

	//д���ļ�
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}
void Store::del_product()
{
	cout << "������Ҫɾ������Ʒ�� ���֣�" << endl;
	char na[20];
	cin >> na;
	int e = checkData1("product.txt", na);
	DelLinePro1("product.txt", e);
	cout << "��Ʒ��" << na << "ɾ����ɣ���" << endl;
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
			return tempStr;
		}
	}
	return "";
}
void Store::check_product()
{
	cout << "��������Ҫ��ѯ����Ʒ���֣�" << endl;
	char na[20];
	cin >> na; cin.get();
	string con=reData1("product.txt", na);
	cout << na << "��Ʒ���ݣ�" << endl;
	cout << con << endl;
}
void Store::check_num_product(int a)
{
	cout << "���潫��� ��� ����" << a << "����Ʒ��Ϣ:" << endl;
	ifstream in;
	in.open("product.txt");
	int i = 0;
	string st;
	char name[25];
	int serial,stock; double in_price, out_price;
	while (getline(in, st))
	{
		i++;
		int pos1 = st.find("  ", 0);
		string ss = st.substr(0, pos1);
		serial = stringToNum<int>(ss);
		int pos2 = st.find("  ", pos1 + 2);
		ss = st.substr(pos1 + 2, pos2 - pos1 - 2);
		//const char* name1 = stringToNum<char*>(ss);
		//strcpy_s(name,25, name1);
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
		//char* nn = stringToNum<char*>(ss);
		if (stock < a)
		{
			cout << st << endl;
		}
	}
	cout << "�����ϣ���" << endl;
}