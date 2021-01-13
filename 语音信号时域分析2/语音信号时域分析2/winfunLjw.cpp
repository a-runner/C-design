#include <iostream>
#include <fstream>//open files
#include <string.h>
#include<math.h>
#include<cmath>//caculate
#include<stdlib.h>
#include <bitset>
#include <iomanip>
#include<vector>
#include "winfunLjw.h"
#define PI 3.1415926535897932
using namespace std;

Lwc_winfun::Lwc_winfun(double set_length, Wintype set_type,long fre) {
	//���δ�
	length = set_length;
	type = set_type;

	long len = set_length * fre;
	if (type == Rect) {
		for (int i = 0; i < len; i++) {
			params.push_back(1);
		}
	}
	//������
	if (type == Hanning) {
		for (int i = 0; i < len; i++) {
			params.push_back(0.5 - 0.5 * cos(2 * PI * i / (length - double(1))));
		}
	}
	//������
	if (type == Hanning) {
		for (int i = 0; i < len; i++) {
			params.push_back(0.54 - 0.46 * cos(2 * PI * i / (length - double(1))));
		}
	}
}
//�����ʱ����֡��vartΪƫ������T 10ms����targĿ����Ƶ��ɢ�źţ�freĿ���źŲ���Ƶ��
vector<vector<double>> Lwc_winfun::caculate(vector<double>targ, double vary1, double fre) {
	//����Ƿ�Խ��
	if (!targ[vary1 + length])cout << "ѡȡ��������ƫ�������󣡣�" << endl;
	unsigned long nx = targ.size();
	//����ƫ���� ��������
	//cout << vary1 << "  " << fre << endl;
	double vary = vary1 * double(fre);  //480
	//����ÿ�����ڲ��ж��ٸ�������
	unsigned long len = length * fre;  //
	//����֡��
	unsigned long nf = (nx - len + vary) / vary-1;
	//����һ����ά���� ֡��*���ڵ������õ���ʱ֡
	printf("Ŀ�������ĳ���������%d\n", nx);
	cout << "ƫ������"<<vary << endl;
	//printf("ƫ������%d\n", vary); 
	printf("ÿ�����ڲ��ĳ����㣺%d\n", len); 
	printf("֡����%d\n", nf);
	//cout << "Ŀ�������ĳ���������" << nx << endl;
	/*cout << "ƫ������" << vary << endl;
	cout << "ÿ�����ڲ��ĳ����㣺" << len << endl;
	cout << "֡����" << nf << endl;*/
	vector<vector<double>>rst(nf);
	//cout << vary * nf + len << endl;
	for (int i = 0; i < nf; i++) {
		//�ƴ�
		for (int j = 0; j < len; j++)
			rst[i].push_back(params[j] * targ[vary * i + j]);
	}
	return rst;
};
Lwc_winfun::~Lwc_winfun() {}