// 43、C++运算符重载——"()"函数调用运算符重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活（STL中用到的较多）

#include <iostream>
#include <string>
using namespace std;

// "()"函数调用运算符重载

// 打印输出的类
class MyPrint {
public:
	// "()"函数调用运算符重载
	void operator()(string test) {
		cout << test << endl;
	}
};

void MyPrint_2(string test) {
	cout << test << endl;
}

void test_1(void) {
	MyPrint myPrint;

	// "()"函数调用运算符重载，由于重载后使用的方式非常像函数的调用，因此称为仿函数
	// 仿函数调用
	myPrint("hello world"); 

	// 函数调用
	MyPrint_2("hello world");
}

// 仿函数没有固定写法，非常灵活（STL中用到的较多）
// 加法类
class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void test_2(void) {
	MyAdd myAdd;
	int result = myAdd(100, 100);
	cout << "result = " << result << endl;

	// 匿名函数对象		使用:无参构造的匿名对象MyAdd()		调用:重载的"()"函数调用运算符
	cout << MyAdd()(100, 100) << endl;
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return 0;
}