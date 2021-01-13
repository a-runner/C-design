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
	int power;  //相关权限
	int borrow_capasity;  //最大借阅数目
	int max_days;   //最大借阅天数
	int borrowed;   //已借阅数目
	char ID[20];  //用户名
	char Password[20];  // 密码
};
#endif
