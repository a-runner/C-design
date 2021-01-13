#pragma once
#ifndef WINFUNLJW_H_
#define WINFUNLJW_H_
#include<vector>
using namespace std;
enum Wintype {
	Rect, Hanning, Hamming
};
class Lwc_winfun
{
public:
	vector<vector<double>> caculate(vector<double>targ, double vary, double fre);
	//构造函数参数为窗长（例如20ms） set_type:窗类型
	Lwc_winfun(double set_length, Wintype set_type,long fre);
	~Lwc_winfun();
protected:
	double length;
	Wintype type;
private:
	vector<double> params;
};
#endif // !WINFUNLJW_H_
