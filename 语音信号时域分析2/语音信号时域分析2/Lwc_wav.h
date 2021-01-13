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
    std::vector<double> data0, data1;      //���������������������
    unsigned long frequency;        //����Ƶ��
    unsigned short sample_num_bit;    //һ��������λ��
    Lwc_wav(const char* filename);
    ~Lwc_wav();
private:
    unsigned char* data;       //��Ƶ���� ,����Ҫ����ʲô�Ϳ�����λ���ˣ�������ֻ�ǵ����ĸ�������
    unsigned long file_size;        //�ļ���С
    unsigned short channel;            //ͨ����
    unsigned long Bps;                //Byte��
    unsigned long  data_size;        //���ݴ�С
};
#endif // !LWC_WAV_H_

