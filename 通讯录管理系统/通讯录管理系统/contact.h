#pragma once
#ifndef CONTACT_H_
#define CONTACT_H_
#include<string>
#include<iostream>
using namespace std;
#define Max 100


struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};


//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼����ϵ������
	Person personArray[Max];
	//��ǰ��ϵ�˸���
	int m_Size;
};

#endif