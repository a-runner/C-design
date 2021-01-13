#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"picture.h"
using namespace std;

Picture::Picture(const char* filename)
{
    /*�洢RGBͼ���һ�����ص�*/
    /*���Ҷ�ͼ�����ش浽һ��һά������*/
    unsigned char ImgData2[3000];
    int i, j, k;
    FILE* fpBMP, * fpGray;
    fileHeader* fh;
    fileInfo* fi;
    rgbq* fq;

    fopen_s(&fpBMP, "luna.bmp", "rb");
    /*if ((fopen_s(&fpBMP,"luna.bmp", "rb"))==NULL)
    {
        printf("���ļ�ʧ��");
        exit(0);
    }*/
    fopen_s(&fpGray, "Grayluna.bmp", "wb");
    /*if ((fopen_s(&fpGray,"Grayluna.bmp", "wb")) == NULL)
    {
        printf("�����ļ�ʧ��");
        exit(0);
    }*/
    fh = (fileHeader*)malloc(sizeof(fileHeader));
    fi = (fileInfo*)malloc(sizeof(fileInfo));
    if (fi->biBitCount <= 8) cout << "�ǻҶ�ͼ" << endl;
    else {
        //��ȡλͼͷ�ṹ����Ϣͷ
        fread(fh, sizeof(fileHeader), 1, fpBMP);
        fread(fi, sizeof(fileInfo), 1, fpBMP);
        //�޸�ͷ��Ϣ
        fi->biBitCount = 8;
        fi->biSizeImage = ((fi->biWidth * 3 + 3) / 4) * 4 * fi->biHeight;
        //fi->biClrUsed=256;
        width = fi->biWidth;
        height = fi->biHeight;
        fh->bfOffBits = sizeof(fileHeader) + sizeof(fileInfo) + 256 * sizeof(rgbq);
        fh->bfSize = fh->bfOffBits + fi->biSizeImage;

        //������ɫ��
        fq = (rgbq*)malloc(256 * sizeof(rgbq));
        for (i = 0; i < 256; i++)
        {
            fq[i].rgbBlue = fq[i].rgbGreen = fq[i].rgbRed = i;
            //fq[i].rgbReserved=0;
        }
        //��ͷ��Ϣд��
        fwrite(fh, sizeof(fileHeader), 1, fpGray);
        fwrite(fi, sizeof(fileInfo), 1, fpGray);
        fwrite(fq, sizeof(rgbq), 256, fpGray);
        //����ֱ��ͼ
        cout << "������Ҷ�ֵ��������" << endl;
        int  b; cin >> a; cin.get();double scale = 256 / a;
        //��ȡRGBͼ���ز�ת��Ϊ�Ҷ�ֵ
        for (i = 0; i < fi->biHeight; i++)
        {
            for (j = 0; j < (fi->biWidth + 3) / 4 * 4; j++)
            {
                for (k = 0; k < 3; k++)
                    fread(&ImgData[j][k], 1, 1, fpBMP);
            }
            for (j = 0; j < (fi->biWidth + 3) / 4 * 4; j++)
            {
                ImgData2[j] = int((float)ImgData[j][0] * 0.114 +
                    (float)ImgData[j][1] * 0.587 +
                    (float)ImgData[j][2] * 0.299);
                b = ImgData2[j] / scale;
                //cout << b << endl;
                gray[b]++;
            }
            //���Ҷ�ͼ��Ϣд��
            fwrite(ImgData2, j, 1, fpGray);
        }
        free(fh);
        free(fi);
        free(fq);
        fclose(fpBMP);
        fclose(fpGray);
        printf("success\n");
        //��ʼ����ֱ��ͼ
       /* for (int i = 0; i < a; i++)
        {
            cout << gray[i] << ":  ";
        }*/
    }
}
void star(int x)
{
    for (int i = 0; i < x; i++)
        cout << "*";
    cout << endl;
}
void Picture::diaplay()
{
    int size = height * ((width + 3) / 4 * 4);
    //cout << size;
    //ͳ��Ƶ��
    for (int i=0; i < a; i++)
    {
        gray[i] = (100*gray[i]) / size;
        //cout << gray[i] << endl;
    }
    //��ʼ����ֱ��ͼ
    for (int i = 0; i < a; i++)
    {
        cout << i << ":  ";
        star(gray[i]);
    }
}