// 43、函数的声明
// 告诉编译器函数的名称及如何调用函数，函数的实际主体可以单独定义
// 函数的声明可以有多次，但是函数的定义只有一次

#include <iostream>
using namespace std;

// 函数的声明
int max(int a, int b);
int max(int a, int b);
int max(int a, int b);

int main(void) {
	int a = 10;
	int b = 20;

	cout << max(a, b) << endl;

	// system("pause");
	return 0;
}

// 比较函数，对两个整型数字进行比较，返回较大的数
int max(int a, int b) {
	return a > b ? a : b;
}

// 函数的定义只有一次
// int max(int a, int b) {
// 	return a > b ? a : b;
// }