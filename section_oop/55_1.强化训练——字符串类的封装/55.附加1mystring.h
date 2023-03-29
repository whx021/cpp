#pragma once						// 防止头文件重复包含
#define _CRT_SECURE_NO_WARNINGS		// 防止C499问题
#include <iostream>
#include <cstring>
using namespace std;

// 我的字符串类
class MyString {
	// 应用全局函数重载"<<"、">>"运算符，实现自定义字符串类型的输入输出
	friend ostream& operator<<(ostream& cout, MyString& myString);
	friend istream& operator>>(istream& cin, MyString& myString);
public:
	// 构造函数
	MyString(const char* str);		// 有参构造 : 实现字符串赋初值：MyString str1 = "abcd";
	MyString(const MyString& str);	// 拷贝构造 : 实现字符串赋值：MyString str2 = str1;

	// 重载"="赋值运算符，防止使用深拷贝防止浅拷贝的问题
	MyString& operator=(const char* str);
	MyString& operator=(const MyString& myString);

	// 重载"[]"，访问单个元素
	char& operator[](int index);

	// 重载'+'运算符，实现字符串拼接
	MyString operator+(const char* str);
	MyString operator+(const MyString& myString);

	// 重载"=="比较运算符，进行字符串的比较
	bool operator==(const char* str);
	bool operator==(const MyString& myString);

	// 析构函数
	~MyString();	// 释放字符串在堆区的内存

private:
	char* pString;		// 维护底层堆区开辟的字符数组
	int member_length;	// 字符串长度
};