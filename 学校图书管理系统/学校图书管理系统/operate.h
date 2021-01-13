#pragma once
#ifndef OPERATE_H_
#define OPERATE_H_
#include<iostream>
#include"User.h"
using namespace std;
class OpLjw
{
public:
	OpLjw();
	void log_in(int);
	void mdy_book_stat(char*, int,int);
	void stastic_borr(char*);
	void stastic_back(char*);
	void add_user();
	void delete_user(int);
	void power_control();
};
#endif // !1
