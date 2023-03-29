// 31、对象特性——成员变量和成员函数分开存储
// 结论：只有非静态成员变量才属于类的对象上

#include <iostream>
using namespace std;

class Person {
	// 非静态成员变量，属于类的对象上（记录类的内存大小）
	int member_A;

	// 静态成员变量，不属于类的对象上（不记录类的内存大小）
	// 静态成员变量——类内声明
	static int member_B;

	// 非静态成员函数，不属于类的对象上（不记录类的内存大小）
	void function_1(void) {}

	// 静态成员函数，不属于类的对象上（不记录类的内存大小）
	static void function_2(void) {}
};

// 静态成员变量——类外初始化
int Person::member_B = 0;

void test_1(void) {
	Person p;
	// 空对象的占用内存空间为：1byte
	// 原因：C++编译器会给每一个空对象分配一个字节的空间，是为了区分空对象占内存的位置
	// 每个空对象也应该有一个独一无二的内存地址

	// 如果不为空对象，内存中的大小为其非静态成员变量的内存大小
	cout << "size of p = " << sizeof(p) << endl;
}

void test_2(void) {
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return 0;
}