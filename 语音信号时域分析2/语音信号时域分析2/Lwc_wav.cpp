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

//��ȡ֮���캯��
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

    fs.seekg(0x04);                //���ļ������л�ȡ�ļ���С
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
    data = new unsigned char[data_size];//����ָ�������
    fs.seekg(0x2c);
    fs.read((char*)data, sizeof(char) * data_size);

    printf("�ļ���С��%d\n", file_size);
    cout << "��Ƶͨ����  ��" << channel << endl;
    printf("����Ƶ�ʣ�%d\n", frequency);
    printf("Byte�ʣ�%d\n", Bps);
    cout << "����λ��    ��" << sample_num_bit << endl;
    printf("��Ƶ���ݴ�С��%d\n", data_size);
    /*cout << "�ļ���СΪ  ��" << file_size << endl;
    cout << "��Ƶͨ����  ��" << channel << endl;
    cout << "����Ƶ��    ��" << frequency << endl;
    cout << "Byte��      ��" << Bps << endl;
    cout << "����λ��    ��" << sample_num_bit << endl;
    cout << "��Ƶ���ݴ�С��" << data_size << endl;*/
    //cout << "���10�����ݣ�" << endl;

    bool is_1 = true; 
    for (unsigned long i = 0; i < data_size; i = i + 2)//ʮ���ֽ�Ϊ��
    {
        //�ұ�Ϊ���
        unsigned long data_low = data[i];
        unsigned long data_high = data[i + 1];
        double data_true = (data_high * 256) + data_low;//�����ߵ�λ
        long data_complement = 0;
        //ȡ��˵����λ������λ��
        int my_sign = (int)(data_high / 128);

        if (my_sign == 1) { data_complement = data_true - 65536; }//���ݵ�ת
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
        }//��������ͬ
    }
    fs.close();
    //printf("����������ɷ����ع�");
    //cout << data0.size() << endl;
    cout << "���ֻ���Ƶ�ź�������" << endl;
    delete[] data;
}

Lwc_wav::~Lwc_wav() {

}