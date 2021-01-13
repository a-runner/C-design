#include<iostream>
#include <cstdlib>
#include<ctime>
#include"Complex.h"
#define random(a,b) (rand()%(b-a)+a)
using namespace std;

//定义4个菜单函数
Complex c_add(Complex& a, Complex& b)
{
	return a + b;
}
Complex c_sub(Complex& a, Complex& b)
{
	return a - b;
}
Complex c_mul(Complex& a, Complex& b)
{
	return a * b;
}
void compute_test()
{
	cout << "计算机会随机出10道运算题，请用户输入对应答案：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << rand() % 100 << " ";
	}
}
void input_num(double* num)
{
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	cin.get();
}
int main()
{
	char re;
	double num[4];
	while (true)
	{
		Customer cus;
		cus.input();
		cout << "请输入想要进行的运算（1-加法，2-减法，3-乘法，4-测试题,q-退出）：" << endl;
		cin >> re;
		cin.get();
		while (re != 'q')
		{
			Complex x, y;
			switch (re) {
			case '1':
				cout << "请输入两个运算复数：" << endl;
				cin >> x >> y;
				cout << "X: " << x << "Y: " << y << endl;
				cout << "运算：" << x.real << " + " << x.imag << "i  " << " + " << y.real << " + " << y.imag << "i " << '=' << x+y << endl;
				break;
			case '2':
				cin >> x >> y;
				cout << "X: " << x << "Y: " << y << endl;
				cout << "运算：" << x.real << " + " << x.imag << "i  " << " - " << y.real << " + " << y.imag << "i " << '=' << x - y << endl;
				break;
			case '3':
				cin >> x >> y;
				cout << "X: " << x << "Y: " << y << endl;
				cout << "运算：" << x.real << " + " << x.imag << "i  " << " * " << y.real << " + " << y.imag << "i " << '=' << x * y << endl;
				break;
			case '4':
				cout << "开始随机出题，请认真做答！！" << endl;
				int a = 0;
				int right;
				srand((int)time(0));  // 产生随机种子  把0换成NULL也行
				for (int i = 0; i < 10; i++)
				{
					a = rand() % 4;  //产生需要进行的运算
					for (int i = 0; i < 4; i++)
						num[i] = random(0, 100);
					Complex C(0, 0);
					switch (a) {
					case 1:input_num(num);
						cout << "运算：" << num[0] << ' + ' << num[1] << 'i  ' << ' + ' << num[2] << ' + ' << num[3] << 'i ' << '=' << '?' << endl;
						cin>>C;
						if (C == (Complex(num[0], num[1]) + Complex(num[2], num[3])))
							right++;
					case 2:input_num(num);
						cout << "运算：" << num[0] << ' + ' << num[1] << 'i  ' << ' - ' << num[2] << ' + ' << num[3] << 'i ' << '=' << '?' << endl;
						cout << C;
						if (C == (Complex(num[0], num[1]) - Complex(num[2], num[3])))
							right++;
					case 3:input_num(num);
						cout << "运算：" << num[0] << ' + ' << num[1] << 'i  ' << ' * ' << num[2] << ' + ' << num[3] << 'i ' << '=' << '?' << endl;
						cout << C;
						if (C == (Complex(num[0], num[1]) * Complex(num[2], num[3])))
							right++;
					}
				}
				cout << "正答率：" << right * 10 <<'%'<< endl;
			}
			cout << "请输入想要进行的运算（1-加法，2-减法，3-乘法，4-测试题,q-退出）：" << endl;
			cin >> re;
		}
		cus.end();
	}
	return 0;
}