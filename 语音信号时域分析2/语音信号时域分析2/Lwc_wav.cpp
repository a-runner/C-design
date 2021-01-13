#include <iostream>
#include <fstream>//open files
#include <string.h>
#include<math.h>
#include<cmath>//caculate
#include<stdlib.h>
#include<vector>
#include <bitset>
#include <iomanip>
#include "Lwc_wav.h"

using namespace std;

//读取之构造函数
Lwc_wav::Lwc_wav(const char* filename) {
    fstream fs;

    fs.open(filename, ios::binary | ios::in);
    if (!fs)
    {
        cout << "fail to open the file" << endl;
        system("pause");
    }
    else
    {
        cout << "open the file successfully" << endl;
    }

    fs.seekg(0x04);                //从文件数据中获取文件大小
    fs.read((char*)&file_size, sizeof(file_size));
    file_size += 8;

    fs.seekg(0x16);
    fs.read((char*)&channel, sizeof(channel));

    fs.seekg(0x18);
    fs.read((char*)&frequency, sizeof(frequency));

    fs.seekg(0x1c);
    fs.read((char*)&Bps, sizeof(Bps));

    fs.seekg(0x22);
    fs.read((char*)&sample_num_bit, sizeof(sample_num_bit));

    fs.seekg(0x4A);
    fs.read((char*)&data_size, sizeof(data_size));
    //printf("%d",data_size);
    data = new unsigned char[data_size];//数据指针在这儿
    fs.seekg(0x2c);
    fs.read((char*)data, sizeof(char) * data_size);

    printf("文件大小：%d\n", file_size);
    cout << "音频通道数  ：" << channel << endl;
    printf("采样频率：%d\n", frequency);
    printf("Byte率：%d\n", Bps);
    cout << "样本位数    ：" << sample_num_bit << endl;
    printf("音频数据大小：%d\n", data_size);
    /*cout << "文件大小为  ：" << file_size << endl;
    cout << "音频通道数  ：" << channel << endl;
    cout << "采样频率    ：" << frequency << endl;
    cout << "Byte率      ：" << Bps << endl;
    cout << "样本位数    ：" << sample_num_bit << endl;
    cout << "音频数据大小：" << data_size << endl;*/
    //cout << "最后10个数据：" << endl;

    bool is_1 = true; 
    for (unsigned long i = 0; i < data_size; i = i + 2)//十六字节为例
    {
        //右边为大端
        unsigned long data_low = data[i];
        unsigned long data_high = data[i + 1];
        double data_true = (data_high * 256) + data_low;//调换高低位
        long data_complement = 0;
        //取大端的最高位（符号位）
        int my_sign = (int)(data_high / 128);

        if (my_sign == 1) { data_complement = data_true - 65536; }//数据调转
        else { data_complement = data_true; }
        //printf("%d  ",data_complement);
        if (channel == 2) {
            if (is_1) {
                data0.push_back(double(data_complement));
                is_1 = false;
            }
            else {
                data1.push_back(double(data_complement));
                is_1 = true;
            }
        }
        else { 
            data0.push_back(double(data_complement)); 
            data1 = data0; 
        }//单声道相同
    }
    fs.close();
    //printf("声道对象完成分离重构");
    //cout << data0.size() << endl;
    cout << "数字化音频信号已载入" << endl;
    delete[] data;
}

Lwc_wav::~Lwc_wav() {

}