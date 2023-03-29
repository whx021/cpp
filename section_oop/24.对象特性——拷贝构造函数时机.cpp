// 24、对象特性——拷贝构造函数时机
// 三种情况：
// 	1、使用一个已经创建完毕的对象来初始化一个新对象 
// 	2、值传递的方式给函数传值
// 	3、以值方式返回局部变量

#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age) {
		member_age = age;
		cout << "Person有参构造函数调用" << endl;
	}
	Person(const Person& p) {
		member_age = p.member_age;
		cout << "Person有参拷贝构造函数调用" << endl;
	}
	~Person() {
		cout << "Person析构函数调用" << endl;
	}

	int member_age;
};

// 1、使用一个已经创建完毕的对象来初始化一个新对象 
void test_1(void) {
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄：" << p2.member_age << endl;
}

// 2、值传递的方式给函数传值，传入被调用函数的对象是调用函数的拷贝
void doWork_1(Person p) {}

void test_2(void) {
	Person p1;
	
	// 2、值传递的方式给函数传值，传入被调用函数的对象是调用函数的拷贝
	doWork_1(p1);
}

// 3、以值方式返回局部变量
Person doWork_2(void) {
	Person p1;
	// p1与调用函数中p的地址不同
	cout << &p1 << endl;
	return p1;	// 以值方式放回局部变量：是通过拷贝的一份局部变量来返回值的
}

void test_3(void) {
	Person p = doWork_2();
	// p与被调用函数中p1的地址不同
	cout << &p << endl;
}

int main(void) {
	// test_1();
	// test_2();
	test_3();
	return 0;
}