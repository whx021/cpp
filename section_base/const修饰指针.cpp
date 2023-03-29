// 48、const修饰指针
//
// 技巧：const修饰紧跟语句
// 
// 1、const修饰指针：--常量指针
// const int* p = &a;
// 特点：指针的指向可以修改，指针指向的值不可以修改
// 
// 2、const修饰常量：--指针常量
// int* const p = &a;
// 特点：指针的指向不可以修改，指针指向的值可以修改
// 
// 3、const及修饰指针，又修饰常量
// const int* const p = &a;
// 特点：指针的指向&指针指向的值都不可以修改

#include <iostream>
using namespace std;

int main(void) {
	// 1、const修饰指针
	int a = 10;
	int b = 20; 
	const int* p = &a;
	// *p = 20;  // 错误：赋值表达式必须是一个可修改左值
	p = &b;	// 正确

	// 2、const修饰常量
	int* const p2 = &a;
	*p2 = 100;	// 正确
	// p2 = &b;	// 错误：赋值表达式必须是一个可修改左值

	// 3、const修饰指针&常量
	const int* const p3 = &a;
	// *p3 = 100;	// 错误
	// p3 = &b;		// 错误

	// system("pause");
	return 0;
}