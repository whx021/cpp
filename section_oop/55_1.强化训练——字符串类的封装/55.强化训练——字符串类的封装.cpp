// 55、强化训练——字符串类的封装

// #define _CRT_SECURE_NO_WARNINGS	// 防止C499问题
#include <iostream>
using namespace std;
// // 维护了C中的字符串数组，并添加了对字符数组中各类操作
// #include <string>	
#include "55.附加1mystring.h"

void test_1(void) {
	// 隐式转换法调用有参构造函数
	MyString str1 = "abcd";

	// 隐式转换法调用有参拷贝构造函数
	MyString str2 = str1;

	// 调用重载"<<"运算符函数
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;

	// 调用重载">>"运算符函数
	cout << "请给str1重新赋值" << endl;
	cin >> str1;
	cout << "str1 = " << str1 << endl;
}

void test_2(void) {
	// 隐式转换法调用有参构造函数
	MyString str1 = "abc";
	MyString str2 = "def";

	// "="赋值运算符使用的是编译器默认提供的，产生浅拷贝问题（析构函数中重复释放同一段堆区内存）
	// 调用重载"="赋值运算符函数
	str1 = str2;
	cout << "str1 = " << str1 << endl;

	// 调用重载"="赋值运算符函数
	str1 = "efghy";
	cout << "str1 = " << str1 << endl;
}

void test_3(void) {
	// 隐式转换法调用有参构造函数
	MyString str1 = "abc";

	// 调用重载"[]"运算符函数
	cout << "myString[0] = " << str1[0] << endl;

	// 调用重载"[]"运算符函数
	str1[0] = 'z';
	cout << "第一个字符改为'z'之后，str1结果为：" << endl;
	cout << "str1 = " << str1 << endl;
}

// 存在问题
void test_4(void) {
	// 调用重载"+"运算符函数
	MyString str1 = "abc";
	MyString str2 = "def";
	MyString str3 = str1 + str2;
	MyString str4 = str1 + "def";

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
}

void test_5(void) {
	MyString str1 = "abc";
	MyString str2 = "abcd";

	// 调用重载"=="运算符函数，与MyString类对象比较
	if (str1 == str2) {
		cout << "str1 == str2" << endl;
	}
	else {
		cout << "str1 != str2" << endl;
	}
	
	// 调用重载"=="运算符函数，与string类对象或字符串比较
	if (str1 == "abc") {
		cout << "str1 == \"abe\"" << endl;
	}
	else {
		cout << "str1 != \"abc\"" << endl;
	}
}


int main(void) {
	// test_1();

	// char buffer1[64] = { 0 };
	// char buffer2[64] = { 0 };
	
	// // cin返回值仍是cin类型，链式编程思想
	// cin >> buffer1 >> buffer2;

	// cout << buffer1 << endl;
	// cout << buffer2 << endl;

	// test_2();
	// test_3();
	test_4();
	// test_5();

	// system("pause");
	return EXIT_SUCCESS;
}