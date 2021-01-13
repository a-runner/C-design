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
	if (t == 1)  //����Ϊѧ��
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
		cout << "�����ڱ�ϵͳ���񷶳룡����" << endl;
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
	string sss = "DEL /f C:\\Users\\10918\\source\\repos\\ѧУͼ�����ϵͳ\\ѧУͼ�����ϵͳ\\" + fileName1;
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
	long hFile = 0; //���
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
			in.close(); //�ر���
		}
	} while (_findnext(hFile, &fileInfo) == 0);
	return 0;
}
void ReaderLjw::modify_info(int k)
{
	int a = 1; string filename;
	if (type == 1)  //ѡ����Ҫ�򿪵��ı��ļ�
		filename = "customer/student.txt";
	else filename = "customer/teacher.txt";
	cout << "�����������޸ĵ���Ϣ����1���û�����2�����룩" << endl;
	char cc; int tt; cin >> cc; cin.get(); string name, pa, name2; name2 = ID; trim(name2);
	switch (cc)
	{
	case '1':cout << "�������µ��û�����" << endl;
		cin >> name; cin.get();
		//�ų��ظ����û���
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
			cout << "������û��������ظ�����" << endl;
			cout << "��������" << endl << endl;
			a = 0;
		}
		else {
			re_name_file("statistic\\" + name2 + ".txt", "statistic\\" + name + ".txt");
			re_name_file("statistic\\" + name2 + "back.txt", "statistic\\" + name + "back.txt");
			//�޸�state_dataÿ���ļ��¾�����
			rename(name2.data(), name.data());
		}
		break;
	case '2':
		cout << "�������µ����룺" << endl;
		cin >> pa; cin.get(); strcpy_s(Password, 21, pa.data());
		//cout << "****" << pa << "***" << Password << endl;
		break;
	}
	if (a == 1) {
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "�û�����"; fout.width(20); fout << ID; fout << "  " << "���룺"; fout.width(20); fout << Password << "  " << "�û����ԣ�"; fout.width(5); fout << type;
		fout << "  " << "Ȩ�ޣ�"; fout.width(6); fout << power;
		fout << "  " << "��������Ŀ��"; fout.width(6); fout << borrow_capasity;
		fout << "  " << "������������"; fout.width(6);fout << max_days;
		fout << "  " << "�ѽ�����Ŀ��"; fout.width(6);fout << borrowed;
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
char* getTime()   //��ȡ��ǰʱ��
{
	time_t t = time(nullptr);
	struct tm nowTime;
	localtime_s(&nowTime, &t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &nowTime);
	return tmp;
}
string simplify(string a)  //��ʱ�仯Ϊ����ʽ
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
	time1 = stringToNum1<int>(a);
	time2 = stringToNum1<int>(b);
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

	//д���ļ�
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
	if (o == 1) {        //����ͼ�� **.txt
		stt.clear();
		fout.open("statistic/" + p + ".txt", ios::app | ios::out);
		stt << "���֣�"; stt.width(20); stt << na << "  " << "���"; stt.width(6); stt << type; stt << "  " << "״̬��"; stt.width(8); stt << "������";
		stt << "  " << "�������ڣ�"; stt.width(64);
		stt << tm; 
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << stt.str().data() << endl;
		fout.close();
		n = -1;

		//ͳ�ƽ�����Ϣ
		ofstream oo;
		oo.open("state_data/" + charToStr(na) + ".txt", ios::app | ios::out);
		oo.setf(ios_base::left, ios_base::adjustfield);
		oo.width(20); oo << ID; oo << "  "; oo.width(64); oo << tm;
		oo << '\n';
		oo.close();
	}
	else if (o == 2)   //�黹ͼ�� **back.txt
	{
		stt.clear();
		fout.open("statistic/" + p + "back.txt", ios::app | ios::out);
		stt << "���֣�"; stt.width(20); stt << na << "  " << "���"; stt.width(6);stt<<type; stt << "  " << "״̬��"; stt.width(8); stt << "�ѹ黹";
		stt << "  " << "�黹���ڣ�"; stt.width(64);
		stt << tm; 
		fout << stt.str().data() << endl; n = 1;
		//*******�ж��Ƿ����ڹ黹*********
		//���Ȼ�ý���ʱ��
		ifstream in; string filename = "statistic/" + p + ".txt";
		in.open("statistic/" + p + "back.txt");
		string re=reDataCount(filename.data(), na, tt);
		string time = re.substr(70, 64); trim(time); string timeNow = charToStr(tm);
		int sub_num = diff_year(time,timeNow);
		if (sub_num > max_days) {
			star2();
			cout << "ͼ��黹�����ڣ���Ҫ���ɷ��ã�����" << endl;
			star2();
		}

		//ͳ�ƽ�����Ϣ
		string path = "state_data/" + charToStr(na)+".txt";
		int line = checkData1( path.data(), ID);
		DelLineData(path.data() , line);
		fout.close();
	}

	//�ı�customer�����borred��Ϣ
	string filename;
	if (type == 1)
		filename = "customer/student.txt";
	else filename = "customer/teacher.txt";
	int tt1 = checkData1(filename.data(), ID);
	//cout << max_days << "*****" << borrowed << endl;
	ostringstream ffout;
	ffout.setf(ios_base::left, ios_base::adjustfield);
	ffout << "�û�����"; ffout.width(20); ffout << ID; ffout << "  " << "���룺"; ffout.width(20); ffout << Password << "  " << "�û����ԣ�"; ffout.width(5); ffout << type;
	ffout << "  " << "Ȩ�ޣ�"; ffout.width(6); ffout << power;
	ffout << "  " << "��������Ŀ��"; ffout.width(6); ffout << (borrow_capasity+n);
	ffout << "  " << "������������"; ffout.width(6);ffout << max_days;
	ffout << "  " << "�ѽ�����Ŀ��"; ffout.width(6);ffout << (borrowed - n);
	modifyContentInFile(filename.data(), tt1, ffout.str().data());
}
void ReaderLjw::borrowBook()
{
	OpLjw op;
	cout << "���潫��ʾ(������50��)����ͼ�飺" << endl;
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
		cout << "Ŀǰ�����Խ��ĵ�ͼ����Ŀ��" << left << endl << endl;
		cout << "��ѡ����Ҫ���ĵ�������(q-�˳�ѡ��ҳ��)" << endl;
		cin >> na; cin.get();
		if (strcmp(na, Q) == 0) break;
		else if (left > 0) {
			k = checkData1("books/books.txt", na);
			con1 = "state_data/" + charToStr(na) + ".txt";
			con1 = "state_data/" + charToStr(na) + "back.txt";
			//�ж��Ƿ��ظ�����
			kk1 = countData(con1.data(), ID);
			kk2= countData(con2.data(), ID);
			if (k != 0 && (kk1==kk2))
			{
				op.mdy_book_stat(na, k, 1);  //����ͼ���״̬ 
				mdy_book(na, 1, 0);     //���Ĺ˿͵� ����ͼ��
				op.stastic_borr(na);
				borrowed++;
			}
			else if (k == 0) {
				cout << "��Ǹ����ѡ���ͼ�鲻���ڣ�����" << endl;
			}
			else if (!(kk1 == kk2))
				cout << "��Ǹ�����鴦�����Ľ���״̬��......" << endl;
		}
	}
}
void ReaderLjw::disBorr()
{
	//����statistic�ڲ��Ľ�����Ϣ
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
	cout << "���ļ�¼��" << endl<<endl;
	cout << content << endl;
	cout << "�黹��¼��" << endl<<endl;
	cout << content2 << endl;
	star2();
}
//�黹ͼ��
void ReaderLjw::giveback()
{	//����Ҫ�黹�����Ƿ��ڽ����鵥��
	OpLjw op;
	char name[20]; string  filename1,filename2;
	while (1) {
		cout << "������Ҫ�黹���������(q���˳�)��" << endl;
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
				cout << "������δ�黹�ĸ�ͼ��" << endl;
			}
		}
	}
}
void ReaderLjw::renew_user()
{
	ofstream fout(".txt", ios_base::app);
	fout << "�û�����" << setw(20) << ID << "  " << "���룺" << setw(20) << Password << "  " << "�û����ԣ�" << setw(5) << '1';
	fout << "  " << "��������Ŀ��" << setw(6) << borrow_capasity;
	fout << "  " << "������������" << setw(6) << max_days;
	fout << "  " << "�ѽ�����Ŀ��" << setw(6) << borrowed;
	fout << '\n';
	fout.close();
}