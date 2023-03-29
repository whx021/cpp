// 40、函数
// 将一段经常使用的代码封装起来，减少重复使用
// 一个较大的程序，一般分为若干个程序块，每个每块实现特定的功能

// 函数的定义
// 1、返回值类型
// 2、函数名
// 3、参数列表
// 4、函数体语句
// 5、return语句

#include <iostream>
using namespace std;

// 函数定义时，num1，num2没有实际值，是一个形式上的参数，简称形参
int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

int main(void) {
	// main函数中调用add函数
	int a = 10, b = 20;
	// a，b称为实际参数，简称实参
	// 当函数调用时，实参的值会传递给形参
	int c = add(a, b);
	cout << "c = " << c << endl;

	// system("pause");
	return 0;
}