// 60、继承——同名成员处理方式
//
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据
// 1、访问子类同名数据：直接访问
// 2、访问父类同名数据：需要加上父类作用域
// 3、如果子类中出现了和父类同名的成员函数，子类中同名成员会隐蔽掉父类中所用的成员函数

#include <iostream>
using namespace std;

class Base {
public:
	Base() : member_A(100) {
		// member_A = 100;
	}
	int member_A;

	void function(void) {
		cout << "Base的function()调用" << endl;
	}
	void function(int a) {
		cout << "Base的function(int a)调用" << endl;
	}
};

class Son : public Base {
public:
	Son() : member_A(200) {
		// member_A = 200;
	}
	int member_A;

	void function(void) {
		cout << "Son的function()调用" << endl;
	}
};

// 同名成员属性处理
void test_1(void) {
	Son s1;
	cout << "Son 中 member_A = " << s1.member_A << endl;
	// 通过子类对象，访问父类同名属性数据：需要加上父类作用域
	cout << "Base 中 member_A = " << s1.Base::member_A << endl;
}

// 同名成员函数处理
void test_2(void) {
	Son s2;
	// 如果子类中出现了和父类同名的成员函数，子类中同名成员会隐蔽掉父类中所用的成员函数
	// 如果像访问到父类中被隐藏的同名成员函数，需要加父类作用域

	// 直接调用是调用子类中的同名成员函数
	s2.function();

	// 加上父类作用域，调用父类中的同名成员函数
	s2.Base::function();
	s2.Base::function(100);
}

int main(void) {
	test_2();
	// system("pause");
	return EXIT_SUCCESS;
}