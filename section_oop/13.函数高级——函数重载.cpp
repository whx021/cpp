// 13、函数高级——函数重载
// 作用：函数名可以相同，提高复用性

// 函数重载满足条件
// 1、同一作用域下（全局作用域、代码块作用域）
// 2、函数名称相同
// 3、(函数的参数类型 || 参数的个数 || 参数的顺序)不同

// 注意：函数的返回值不可以做为函数重载的条件

// 函数重载实现原理
// 编译器为了实现函数重载，默认为做了一些幕后的事情：
// 编译器用不同参数类型，来修饰不同函数名：
// void func()					函数名修饰为：	_func
// void func(int x)				函数名修饰为：	_func_int
// void func(int x, char y)		函数名修饰为：	_func_int_char
// 
// 不同编译器修饰重载函数名，没有统一标准，不同编译器可能会产生不同内部名
//
// linux下生成的编译之后的函数名为：
// _Z4funcv		// v:void
// _Z4funci		// i:int
// _Z4funcic	// i:int c:char

#include <iostream>
using namespace std;

void function() {
	cout << "function的调用" << endl;
}

void function(int a) {
	cout << "function(int a)的调用" << endl;
}

void function(double a) {
	cout << "function(double a)的调用" << endl;
}

void function(int a, double b) {
	cout << "function(int a, double b)的调用" << endl;
}

void function(double b, int a) {
	cout << "function(double b, int a)的调用" << endl;
}

// 注意：函数的返回值不可以做为函数重载的条件
// int function(double b, int a) {
// 	cout << "function(double b, int a)的调用" << endl;
// }
// 以上函数重定义，重载错误，


int main(void) {
	function();
	function(10);
	function(3.14);
	function(10, 3.14);
	function(3.14, 10);
	
	// system("pause");
	return 0;
}