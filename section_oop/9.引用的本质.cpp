// 9、引用的本质
// 应用的本质：C++中内部实现是一个指针常量
// 一旦初始化后，不可以改变指向
// 
// 编译器自动转换：定义引用类型时，编译器已知b为引用类型
//
// 原语句：int& b = a;
// 转化语句：int* const b = &a;
// 原语句：b = 10;
// 转化语句：*b = 10;

#include <iostream>
using namespace std;

// 编译器自动转化引用类型函数参数：int* const ref = &a
// 通过指针常量传入a的地址
void function(int& ref) {
	//编译器自动转化：*ref = 100;
	ref = 100;	
}

int main(void) {
	int a = 10;

	//编译器自动转化：int* const ref = &a;
	int& ref = a;

	//编译器自动转化：*ref = 20;
	ref = 20;

	cout << "a = " << a << endl;
	//编译器自动转化：cout << "ref = " << *ref << endl;
	cout << "ref = " << ref << endl;
	
	// system("pause");
	return 0;
}