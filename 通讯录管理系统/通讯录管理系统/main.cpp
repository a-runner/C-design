#include<iostream>
#include"contact.h"
using namespace std;


//输出画斜线
void line() {
	for (int i = 0; i < 70; i++)
		cout << '-';
	cout << endl;
}
void dashline() {
	for (int i = 0; i < 50; i++)
		cout << "-|";
	cout << endl;
}

//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满
	if (abs->m_Size == Max) 
	{
		cout << "通讯录已满，无法添加！！！" << endl;
	}
	else {
		//添加具体的联系人
		string name;
		cout << "请输入一个姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入!!" << endl;
			}
		}

		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;

		cout << "添加成功！！！" << endl;
		system("pause");
		system("cls");  //清屏操作
	}
}

//显示所有联系人
void showPerson(Addressbooks* abs)
{
	dashline();
	//判断通讯录中人数是否为零
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	cout << "\n### 总人数：" << abs->m_Size << endl;
	dashline();
	system("pause");
	system("cls");   //清屏
}

//检测联系人是否存在，若存在则返回联系人所在 数组中的具体位置，否则返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
		{
			return i;   //找到数组下标
		}
	}
	return -1;
}
//删除指定的联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		//平移后面的数据
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  //更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else {
		cout << "未记录该用户" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbooks* abs) 
{
	cout << "请输入您要查找的联系人： " << endl;
	string name;
	cin >> name;

	//判断一下指定的联系人是否存在
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改的联系人： " << endl;
	string name;
	cin >> name;
	int sex; int age; string  phone; string  addr;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "请输入要修改的信息编号（1-姓名，2-性别，3-年龄，4-电话，5-住址）" << endl;
		int add;
		cin >> add;
		switch (add) {
		case 1:
			cout << "请输入要修改后名字： " << endl;
			cin >> name;
			abs->personArray[ret].m_Name = name;
			break;
		case 2:
			cout << "请输入要修改后性别(1-男，2-女)： " << endl;
			cin >> sex;
			abs->personArray[ret].m_Sex = sex;
			break;
		case 3:
			cout << "请输入要修改后年龄： " << endl;
			cin >> age;
			abs->personArray[ret].m_Age = age;
			break;
		case 4:
			cout << "请输入要修改后电话号： " << endl;
			cin >> phone;
			abs->personArray[ret].m_Phone = phone;
			break;
		case 5:
			cout << "请输入要修改后住址： " << endl;
			cin >> addr;
			abs->personArray[ret].m_Addr = addr;
			break;
		}
		cout << "修改成功！！！" << endl;
	}
	else {
		cout << "未找到来联系人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
//菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
	line();
	line();
}

int main() {
	//通讯录结构体变量
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		//菜单调用
		showMenu();
		cin >> select;
		switch (select) {
		case 1:    //1.添加联系人
			addPerson(&abs);
			break;
		case 2:    //2.显示联系人
			showPerson(&abs);
			break;
		case 3:    //3.删除联系人
			deletePerson(&abs);
			break;
		case 4:    //4.查找联系人
			findPerson(&abs);
			break;
		case 5:    //5.修改联系人
			modifyPerson(&abs);
			break;
		case 6:    //6.清空联系人
			cleanPerson(&abs);
			break;
		case 0:    //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}