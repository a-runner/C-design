#pragma once
#ifndef STORE_H_
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Store
{
public:
	//��Ա���ϵĲ���
	void check_name();   //�����ֲ�ѯ��Ա��Ϣ
	void modify_name();   //�������޸Ļ�Ա��Ϣ
	void del_name();   //������ɾ����Ա��Ϣ
	int delete_info();   //ɾ����Ա������Ϣ  ����1���ڼ�¼
	void del_no_buy();  //ɾ�� �޹����¼�Ļ�Ա
	//��Ʒ��Ϣ�Ĳ���
	void add_product();   //�����Ʒ��Ϣ
	void modify_product();   //��Ʒ��Ϣ���޸�
	void del_product();   //��Ʒ��Ϣɾ��
	void check_product();  //��Ʒ��ѯ
	void check_num_product(int a);  //��ѯ �������һ����������Ʒ
	// ����ʱ�����ͳ��

};
#endif // !STORE_H_
