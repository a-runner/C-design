#pragma once
#ifndef STORE_H_
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Store
{
public:
	//会员资料的操作
	void check_name();   //按名字查询会员信息
	void modify_name();   //按名字修改会员信息
	void del_name();   //按名字删除会员信息
	int delete_info();   //删除会员购物信息  保留1年内记录
	void del_no_buy();  //删除 无垢面记录的会员
	//商品信息的操作
	void add_product();   //添加商品信息
	void modify_product();   //商品信息的修改
	void del_product();   //商品信息删除
	void check_product();  //商品查询
	void check_num_product(int a);  //查询 库存少于一定数量的商品
	// 按照时间地区统计

};
#endif // !STORE_H_
