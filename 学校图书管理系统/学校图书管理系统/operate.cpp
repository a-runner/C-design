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
	//首先产看state_data/stastic_data.txt有没有na，没有的话再添加
	int k = checkData5("state_data/stastic_data.txt", na);
	if (k != 0)   //该图书在记录中
	{
		string re = reData("state_data/stastic_data.txt", na);
		//提取分量
		string name = re.substr(6, 20);
		string num = re.substr(34, 6);
		string borr = re.substr(50, 6);
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "名字：" << setw(20) << name << "  " << "库存：" << setw(6) << stringToNum<int>(num) << "  " << "在借阅：" << setw(6) << stringToNum<int>(borr) + 1;

		modifyContentInFile2("state_data/stastic_data.txt", k, fout.str().data());
	}
	else {
		ofstream fout;
		fout.open("state_data/stastic_data.txt", ios::app | ios::out);
		string re = reData("books/books.txt", na);
		//提取该图书剩余数量
		string name = re.substr(6, 20);
		string type = re.substr(34, 10);
		string number = re.substr(52, 6);
		ostringstream ffout;
		ffout << "名字：" << setw(20) << name << "  " << "库存：" << setw(6) << stringToNum<int>(number) << "  " << "在借阅：" << setw(6) <<  '1';
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << ffout.str().data();
		fout.close();
	}
}
void OpLjw::stastic_back(char* na)
{
	int k = checkData5("state_data/stastic_data.txt", na);
	string re = reData("state_data/stastic_data.txt", na);
	//提取分量
	string name = re.substr(6, 20);
	string num = re.substr(34, 6);
	string borr = re.substr(50, 6);
	ostringstream fout;
	fout << "名字：" << setw(20) << name << "  " << "库存：" << setw(6) << stringToNum<int>(num) + 1 << "  " << "在借阅：" << setw(6) << stringToNum<int>(borr) - 1;
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
	cout << "请输入用户名：" << endl;
	cin >> ID; cin.get(); 
	if (reader.type == 1)  //选择需要打开的文本文件
		filename = "customer/student.txt";
	else 
		filename = "customer/teacher.txt";
	string st, id, pa, typ, borrow_c, max_day, borr,po;
	//k = checkData5(stringToNum<char*>(filename), stringToNum<char*>(ID));
	k = checkData5(filename.data(), ID.data());
	if (k != 0)   //说明是老用户
	{
		//显示用户信息
		st = reData(filename.data(), ID.data());
		cout << endl << "欢迎 "<<ID<<" !!!" << endl;
		cout << "请输入密码：" << endl; cin >> pass; cin.get();
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
			if (pass==pa)  //说明为老用户
			{
			label: 
					k = checkData5(filename.data(), ID.data());
					if ((reader.type == 1 || reader.type == 2)&& reader.power) {
					char ch;
					while (1) {
						cout << "请输入要进行的操作：（1—借阅，2—归还，3—借阅信息查看，4—个人信息的修改，q—退出登录）" << endl;
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
				else if (reader.type == 3 && reader.power)  //图书管理员的操作
				{
					char kk;
					while (1) {
						cout << "请选择进行的操作（1—正常借还，2—对图书的高级操作，q—退出登录）：" << endl;
						cin >> kk; cin.get();
						if (kk == '2') {
							Books book;
							while (1) {
								cout << "请输入要进行的操作（1—图书增加，2—图书修改，3—图书查询，4—统计，q—上一步）：" << endl;
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
								cout << "请输入要进行的操作：（1—借阅，2—归还，3—借阅信息查看，4—个人信息的修改，q—上一步）" << endl;
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
				else if (reader.type==4 && reader.power)       //系统管理员的操作
				{
					//char k;
					while (1) {
						cout << "请输入要进行的操作（1—用户增加，2—用户删除，3—权限管理，q—退出登录）：" << endl;
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
						cout << "访问受限制，请联系管理员更改权限！！！" << endl;
					}
			}
			else {
				cout << "密码错误！！！" << endl << endl;
			}
		}
		//cout << "请输入要执行的操作：（1—借阅，2—归还）" << endl;
		cout << "正在退出登录....." << endl;
	}
	else if(k==0) //说明是新用户
	{
		cout << "是否需要注册新的用户名？（Y or N）" << endl;
		char ch; cin >> ch; cin.get();
		if (ch == 'Y' || ch == 'y')
		{
			char na[20],pass[20];
			cout << "请输入用户名:" << endl; cin >> na; cin.get();
			cout << "请输入密码：" << endl; cin >> pass; cin.get();
			cout << "注册成功！！！" << endl << endl;
			strcpy_s(reader.ID, 21, na); strcpy_s(reader.Password, 20, pass);
			ostringstream fout;
			fout.setf(ios_base::left, ios_base::adjustfield);
			fout << "用户名："; fout.width(20); fout << na; fout << "  " << "密码："; fout.width(20); fout << pass << "  " << "用户属性："; fout.width(5); fout << reader.type;
			fout << "  " << "权限："; fout.width(6); fout << reader.power;
			fout << "  " << "最大借阅数目："; fout.width(6); fout << reader.borrow_capasity;
			fout << "  " << "最大借阅天数："; fout.width(6);fout << reader.max_days;
			fout << "  " << "已借阅数目："; fout.width(6);fout << reader.borrowed;
			ofstream ffout; ffout.open(filename, ios::app | ios::out);
			cout << "新用户：" << na << " 添加完成！！" << endl;
			ffout << fout.str().data() << endl; ffout.close();
			goto label;
			/*cout << "请输入要进行的操作：（1—借阅，2—归还，3—借阅信息查看，4—个人信息的修改）" << endl;
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
			cout << "********非注册用户没有访问权限！！********" << endl;
		}
	}
}
void OpLjw::mdy_book_stat(char* na, int k,int o)
{
	string re = reData("books/books.txt", na);
	//提取该图书剩余数量
	string name = re.substr(6, 20);
	string type = re.substr(34, 10);
	string number = re.substr(52, 6);
	//判断是否借阅成功
	if (o == 1) {
		if (stringToNum<int>(number) > 0)
		{
			ostringstream fout;
			fout << "名字："; fout.width(20); fout << name << "  " << "种类："; fout.width(10); fout << type;
			fout << "  " << "库存："; fout.width(6); fout << stringToNum<int>(number) - 1;
			modifyContentInFile2("books/books.txt", k, fout.str().data());
			cout << na << " 借阅成功！！" << endl;
		}
	}
	else if (o == 2)
	{
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "名字："; fout.width(20); fout << name << "  " << "种类："; fout.width(10); fout << type;
		fout << "  " << "库存："; fout.width(6); fout << stringToNum<int>(number) + 1;
		modifyContentInFileCount("books/books.txt", k, fout.str().data());
		cout << na << " 归还成功！！" << endl;
	}
}
//***************************系统管理员操作***********************************
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

	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out << strFileData;
	out.close();
}
void OpLjw::add_user()
{
	string filename; char na[20], pass[20]; int n,m;
	cout << "请选择要添加的用户类型（1—学生读者，2—老师读者，3—图书管理员）：" << endl; cin >> n; cin.get();
	ReaderLjw reader(n);
	cout << "请输入想要添加的用户 用户名：" << endl; cin >> na; cin.get(); strcpy_s(reader.ID, 20, na);
	cout << "请输入想要添加的用户 密码：" << endl; cin >> pass; cin.get(); strcpy_s(reader.Password, 20, pass);
	//cout << "请输入想要添加的用户 类型：" << endl; cin >> reader.type; cin.get();
	if (reader.type == 1)
	{
		filename = "customer/student.txt";
	}
	else {
		filename = "customer/teacher.txt";
	}
	//判断用户是否重复
	int k = checkData5(filename.data(), na);
	if (k !=0)
	{
		cout << "输入错误，输入的用户名有重复！！！" << endl;
	}
	else {
		//写入文件的操作
		ostringstream fout;
		fout.setf(ios_base::left, ios_base::adjustfield);
		fout << "用户名："; fout.width(20); fout << na; fout << "  " << "密码："; fout.width(20); fout << pass << "  " << "用户属性："; fout.width(5); fout << n;
		fout << "  " << "权限："; fout.width(6); fout << reader.power;
		fout << "  " << "最大借阅数目："; fout.width(6); fout << reader.borrow_capasity;
		fout << "  " << "最大借阅天数："; fout.width(6);fout << reader.max_days;
		fout << "  " << "已借阅数目："; fout.width(6);fout << reader.borrowed;
		ofstream ffout; ffout.open(filename, ios::app | ios::out);
		ffout << fout.str().data() << endl;
		cout << "新用户：" << na << " 添加完成！！" << endl;
	}
}
//检查会员是否有没有归还的书
int check_noback(char* name)
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
			int k = checkData5(filen.data(), name);
			if (k != 0)  //含有数据
			{
				return 1;
			}
			in.close(); //关闭流
		}
	} while (_findnext(hFile, &fileInfo) == 0);
	return 0;
}
void OpLjw::delete_user(int n)
{
	ReaderLjw reader(n);
	char na[20]; string filename; int type;
	cout << "请输入要删除的 用户名：" << endl; cin >> na; cin.get();
	cout << "请输入要删除的 类别：" << endl; cin >> type; cin.get();

	if (type == 1)
		filename = "customer/student.txt";
	else {
		filename = "customer/teacher.txt";
	}
	int k = checkData5(filename.data(), na);
	if (k == 0)cout << "所查找的用户不存在！！！" << endl;
	else {
		//如果用户有未归还的书，将出现警告

		if (check_noback(na)) { cout << "该用户还含有未归还的书籍，删除取消！！！" << endl; }
		else {
			DelLineData1(filename.data(), k);
			//删除stastic下对应的文本文件
			string sss = "DEL /f C:\\Users\\10918\\source\\repos\\图书管理系统\\图书管理系统\\statistic\\" + m_toStr4(na) + ".txt";
			//string sss = "DEL /f CUS\\" + Pna + ".txt";
			string sss1 = "DEL /f C:\\Users\\10918\\source\\repos\\图书管理系统\\图书管理系统\\statistic\\" + m_toStr4(na) + "back.txt";
			system(sss.data());
			system(sss1.data());
			cout << na << "  的信息已经删除！！！" << endl;
		}
	}
}
//定义权限管理的函数
void OpLjw::power_control()
{
	char na[20]; int type; string filename;
	string st, id, pa, typ, borrow_c, max_day, borr, po;
	cout << "请选择您想要修改权限的用户名：" << endl; cin >> na; cin.get();
	cout << "请选择您想要修改权限的种类：" << endl; cin >> type; cin.get();
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
	cout << "请输入想要修改的成权限？（1—授权，0—不授权）" << endl;
	cin >> po; cin.get();
	//构造写入东西
	ostringstream fout;
	fout.setf(ios_base::left, ios_base::adjustfield);
	fout << "用户名："; fout.width(20); fout << id; fout << "  " << "密码："; fout.width(20); fout << pa << "  " << "用户属性："; fout.width(5); fout << typ;
	fout << "  " << "权限："; fout.width(6); fout << po;
	fout << "  " << "最大借阅数目："; fout.width(6); fout << borrow_c;
	fout << "  " << "最大借阅天数："; fout.width(6);fout << max_day;
	fout << "  " << "已借阅数目："; fout.width(6);fout << borr << endl;
	modifyContentInFile2(filename.data(), k, fout.str().data());//stringToNum<char*>(ss.str())
	if (po == "0")cout << "操作成功，将限制 " << id << " 的行为！！！" << endl;
	else cout << id << " 的限制已解除！！！" << endl;
}