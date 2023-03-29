// 30、静态成员函数
// 
// 静态成员：在成员变量和成员函数前面加上关键字static 
// 
// 静态成员函数：
//	所有对象共享同一函数
//	静态成员函数只能访问静态成员变量（不含this pointer）


#include <iostream>
using namespace std;

class Person {
public:
	// 静态成员函数：
	// 1、所有对象共享同一函数
	// 2、静态成员函数只能访问静态成员变量
	static void function(void) {
		// 静态的成员函数 可以访问 静态的成员变量
		member_A = 100;

		// 静态的成员函数 不可以访问 非静态的成员变量（不含有this pointer）
		// 原因：	
		// 	静态成员函数在内存中仅有一份，所用对象共享同一静态成员函数
		//	而非静态的成员变量属于已定义特定的对象，可以存在多个
		//	已定义的特定对象在调用静态成员函数时，
		//	静态成员函数无法确定是对那个已定义对象的非静态成员变量进行访问
		//	产生二义性错误
		// member_B = 100;	// 错误
		cout << "static void function(void)调用" << endl;
	}
	// 静态成员变量
	static int member_A;

	// 非静态的成员变量
	int member_B;

	// 静态成员函数也是有访问权限的
private:
	static void function2(void) {
		cout << "static void function2(void)调用" << endl;
	}
};

// 静态成员变量的初始化
int Person::member_A = 0;

void test_1(void) {
	// 两种访问方法：
	// 1、通过对象调用访问
	Person p1;
	p1.function();
	// 2、通过类名调用访问
	Person::function();

	// 类外访问不到私有的静态成员函数
	// （需要将访问的函数设置为被访问类的友元）
	// Person::function2();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}