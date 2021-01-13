#include<iostream>
#include <string>
#include<fstream>
#include<cmath>
#include <cstdlib>
#include"Complex.h"
using namespace std;
double total[3][2];
int c_add, c_sub, c_mul;
void init()   //记录最后三次测试的实部和虚部
{
    total[3][2] = 0;
}
void init_c()
{
    c_add = 0;
    c_sub = 0;
    c_mul = 0;
}

Complex::Complex(double r , double i) :real(r), imag(i)
{
};
Complex::~Complex()
{
}
Customer::Customer()
{
    init_c();
}
Customer::~Customer() 
{ 
    cout << "Bye!!  " << name << endl;
    for (int i = 0; i < 70; i++)
        cout << '*';
    cout << endl;
    //delete name; 
}
void Customer::end()
{
    ofstream fout(name + ".txt");
    fout << name << "(上次记录)：" << endl;
    fout << "总共加法次数：" << c_add << endl;
    fout << "总共减法次数：" << c_sub << endl;
    fout << "总共乘法次数：" << c_mul << endl;
    fout << "最后三次 乘法测试（一位数运算）的平均分：" << Complex(total[0][0] + total[1][0] + total[2][0], total[0][1] + total[1][1] + total[2][1]);
    fout << endl;
}
void Customer::input()
{
    init();
    cout << "请输入 用户名：" << endl;
    cin >> name;
    ifstream fin(name + ".txt", ios::in);
    char ch;
    fin >> ch;
    if (fin.eof())
    {
        cout << " 您好，新用户！！ " << endl;
    }
    else {
        cout << name << "，您好！！！\n下面为之前记录：" << endl << endl;;
        string s;
        while (getline(fin, s))
        {
            cout << s << endl;
        }
        cout << endl;
        fin.close();             //关闭文件输入流 
    }
}
//成员函数定义
Complex Complex::operator+(const Complex& a) 
{
    c_add++;
    return Complex(real + a.real, imag + a.imag);
}
Complex Complex::operator-(const Complex& a)
{
    c_sub++;
    return Complex(real - a.real, imag - a.imag);
}
Complex Complex::operator*(const Complex& a)
{
    c_mul++;
    return Complex(real * a.real - imag * a.imag, real * a.imag + imag * a.real);
}
Complex Complex::operator+=(const Complex& a)
{
    c_add++;
    return Complex(real + a.real, imag + a.imag);
}
Complex Complex::operator-=(const Complex& a) 
{
    c_sub++;
    return Complex(real - a.real, imag - a.imag);
}
Complex Complex::operator*=(const Complex& a) 
{
    c_mul++;
    return Complex(real * a.real - imag * a.imag, real * a.imag + imag * a.real);
}
Complex Complex::operator++() 
{
    c_add++;
    Complex a(1, 1);
    return Complex(real + a.real, imag + a.imag);
}
Complex Complex::operator--() 
{
    c_sub++;
    Complex a(1, 1);
    return Complex(real - a.real, imag - a.imag);
}
bool operator>=(const Complex& a,const Complex& b)
{
    return (pow(a.real, 2) + pow(a.imag, 2)) >= (pow(a.real, 2) + pow(a.imag, 2));
}
bool operator<=(const Complex& a, const Complex& b)
{
    return (pow(a.real, 2) + pow(a.imag, 2)) <= (pow(a.real, 2) + pow(a.imag, 2));
}
bool operator==(const Complex& a, const Complex& b)
{
    return (a.real == b.real && a.imag == b.imag) ? true : false;
}
bool operator!=(const Complex& a, const Complex& b)
{
    return (a.real != b.real || a.imag != b.imag) ? true : false;
}
ostream& operator<<(ostream& os, const Complex& c)
{
    os << c.real << "+" << c.imag << "i"; //以"a+bi"的形式输出
    return os;
}
//ofstream& operator<<(ofstream& os, const Complex& c)
//{
//    os << (c.real)/3 << "+" << (c.imag)/3 << "i"; //以"a+bi"的形式输出
//    return os;
//}
istream& operator>>(istream& is, Complex& c)
{
    string s;
    is >> s;  //将"a+bi"作为字符串读入, "a+bi" 中间不能有空格
    int pos1 = s.find("+", 0);
    int pos2 = s.find("-", 0);
    int pos3 = s.find("i", 0);
    if (pos1 != s.npos)
    {
        if (pos1 == 0)
        {
            c.real = 0;
            string sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //分离出代表虚部的字符串
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = atof(sTmp.c_str());
        }
        else
        {
            string sTmp = s.substr(0, pos1); //分离出代表实部的字符串
            c.real = atof(sTmp.c_str());//atof库函数能将const char*指针指向的内容转换成 float
            sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //分离出代表虚部的字符串
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = atof(sTmp.c_str());
        }
    }
    else if (pos2 != s.npos)
    {
        if (pos1 == 0)
        {
            c.real = 0;
            string sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //分离出代表虚部的字符串
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = 0-atof(sTmp.c_str());
        }
        else
        {
            string sTmp = s.substr(0, pos1); //分离出代表实部的字符串
            c.real = atof(sTmp.c_str());//atof库函数能将const char*指针指向的内容转换成 float
            sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //分离出代表虚部的字符串
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = 0-atof(sTmp.c_str());
        }
    }
    else if (pos3 == s.npos)
    {
        c.real = atof(s.c_str());
        c.imag = 0;
    }
    else {
        if (atof(s.c_str()) == 0)
            c.imag = 1;
        else c.imag = atof(s.c_str());
    }

    return is;
}
void queue_in(Complex& X)
{
    for (int i = 0; i < 2; i++)
    {
        total[i][0] = total[i + 1][0];
        total[i][1] = total[i + 1][1];
    }
    total[2][0] = X.real;
    total[2][1] = X.imag;
}
//友元函数定义
Complex operator*(int x, Complex& a)
{
    Complex X(x * a.real, x * a.imag);
    c_mul++;
    if (c_mul < 3)
    {
        total[c_mul][0] = X.real;
        total[c_mul][1] = X.imag;
    }
    else { queue_in(X); }
    return X;
}
