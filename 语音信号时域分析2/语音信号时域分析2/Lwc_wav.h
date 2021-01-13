#pragma once
#pragma 
#ifndef LWC_WAV_H_
#include <iostream>
#include <fstream>//open files
#include <string.h>
#include<math.h>
#include<cmath>//caculate
#include<stdlib.h>
#include <bitset>
#include <iomanip>
#include<vector>

class Lwc_wav
{
public:
    std::vector<double> data0, data1;      //左右声道，单声道则相等
    unsigned long frequency;        //采样频率
    unsigned short sample_num_bit;    //一个样本的位数
    Lwc_wav(const char* filename);
    ~Lwc_wav();
private:
    unsigned char* data;       //音频数据 ,这里要定义什么就看样本位数了，我这里只是单纯的复制数据
    unsigned long file_size;        //文件大小
    unsigned short channel;            //通道数
    unsigned long Bps;                //Byte率
    unsigned long  data_size;        //数据大小
};
#endif // !LWC_WAV_H_

