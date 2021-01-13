#pragma once
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Complex
{
public:
	Complex(double r=0, double i=0);
	~Complex();
	//类函数声明
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator+=(const Complex&);
	Complex operator*=(const Complex&);
	Complex operator-=(const Complex&);
	Complex operator++();
	Complex operator--();

	//友元函数声明
	friend Complex operator*(int x, const Complex&);
	friend ostream& operator<<(ostream& os, const Complex& c);
	friend ofstream& operator<<(ofstream& os, const Complex& c);
	friend istream& operator>>(istream& is, Complex& c);
	double real;
	double imag;
};
bool operator>=(const Complex&, const Complex&);
bool operator<=(const Complex&, const Complex&);
bool operator==(const Complex&, const Complex&);
bool operator!=(const Complex&, const Complex&);

class Customer
{
public:
	string name;
	void input();
	void end();
	~Customer();
	Customer();
};
#endif // !COMPLEX_H_
