#pragma once
#ifndef CONTACT_H_
#define CONTACT_H_
#include<string>
#include<iostream>
using namespace std;
#define Max 100


struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};


//设计通讯录结构体
struct Addressbooks
{
	//通讯录中联系人数组
	Person personArray[Max];
	//当前联系人个数
	int m_Size;
};

#endif