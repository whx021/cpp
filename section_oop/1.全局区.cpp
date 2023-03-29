// 1、全局区
#include <iostream>
using namespace std;

// 全局变量
int global_a = 10;
int global_b = 10;

// const修饰的全局变量（全局常量）
const int const_global_a = 10;
const int const_global_b = 10;

int main(void) {
	// 普通局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a的地址为：" << &a << endl;
	cout << "局部变量b的地址为：" << &b << endl;

	// 全局变量
	cout << "全局变量global_a的地址为：" << &global_a << endl;
	cout << "全局变量global_b的地址为：" << &global_b << endl;

	// 静态变量
	static int static_a = 10;
	static int static_b = 10;
	cout << "静态变量static_a的地址为：" << &static_a << endl;
	cout << "静态变量static_b的地址为：" << &static_b << endl;

	// 常量
	// 字符串常量
	cout << "字符串常量的地址为：" << &"hello c++" << endl;

	// const修饰的变量
	// const修饰的全局变量，const修饰的局部变量
	cout << "const修饰的全局变量（全局常量）const_global_a地址为：" << &const_global_a << endl;
	cout << "const修饰的全局变量（全局常量）const_global_b地址为：" << &const_global_b << endl;
	// const修饰的局部变量（局部常量）
	const int const_local_a = 10;
	const int const_local_b = 10;
	cout << "const修饰的局部变量（局部常量）const_local_a地址为：" << &const_local_a << endl;
	cout << "const修饰的局部变量（局部常量）const_local_b地址为：" << &const_local_b << endl;

	// system("pause");
	return 0;
}