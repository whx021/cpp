#include <iostream>
using namespace std;

int main(void) {
	// 加减乘除
	int a1 = 10;
	int b1 = 3;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;	// 两个整型相除，仍是整数，小数部分舍去

	int a2 = 10, b2 = 20;
	cout << a2 / b2 << endl;

	int a3 = 10, b3 = 0;
	// cout << a3 / b3 << endl;	// 错误：除数不能为0

	// 两个小数相除
	double d1 = 0.5, d2 = 0.25;
	cout << d1 / d2 << endl;	// 运算的结果也可以是小数


	// 取模、取余运算——求余数，只有整型变量能做取模运算
	int a4 = 10, b4 = 3;
	cout << a4 % b4 << endl;
	
	int a5 = 10, b5 = 20;
	cout << a5 % b5 << endl;

	int a6 = 10, b6 = 0;
	cout << a6 % b6 << endl;	// 错误：除数不能为0,所以也做不了取模运算

	// 错误两个小数是不可以做取模运算的
	double d3 = 3.14, d4 = 1.1;
	// cout << d3 % d4 << endl;

	// system("pause");
	return 0;
}