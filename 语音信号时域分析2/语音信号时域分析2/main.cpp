#include<iostream>
#include<cmath>
#include<vector>
#include"Lwc_wav.h"
#include"winfunLjw.h"
using namespace std;


int sgn(double x)
{
	if (x >= 0)return 1;
	else return -1;
}
//定义一个计算短时语音帧时域参数
void anlysLjw(vector<vector<double>> rst)
{
	//获得二维数组大小 
	long size_row = rst.size();  //获取行数
	long size_col = rst[0].size();  //获取列数
	//cout << size_row << "  "<<size_col << endl;
	double egy, mnt, zo;
	vector<double>Egy; vector<double>Mnt; vector<long>zro;
	for (int i = 0; i < size_row; i++)
	{
		egy = 0, mnt = 0, zo = 0;
		for (int j = 0; j < size_col; j++)
		{
			egy += rst[i][j] * rst[i][j];
			mnt += abs(rst[i][j]);
			if (j < size_col - 1)zo += abs(sgn(rst[i][j + 1] - rst[i][j]));
		}
		Egy.push_back(egy); Mnt.push_back(mnt); zro.push_back(zo);
	}
	cout << endl << endl;
	cout << "下面即将显示时域参数：" << endl;
	double m_egy=0, m_mnt=0, m_zo=0;
	for (int i = 0; i < size_row; i++)
	{
		m_egy += Egy[i];
		m_mnt += Mnt[i];
		m_zo += zro[i];
	}
	cout << "开始显示时域统计信息：" << endl;
	cout << "平均短时能量：" << m_egy<<endl;
	cout << "平均短时幅度：" << m_mnt<<endl;
	cout << "平均短时过零：" << m_zo<<endl;
}
int main()
{
	Lwc_wav wav("test.wav");
	Lwc_winfun fun(0.02, Hanning,wav.frequency);
	vector<vector<double>> rst = fun.caculate(wav.data0, 0.01, wav.frequency);
	//long size_row = rst.size();  //获取行数
	//long size_col = rst[0].size();  //获取列数
	//cout << size_row << "  " << size_col << endl;
	anlysLjw(rst);
	//cout << fnl.Egy << endl << fnl.Mnt << endl << fnl.Zro << endl;
	system("pause");
	return 0;
}