// 32、对象特性——this指针的用途
//
// C++中：成员变量和成员函数分开存储
//
// 每一个非静态成员函数只会产生一份函数实例（多个同类的对象共用一段成员函数代码）
// 
// 问题：非静态成员函数的代码是怎样区分那个对象调用自身？
// 
// 解决：
// C++通过提供特殊的对象指针：this指针：指向被调用成员函数所属的对象
// this pointer作为非静态成员函数的隐藏默认参数，
// 传入参数的值为当前调用该成员函数的实例化对象的地址
// (className* this = &objectName)
//
// this指针是隐含每一个非静态成员函数内部的一种指针
// this指针不需要定义，直接使用即可
// 
// this指针用途：
// 1、当形参和成员变量同名时，可用this指针区分
// 2、在类的非静态成员函数中返回对象本身，可使用return *this;

#include <iostream>
using namespace std;

class Person {
public:
	// 1、当形参和成员变量同名时，可用this指针区分
	Person(int age) {
		// this指针：指向被调用成员函数所属的对象
		this->age = age;
	}
	// 使用引用类型返回，不会创建一个新的变量，直接返回处理后的原变量（地址相同）
	//
	// 直接返回类的类型，是拷贝一份处理后的新变量，存储函数结果值，并返回
	// 仅有第一次函数调用对原变量p产生影响
	Person& PersonAddAge(Person& p) {
		this->age += p.age;

		// this是指向p的指针，
		// *this为调用改成员函数的实例化对象;
		return *this;
	}

	int age;
};

// 1、当形参和成员变量同名时，可用this指针区分
void test_1(void) {
	Person p(18);
	cout << "p的年龄为：" << p.age << endl;
}

// 2、在类的非静态成员函数中返回对象本身，可使用return *this;
void test_2(void) {
	Person p1(10);
	Person p2(10);

	// 链式编程思想：原对象调用的成员函数的返回值类型是原对象的引用类型，
	// 成员函数返回的是原对象修改后的原对象，可以在一个语句中多次调用
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄：" << p2.age << endl;
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return 0;
}