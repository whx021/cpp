// 61、继承——同名静态成员处理
//
// 静态成员变量特点：
// 	1、所用对象共享同一份实例
// 	2、编译阶段分配内存
// 	3、类内声明，类外初始化
// 静态成员函数特点：
// 	1、仅能访问静态成员变量
//
// 问题：继承中同名的静态成员在子类对象上如何进行访问
//	静态成员与非静态成员出现同名，处理方式一致
//	访问子类同名成员：直接访问
//	访问父类同名成员：需要加父类的作用域

#include <iostream>
using namespace std;

class Base {
public:
	static int member_A;

	static void function(void) {
		cout << "Base 中 static void function(void)函数调用" << endl;
	}
	static void function(int a) {
		cout << "Base 中 static void function(int a)函数调用" << endl;
	}
};

int Base::member_A = 100;

class Son : public Base {
public:
	static int member_A;

	static void function(void) {
		cout << "Son 中 static void function(void)函数调用" << endl;
	}
};
int Son::member_A = 200;

// 同名的静态的成员属性
void test_1(void) {
	// 1、通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	cout << "Son 中 static int member_A = " << s.member_A << endl;
	cout << "Base 中 static int member_A = " << s.Base::member_A << endl;

	// 2、通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son 中 static int member_A = " << Son::member_A << endl;
	
	// 第一个双冒号：代表通过类名的方式访问
	// 第二个双冒号：表示父类作用于下的member_A
	cout << "Base61 中 static int member_A = " << Son::Base::member_A << endl;
}

// 同名的静态成员函数
void test_2(void) {
	// 1、通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	s.function();
	s.Base::function();

	// 2、通过类名访问
	cout << "通过类名访问：" << endl;
	Son::function();

	// 第一个双冒号：代表通过类名的方式访问
	// 第二个双冒号：表示父类作用于下的function()
	Son::Base::function();
	Son::Base::function(100);
	// 如果子类中出现了和父类同名的静态成员函数，子类中同名成员会隐蔽掉父类中所用的静态成员函数
	// 如果像访问到父类中被隐藏的同名静态成员函数，需要加父类作用域
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return EXIT_SUCCESS;
}