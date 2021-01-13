#include<iostream>
#include <string>
#include<fstream>
#include<cmath>
#include <cstdlib>
#include"Complex.h"
using namespace std;
double total[3][2];
int c_add, c_sub, c_mul;
void init()   //��¼������β��Ե�ʵ�����鲿
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
    fout << name << "(�ϴμ�¼)��" << endl;
    fout << "�ܹ��ӷ�������" << c_add << endl;
    fout << "�ܹ�����������" << c_sub << endl;
    fout << "�ܹ��˷�������" << c_mul << endl;
    fout << "������� �˷����ԣ�һλ�����㣩��ƽ���֣�" << Complex(total[0][0] + total[1][0] + total[2][0], total[0][1] + total[1][1] + total[2][1]);
    fout << endl;
}
void Customer::input()
{
    init();
    cout << "������ �û�����" << endl;
    cin >> name;
    ifstream fin(name + ".txt", ios::in);
    char ch;
    fin >> ch;
    if (fin.eof())
    {
        cout << " ���ã����û����� " << endl;
    }
    else {
        cout << name << "�����ã�����\n����Ϊ֮ǰ��¼��" << endl << endl;;
        string s;
        while (getline(fin, s))
        {
            cout << s << endl;
        }
        cout << endl;
        fin.close();             //�ر��ļ������� 
    }
}
//��Ա��������
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
    os << c.real << "+" << c.imag << "i"; //��"a+bi"����ʽ���
    return os;
}
//ofstream& operator<<(ofstream& os, const Complex& c)
//{
//    os << (c.real)/3 << "+" << (c.imag)/3 << "i"; //��"a+bi"����ʽ���
//    return os;
//}
istream& operator>>(istream& is, Complex& c)
{
    string s;
    is >> s;  //��"a+bi"��Ϊ�ַ�������, "a+bi" �м䲻���пո�
    int pos1 = s.find("+", 0);
    int pos2 = s.find("-", 0);
    int pos3 = s.find("i", 0);
    if (pos1 != s.npos)
    {
        if (pos1 == 0)
        {
            c.real = 0;
            string sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //����������鲿���ַ���
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = atof(sTmp.c_str());
        }
        else
        {
            string sTmp = s.substr(0, pos1); //���������ʵ�����ַ���
            c.real = atof(sTmp.c_str());//atof�⺯���ܽ�const char*ָ��ָ�������ת���� float
            sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //����������鲿���ַ���
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
            string sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //����������鲿���ַ���
            if (atof(sTmp.c_str()) == 0)
                c.imag = 1;
            else c.imag = 0-atof(sTmp.c_str());
        }
        else
        {
            string sTmp = s.substr(0, pos1); //���������ʵ�����ַ���
            c.real = atof(sTmp.c_str());//atof�⺯���ܽ�const char*ָ��ָ�������ת���� float
            sTmp = s.substr(pos1 + 1, s.length() - pos1 - 2);   //����������鲿���ַ���
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
//��Ԫ��������
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
