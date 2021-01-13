#pragma once
#ifndef PRODUCTLIUJW_H_
#define PRODUCTLIUJW_H_
#include <string>
#include <time.h>
using namespace std;

//������Ʒ��Ϣ product.txt
//�˿͹����¼�� customer.txt

char* getTime2();   //��ȡ��ǰʱ��

class Product_Ljw
{
private:
	int serial;   //��Ʒ���
	double in_price;  //����
	double out_price;  //�ۼ�
	int stock;    //���
	char provider[50];
	char time[64];  //ʱ��
	int buy_num;  //���������
	double sum;  //������
public:
	char name[25];  //��Ʒ����
	char type[20];  //��Ʒ����
	void insert(const char*);  //������Ʒ��¼���˿ͻ���̣�
	string display(double dis);   //�˵�ҳ�������Ʒ��Ϣ
	string display12(double dis);
	double total();   //���㵥����Ʒ�ܽ��
	Product_Ljw();   
	void add_pro();
	void reset(double dis);   //��ʼ����Աֵ
};
#endif // !PRODUCTLIUJW_H_

