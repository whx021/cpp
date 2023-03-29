// 44、函数的分文件编写
// 4个步骤
// 1、创建后缀名为.h的头文件
// 2、创建后缀名为.cpp的源文件
// 3、在头文件中写函数的声明
// 4、在源文件中写函数的定义

#include <iostream>
using namespace std;
#include "swap.h"

// // 函数的声明
// void swap(int a, int b);

// // 函数的定义
// void swap(int a, int b) {
// int temp = a;
// a = b;
// b = temp;
// cout << "a = " << a << endl;
// cout << "b = " << b << endl;
// }

int main(void) {
	int a = 10; 
	int b = 20;
	swap(a, b);

	return 0;
}