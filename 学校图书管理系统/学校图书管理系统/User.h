#pragma once
#ifndef USER_H_
#define USER_H_
#include<string>
#include"operate.h"
using namespace std;
class ReaderLjw
{
public:
	ReaderLjw(int t);
	ReaderLjw();
	~ReaderLjw();
	void modify_info(int k);
	void renew_user();
	void mdy_book(char*,int,int);
	void giveback();
	void borrowBook();
	void disBorr();
	int type;
	int power;  //���Ȩ��
	int borrow_capasity;  //��������Ŀ
	int max_days;   //����������
	int borrowed;   //�ѽ�����Ŀ
	char ID[20];  //�û���
	char Password[20];  // ����
};
#endif
