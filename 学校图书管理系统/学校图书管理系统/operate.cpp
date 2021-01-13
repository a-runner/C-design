#include"operate.h"
#include<string>
#include<cstring>
#include <time.h>
#include<fstream>
#include<iomanip>
#include <sstream>
#include<iostream>
#include<iomanip>
#include<io.h>
#include<cstdio>
#include<sys/types.h>
#include"books.h"
using namespace std;

string charToStr2(const char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
void modifyContentInFile2(const char* fileName, int lineNum, const char* content)
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
			tempStr += charToStr2(line);
		}
		else
		{
			tempStr += charToStr2(content);
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
void modifyContentInFileCount(const char* fileName, int lineNum, const char* content)
{
	ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0,k;
	string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		k = tempStr.find(content);
		if (k != -1)
		{
			i++;
			if (lineNum != i)
			{
				tempStr += charToStr2(line);
			}
			else
			{
				tempStr += charToStr2(content);
			}
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
template <class T> string m_toStr4(T tmp)
{
	ostringstream ss;
	ss << tmp;
	return ss.str();
}
template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	//iss << str;
	Type num;
	iss >> num;
	return num;
}
int checkData5(const char* fileName,const char* content)
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
			in.close();
			return i;
		}
	}
	in.close();
	return 0;
}
string reData(const char* fileName,const char* content)
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
void OpLjw::stastic_borr(char* na)
{
	//���Ȳ���state_data/stastic_data.txt��û��na��û�еĻ������
	int k = checkData5("state_data/stastic_data.txt", na);
	if (k != 0)   //��ͼ���ڼ�¼��
	{
		string re = reData("state_data/stastic_data.txt", na);
		//��ȡ����
		string name = re.substr(6, 20);
		string num = re.substr(34, 6);
		string borr = re.substr(50, 6);
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "���֣�" << setw(20) << name << "  " << "��棺" << setw(6) << stringToNum<int>(num) << "  " << "�ڽ��ģ�" << setw(6) << stringToNum<int>(borr) + 1;

		modifyContentInFile2("state_data/stastic_data.txt", k, fout.str().data());
	}
	else {
		ofstream fout;
		fout.open("state_data/stastic_data.txt", ios::app | ios::out);
		string re = reData("books/books.txt", na);
		//��ȡ��ͼ��ʣ������
		string name = re.substr(6, 20);
		string type = re.substr(34, 10);
		string number = re.substr(52, 6);
		ostringstream ffout;
		ffout << "���֣�" << setw(20) << name << "  " << "��棺" << setw(6) << stringToNum<int>(number) << "  " << "�ڽ��ģ�" << setw(6) <<  '1';
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << ffout.str().data();
		fout.close();
	}
}
void OpLjw::stastic_back(char* na)
{
	int k = checkData5("state_data/stastic_data.txt", na);
	string re = reData("state_data/stastic_data.txt", na);
	//��ȡ����
	string name = re.substr(6, 20);
	string num = re.substr(34, 6);
	string borr = re.substr(50, 6);
	ostringstream fout;
	fout << "���֣�" << setw(20) << name << "  " << "��棺" << setw(6) << stringToNum<int>(num) + 1 << "  " << "�ڽ��ģ�" << setw(6) << stringToNum<int>(borr) - 1;
	fout << '\n';
	modifyContentInFile2("state_data/stastic_data.txt", k, fout.str().data());
}
void trim5(string& s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}
OpLjw::OpLjw() {}
void OpLjw::log_in(int n)
{ 
	ReaderLjw reader(n);
	string ID, pass; string filename;
	char cc; int k;
	cout << "�������û�����" << endl;
	cin >> ID; cin.get(); 
	if (reader.type == 1)  //ѡ����Ҫ�򿪵��ı��ļ�
		filename = "customer/student.txt";
	else 
		filename = "customer/teacher.txt";
	string st, id, pa, typ, borrow_c, max_day, borr,po;
	//k = checkData5(stringToNum<char*>(filename), stringToNum<char*>(ID));
	k = checkData5(filename.data(), ID.data());
	if (k != 0)   //˵�������û�
	{
		//��ʾ�û���Ϣ
		st = reData(filename.data(), ID.data());
		cout << endl << "��ӭ "<<ID<<" !!!" << endl;
		cout << "���������룺" << endl; cin >> pass; cin.get();
		if (st != "")
		{
			id = st.substr(8, 20);
			trim5(id);
			pa = st.substr(36, 20);
			trim5(pa);
			typ = st.substr(68, 5);
			po = st.substr(81, 6);
			trim5(po);
			borrow_c = st.substr(103, 6);
			max_day = st.substr(125, 6);
			borr = st.substr(145, 6);
			trim5(pa); trim5(borrow_c); trim5(max_day); trim5(borr);
			strcpy_s(reader.ID, 21, id.data());
			strcpy_s(reader.Password, 20, pa.data());
			reader.borrowed = stringToNum<int>(borr);
			reader.borrow_capasity = stringToNum<int>(borrow_c);
			reader.type = stringToNum<int>(typ); reader.power = stringToNum<int>(po);
			reader.max_days = stringToNum<int>(max_day); reader.borrowed = stringToNum<int>(borr);
			if (pass==pa)  //˵��Ϊ���û�
			{
			label: 
					k = checkData5(filename.data(), ID.data());
					if ((reader.type == 1 || reader.type == 2)&& reader.power) {
					char ch;
					while (1) {
						cout << "������Ҫ���еĲ�������1�����ģ�2���黹��3��������Ϣ�鿴��4��������Ϣ���޸ģ�q���˳���¼��" << endl;
						char m; cin >> m; cin.get();
						switch (m)
						{
						case '1':reader.borrowBook(); break;
						case '2':reader.giveback(); break;
						case '3':reader.disBorr(); break;
						case '4':reader.modify_info(k); break;
						}
						if (m == 'q' || m == 'Q')break;
					}
				}
				else if (reader.type == 3 && reader.power)  //ͼ�����Ա�Ĳ���
				{
					char kk;
					while (1) {
						cout << "��ѡ����еĲ�����1�������軹��2����ͼ��ĸ߼�������q���˳���¼����" << endl;
						cin >> kk; cin.get();
						if (kk == '2') {
							Books book;
							while (1) {
								cout << "������Ҫ���еĲ�����1��ͼ�����ӣ�2��ͼ���޸ģ�3��ͼ���ѯ��4��ͳ�ƣ�q����һ������" << endl;
								char cc; cin >> cc; cin.get();
								switch (cc)
								{
								case '1':book.add_books(); break;//book.add_books(); break;
								case '2':book.modify_books(); break;
								case '3':book.check_info(); break;
								case '4':book.ststistic(); break;
								}
								if (cc == 'q' || cc == 'Q')break;
							}
						}
						else if(kk=='1'){
							char ch;
							while (1) {
								cout << "������Ҫ���еĲ�������1�����ģ�2���黹��3��������Ϣ�鿴��4��������Ϣ���޸ģ�q����һ����" << endl;
								char m; cin >> m; cin.get();
								switch (m)
								{
								case '1':reader.borrowBook(); break;
								case '2':reader.giveback(); break;
								case '3':reader.disBorr(); break;
								case '4':reader.modify_info(k); break;
								}
								if (m == 'q' || m == 'Q')break;
							}
						}
						if (kk == 'q' || kk == 'Q')break;
					}
				}
				else if (reader.type==4 && reader.power)       //ϵͳ����Ա�Ĳ���
				{
					//char k;
					while (1) {
						cout << "������Ҫ���еĲ�����1���û����ӣ�2���û�ɾ����3��Ȩ�޹���q���˳���¼����" << endl;
						char cc; cin >> cc; cin.get();
						switch (cc)
						{
						case '1':add_user(); break;
						case '2':delete_user(n); break;
						case '3':power_control(); break;
						}
						if (cc == 'Q' || cc == 'q')break;
					}
				}
				else if (reader.power == 0)
					{
						cout << "���������ƣ�����ϵ����Ա����Ȩ�ޣ�����" << endl;
					}
			}
			else {
				cout << "������󣡣���" << endl << endl;
			}
		}
		//cout << "������Ҫִ�еĲ�������1�����ģ�2���黹��" << endl;
		cout << "�����˳���¼....." << endl;
	}
	else if(k==0) //˵�������û�
	{
		cout << "�Ƿ���Ҫע���µ��û�������Y or N��" << endl;
		char ch; cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y')
		{
			char na[20],pass[20];
			cout << "�������û���:" << endl; cin >> na; cin.get();
			cout << "���������룺" << endl; cin >> pass; cin.get();
			cout << "ע��ɹ�������" << endl << endl;
			strcpy_s(reader.ID, 21, na); strcpy_s(reader.Password, 20, pass);
			ostringstream fout;
			fout.setf(ios_base::left, ios_base::adjustfield);
			fout << "�û�����"; fout.width(20); fout << na; fout << "  " << "���룺"; fout.width(20); fout << pass << "  " << "�û����ԣ�"; fout.width(5); fout << reader.type;
			fout << "  " << "Ȩ�ޣ�"; fout.width(6); fout << reader.power;
			fout << "  " << "��������Ŀ��"; fout.width(6); fout << reader.borrow_capasity;
			fout << "  " << "������������"; fout.width(6);fout << reader.max_days;
			fout << "  " << "�ѽ�����Ŀ��"; fout.width(6);fout << reader.borrowed;
			ofstream ffout; ffout.open(filename, ios::app | ios::out);
			cout << "���û���" << na << " �����ɣ���" << endl;
			ffout << fout.str().data() << endl; ffout.close();
			goto label;
			/*cout << "������Ҫ���еĲ�������1�����ģ�2���黹��3��������Ϣ�鿴��4��������Ϣ���޸ģ�" << endl;
			char m; cin >> m; cin.get();
			switch (m)
			{
			case '1':reader.borrowBook(op); break;
			case '2':reader.giveback(op); break;
			case '3':reader.disBorr(); break;
			case '4':reader.modify_info(k); break;
			}*/
		}
		else {
			cout << "********��ע���û�û�з���Ȩ�ޣ���********" << endl;
		}
	}
}
void OpLjw::mdy_book_stat(char* na, int k,int o)
{
	string re = reData("books/books.txt", na);
	//��ȡ��ͼ��ʣ������
	string name = re.substr(6, 20);
	string type = re.substr(34, 10);
	string number = re.substr(52, 6);
	//�ж��Ƿ���ĳɹ�
	if (o == 1) {
		if (stringToNum<int>(number) > 0)
		{
			ostringstream fout;
			fout << "���֣�"; fout.width(20); fout << name << "  " << "���ࣺ"; fout.width(10); fout << type;
			fout << "  " << "��棺"; fout.width(6); fout << stringToNum<int>(number) - 1;
			modifyContentInFile2("books/books.txt", k, fout.str().data());
			cout << na << " ���ĳɹ�����" << endl;
		}
	}
	else if (o == 2)
	{
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "���֣�"; fout.width(20); fout << name << "  " << "���ࣺ"; fout.width(10); fout << type;
		fout << "  " << "��棺"; fout.width(6); fout << stringToNum<int>(number) + 1;
		modifyContentInFileCount("books/books.txt", k, fout.str().data());
		cout << na << " �黹�ɹ�����" << endl;
	}
}
//***************************ϵͳ����Ա����***********************************
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
			strFileData += charToStr2(lineData);
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
void OpLjw::add_user()
{
	string filename; char na[20], pass[20]; int n,m;
	cout << "��ѡ��Ҫ��ӵ��û����ͣ�1��ѧ�����ߣ�2����ʦ���ߣ�3��ͼ�����Ա����" << endl; cin >> n; cin.get();
	ReaderLjw reader(n);
	cout << "��������Ҫ��ӵ��û� �û�����" << endl; cin >> na; cin.get(); strcpy_s(reader.ID, 20, na);
	cout << "��������Ҫ��ӵ��û� ���룺" << endl; cin >> pass; cin.get(); strcpy_s(reader.Password, 20, pass);
	//cout << "��������Ҫ��ӵ��û� ���ͣ�" << endl; cin >> reader.type; cin.get();
	if (reader.type == 1)
	{
		filename = "customer/student.txt";
	}
	else {
		filename = "customer/teacher.txt";
	}
	//�ж��û��Ƿ��ظ�
	int k = checkData5(filename.data(), na);
	if (k !=0)
	{
		cout << "�������������û������ظ�������" << endl;
	}
	else {
		//д���ļ��Ĳ���
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "�û�����"; fout.width(20); fout << na; fout << "  " << "���룺"; fout.width(20); fout << pass << "  " << "�û����ԣ�"; fout.width(5); fout << n;
		fout << "  " << "Ȩ�ޣ�"; fout.width(6); fout << reader.power;
		fout << "  " << "��������Ŀ��"; fout.width(6); fout << reader.borrow_capasity;
		fout << "  " << "������������"; fout.width(6);fout << reader.max_days;
		fout << "  " << "�ѽ�����Ŀ��"; fout.width(6);fout << reader.borrowed;
		ofstream ffout; ffout.open(filename, ios::app | ios::out);
		ffout << fout.str().data() << endl;
		cout << "���û���" << na << " �����ɣ���" << endl;
	}
}
//����Ա�Ƿ���û�й黹����
int check_noback(char* name)
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
			int k = checkData5(filen.data(), name);
			if (k != 0)  //��������
			{
				return 1;
			}
			in.close(); //�ر���
		}
	} while (_findnext(hFile, &fileInfo) == 0);
	return 0;
}
void OpLjw::delete_user(int n)
{
	ReaderLjw reader(n);
	char na[20]; string filename; int type;
	cout << "������Ҫɾ���� �û�����" << endl; cin >> na; cin.get();
	cout << "������Ҫɾ���� ���" << endl; cin >> type; cin.get();

	if (type == 1)
		filename = "customer/student.txt";
	else {
		filename = "customer/teacher.txt";
	}
	int k = checkData5(filename.data(), na);
	if (k == 0)cout << "�����ҵ��û������ڣ�����" << endl;
	else {
		//����û���δ�黹���飬�����־���

		if (check_noback(na)) { cout << "���û�������δ�黹���鼮��ɾ��ȡ��������" << endl; }
		else {
			DelLineData1(filename.data(), k);
			//ɾ��stastic�¶�Ӧ���ı��ļ�
			string sss = "DEL /f C:\\Users\\10918\\source\\repos\\ͼ�����ϵͳ\\ͼ�����ϵͳ\\statistic\\" + m_toStr4(na) + ".txt";
			//string sss = "DEL /f CUS\\" + Pna + ".txt";
			string sss1 = "DEL /f C:\\Users\\10918\\source\\repos\\ͼ�����ϵͳ\\ͼ�����ϵͳ\\statistic\\" + m_toStr4(na) + "back.txt";
			system(sss.data());
			system(sss1.data());
			cout << na << "  ����Ϣ�Ѿ�ɾ��������" << endl;
		}
	}
}
//����Ȩ�޹���ĺ���
void OpLjw::power_control()
{
	char na[20]; int type; string filename;
	string st, id, pa, typ, borrow_c, max_day, borr, po;
	cout << "��ѡ������Ҫ�޸�Ȩ�޵��û�����" << endl; cin >> na; cin.get();
	cout << "��ѡ������Ҫ�޸�Ȩ�޵����ࣺ" << endl; cin >> type; cin.get();
	if (type == 1)
		filename = "customer/student.txt";
	else {
		filename = "customer/teacher.txt";
	}
	int k = checkData5(filename.data(), na);
	st = reData(filename.data(), na);
	id = st.substr(8, 20);
	pa = st.substr(36, 20);
	typ = st.substr(68, 5);
	po = st.substr(81, 6);
	borrow_c = st.substr(103, 6);
	max_day = st.substr(125, 6);
	borr = st.substr(145, 6); trim5(id); trim5(pa); trim5(typ); trim5(po); trim5(borrow_c); trim5(max_day); trim5(borr);
	cout << "��������Ҫ�޸ĵĳ�Ȩ�ޣ���1����Ȩ��0������Ȩ��" << endl;
	cin >> po; cin.get();
	//����д�붫��
	ostringstream fout;
	fout.setf(ios_base::left, ios_base::adjustfield);
	fout << "�û�����"; fout.width(20); fout << id; fout << "  " << "���룺"; fout.width(20); fout << pa << "  " << "�û����ԣ�"; fout.width(5); fout << typ;
	fout << "  " << "Ȩ�ޣ�"; fout.width(6); fout << po;
	fout << "  " << "��������Ŀ��"; fout.width(6); fout << borrow_c;
	fout << "  " << "������������"; fout.width(6);fout << max_day;
	fout << "  " << "�ѽ�����Ŀ��"; fout.width(6);fout << borr << endl;
	modifyContentInFile2(filename.data(), k, fout.str().data());//stringToNum<char*>(ss.str())
	if (po == "0")cout << "�����ɹ��������� " << id << " ����Ϊ������" << endl;
	else cout << id << " �������ѽ��������" << endl;
}