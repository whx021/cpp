// 8、引用做函数的返回值
// 注意：
// 1、不要返回局部变量的引用
// （引用本质：指针常量，局部变量在栈区函数调用后释放内存，返回的地址空间不属于程序维护）
//
// 2、函数的调用可以作为左值

// 1、不要返回局部变量的引用
int& test_1(void) {
	int a = 10;	// 存放在栈区
	return a;
}

// 2、函数的调用可以作为左值
int& test_2(void) {
	static int b = 10;	// 静态变量，存放在全局区，程序运行结束后才会被释放
	return b;
}

#include <iostream>
using namespace std;

int main(void) {
	int& ref1 = test_1();

	// ref为栈区空间中变量a的引用，
	// test_1函数调用结束后，a的内存空间被释放
	// 此时通过ref访问a的值是非法操作
	cout << "ref1 = " << ref1 << endl;
	cout << "ref1 = " << ref1 << endl;
	cout << "ref1 = " << ref1 << endl;
	cout << "ref1 = " << ref1 << endl;
	cout << "ref1 = " << ref1 << endl;

	int& ref2 = test_2();	// ref2引用函数test_2()中的静态变量b
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	
	// 2、函数的调用可以作为左值
	// 若函数的返回值是一个引用，这个函数的调用可以作为左值
	test_2() = 1000;	// test_2()为静态变量b的引用的赋值操作
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	// system("pause");
	return 0;
}