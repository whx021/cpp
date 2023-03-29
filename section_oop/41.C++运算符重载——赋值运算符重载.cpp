// 41、C++运算符重载——'='赋值运算符重载
// C++编译器至少给一个类添加4个函数
// 	1、默认构造函数（无参，函数体为空）
// 	2、默认析构函数（无参，函数体为空）
// 	3、默认拷贝构造函数，对属性进行值拷贝（浅拷贝）
// 	4、赋值运算符operator=，对属性进行值拷贝（浅拷贝）
// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题 

#include <iostream>
using namespace std;

class Person{
public:
	Person(int age) {
		member_age = new int(age);
	}

	~Person() {
		if (member_age != nullptr) { 
			delete member_age;
			member_age = nullptr;
		}
	}

	// '='赋值运算符重载
	// 传入和返回都为引用类型——链式编程思想
	Person& operator=(Person& p) {
		// 编译器提供浅拷贝
		// this->member_age = p.member_age;
		// 应先判断是否有属性在堆区，如果有：先释放干净，然后深拷贝
		if (member_age != nullptr) {
			delete member_age;
			member_age = nullptr;
		}
		// 提供深拷贝
		member_age = new int(*p.member_age);
		// 返回对象本身
		return *this;
	}

	int* member_age;
};

void test_1(void) {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	// 赋值操作
	p3 = p2 = p1;
	cout << "p1的年龄为：" << *p1.member_age << endl;
	cout << "p2的年龄为：" << *p2.member_age << endl;
	cout << "p3的年龄为：" << *p3.member_age << endl;
}

int main(void) {
	test_1();
	// int a = 10;
	// int b = 20;
	// int c = 30;
	// c = b = a;
	// cout << "a = " << a << endl;
	// cout << "b = " << b << endl;
	// cout << "c = " << c << endl;
	// system("pause");
	return 0;
}