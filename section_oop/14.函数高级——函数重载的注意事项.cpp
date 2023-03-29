// 函数能够发生重载的核心思想：函数调用时无歧义

// 14、函数高级——函数重载的注意事项
// 1、引用作为函数重载条件
// 2、函数重载碰到默认参数

#include <iostream>
using namespace std;

// 1、引用作为函数重载条件
// 加const可以作为函数重载的条件
// int& a = 10;	// 传入int常量不合法，仅能传入int型变量
void function_1(int& a) {
	cout << "function(int& a)调用" << endl;
}

// 加入const后，编译器自动优化代码：int temp = 10; const int& ref = temp;
// const int& a = 10;	// 传入int常量合法
void function_1(const int& a) {
	cout << "function(const int& a)调用" << endl;
}

// 2、函数重载碰到默认参数——有二义性
void function_2(int a, int b = 10) {
	cout << "function_2(int a, int b)的调用" << endl;
}

void function_2(int a) {
	cout << "function_2(int a)的调用" << endl;
}

int main(void) {
	// int a = 10;
	// function_1(a);

	// function_1(10);

	// function_2(10);	// 函数重载碰到了默认参数，调用时出现了二义性，尽量避免这种情况

	// system("pause");
	return 0;
}