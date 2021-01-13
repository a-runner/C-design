/*
真彩图转换成灰度图的改进版
（不把真彩图的每个像素点放入二维矩阵，而是读一行写一行）
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
#include"picture.h"
using namespace std;


int main()
{
    Picture pc("luna.bmp");
    pc.diaplay();

    return 0;
}
