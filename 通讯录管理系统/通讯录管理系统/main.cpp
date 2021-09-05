#include<iostream>
#include"contact.h"
using namespace std;


//�����б��
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

//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���
	if (abs->m_Size == Max) 
	{
		cout << "ͨѶ¼�������޷���ӣ�����" << endl;
	}
	else {
		//��Ӿ������ϵ��
		string name;
		cout << "������һ�������� " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "������������������!!" << endl;
			}
		}

		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;

		cout << "��ӳɹ�������" << endl;
		system("pause");
		system("cls");  //��������
	}
}

//��ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
	dashline();
	//�ж�ͨѶ¼�������Ƿ�Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	cout << "\n### ��������" << abs->m_Size << endl;
	dashline();
	system("pause");
	system("cls");   //����
}

//�����ϵ���Ƿ���ڣ��������򷵻���ϵ������ �����еľ���λ�ã����򷵻�-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
		{
			return i;   //�ҵ������±�
		}
	}
	return -1;
}
//ɾ��ָ������ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		//ƽ�ƺ��������
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "δ��¼���û�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(Addressbooks* abs) 
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;

	//�ж�һ��ָ������ϵ���Ƿ����
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int sex; int age; string  phone; string  addr;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������Ҫ�޸ĵ���Ϣ��ţ�1-������2-�Ա�3-���䣬4-�绰��5-סַ��" << endl;
		int add;
		cin >> add;
		switch (add) {
		case 1:
			cout << "������Ҫ�޸ĺ����֣� " << endl;
			cin >> name;
			abs->personArray[ret].m_Name = name;
			break;
		case 2:
			cout << "������Ҫ�޸ĺ��Ա�(1-�У�2-Ů)�� " << endl;
			cin >> sex;
			abs->personArray[ret].m_Sex = sex;
			break;
		case 3:
			cout << "������Ҫ�޸ĺ����䣺 " << endl;
			cin >> age;
			abs->personArray[ret].m_Age = age;
			break;
		case 4:
			cout << "������Ҫ�޸ĺ�绰�ţ� " << endl;
			cin >> phone;
			abs->personArray[ret].m_Phone = phone;
			break;
		case 5:
			cout << "������Ҫ�޸ĺ�סַ�� " << endl;
			cin >> addr;
			abs->personArray[ret].m_Addr = addr;
			break;
		}
		cout << "�޸ĳɹ�������" << endl;
	}
	else {
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
	line();
	line();
}

int main() {
	//ͨѶ¼�ṹ�����
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		//�˵�����
		showMenu();
		cin >> select;
		switch (select) {
		case 1:    //1.�����ϵ��
			addPerson(&abs);
			break;
		case 2:    //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:    //3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:    //4.������ϵ��
			findPerson(&abs);
			break;
		case 5:    //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:    //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:    //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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