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
	//矩形窗
	length = set_length;
	type = set_type;

	long len = set_length * fre;
	if (type == Rect) {
		for (int i = 0; i < len; i++) {
			params.push_back(1);
		}
	}
	//汉宁窗
	if (type == Hanning) {
		for (int i = 0; i < len; i++) {
			params.push_back(0.5 - 0.5 * cos(2 * PI * i / (length - double(1))));
		}
	}
	//汉明窗
	if (type == Hanning) {
		for (int i = 0; i < len; i++) {
			params.push_back(0.54 - 0.46 * cos(2 * PI * i / (length - double(1))));
		}
	}
}
//计算短时语音帧，vart为偏移量（T 10ms），targ目标音频离散信号，fre目标信号采样频率
vector<vector<double>> Lwc_winfun::caculate(vector<double>targ, double vary1, double fre) {
	//检测是否越界
	if (!targ[vary1 + length])cout << "选取窗函数和偏移量过大！！" << endl;
	unsigned long nx = targ.size();
	//计算偏移量 四舍五入
	//cout << vary1 << "  " << fre << endl;
	double vary = vary1 * double(fre);  //480
	//计算每个窗内部有多少个抽样点
	unsigned long len = length * fre;  //
	//计算帧数
	unsigned long nf = (nx - len + vary) / vary-1;
	//定义一个二维数组 帧数*窗内点数，得到短时帧
	printf("目标语音的抽样点数：%d\n", nx);
	cout << "偏移量："<<vary << endl;
	//printf("偏移量：%d\n", vary); 
	printf("每个窗内部的抽样点：%d\n", len); 
	printf("帧数：%d\n", nf);
	//cout << "目标语音的抽样点数：" << nx << endl;
	/*cout << "偏移量：" << vary << endl;
	cout << "每个窗内部的抽样点：" << len << endl;
	cout << "帧数：" << nf << endl;*/
	vector<vector<double>>rst(nf);
	//cout << vary * nf + len << endl;
	for (int i = 0; i < nf; i++) {
		//移窗
		for (int j = 0; j < len; j++)
			rst[i].push_back(params[j] * targ[vary * i + j]);
	}
	return rst;
};
Lwc_winfun::~Lwc_winfun() {}