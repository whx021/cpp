// 25、对象特性——构造函数的调用规则
//
// 默认情况下：C++编译器至少给一个类添加3个函数
// 	1、默认构造函数（无参，函数体为空）
// 	2、默认析构函数（无参，函数体为空）
// 	3、默认拷贝构造函数，对属性进行值拷贝：浅拷贝
//
// 构造函数的调用规则：
// 	1、如果用户定义有参构造函数，C++不在提供默认无参构造，提供默认拷贝构造函数
// 	2、如果用户定义无参构造函数，C++不在提供其他构造函数

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
		cout << "Person析构构造函数调用" << endl;
	}

	int member_age;
};

void test_1(void) {
	Person p;
	p.member_age = 18;

	Person p2(p);
	cout << "p2的年龄为：" << p2.member_age << endl;
}

void test_2(void) {
	Person p(28);
	Person p2(p);
	cout << "p2的年龄为：" << p2.member_age << endl;
}

int main(void) {
	//test_1();
	test_2();
	// system("pause");
	return 0;
}