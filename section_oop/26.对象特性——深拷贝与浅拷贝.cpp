// 26、对象特性——深拷贝与浅拷贝
//
// 	浅拷贝：简单的复制拷贝操作（编译器提供的拷贝构造函数）
// 	深拷贝：在堆区重新申请空间，进行拷贝操作
//
// 总结：如果属性有在堆区开辟的，一定要自己构造拷贝构造函数，防止浅拷贝带来的问题

#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age, int height) {
		member_age = age;
		member_height = new int(height);
		cout << "Person有参构造函数调用" << endl;
	}
	// 自己构造拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p) {
		cout << "Person有参拷贝构造函数调用" << endl;
		member_age = p.member_age;
		// 对于指针变量，编译器默认实现的拷贝构造函数的语句（浅拷贝）
		// member_height = p.member_height;
		// 深拷贝解决浅拷贝的问题（堆区空间重复释放的非法操作）
		member_height = new int(*p.member_height);
	}
	~Person() {
		// 析构函数作用：对象销毁前，将堆区开辟的数据做释放操作
		// 如果使用浅拷贝，则会导致堆区内存重复释放
		if (member_height != NULL) {
			delete member_height;	// 释放堆区的空间
			member_height = NULL;	// 置空，防止野指针
		}
		cout << "Person析构函数调用" << endl;
	}

	int member_age;		// 年龄
	int* member_height;	// 身高
};

void test_1(void) {
	Person p1(18, 160);
	cout << "p1的年龄为：" << p1.member_age << "\t身高为：" << *p1.member_height << endl;

	Person p2(p1);
	cout << "p2的年龄为：" << p2.member_age << "\t身高为：" << *p2.member_height << endl;
}

int main(void) {
	test_1();

	return 0;
}