// 51、C++堆区深入——new和delete运算符
//
// malloc 和 new 的区别？
//	1、malloc和free属于库函数,				    new和delete属于运算符,关键字
//	2、malloc返回void*，需要进行强制类型转换	  new返回对应 数据类型指针
//	3、malloc对应的是free释放				    new对应delete释放
//	4、malloc不会调用构造函数					new会调用构造函数
//	5、free不会调用析构函数						delete会调用析构函数
//	6、malloc需要配合sizeof计算分配内存的大小	  new不需要

// 注意事项：不要利用void* 接受new出来的对象
// 原因：delete时不会执行析构函数,void*无法得知delete对象的类型

#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "Person默认构造函数调用" << endl;
	}

	Person(int) {
		cout << "Person有参构造函数调用" << endl;
	}

	Person(const Person&) {
		cout << "Person有参拷贝构造函数调用" << endl;
	}

	~Person() {
		cout << "Person析构函数调用" << endl;
	}
};

void test_1(void) {
	// Person p;	// 在栈上创建对象

	// 在堆区创建对象
	Person* p1 = new Person;

	// 释放堆区创建的对象
	delete p1;
}

// 注意事项：不要利用void* 接受new出来的对象
// 原因：delete时不会执行析构函数
void test_2(void) {
	void* p = new Person;
	
	delete p;
}

// 在堆区开辟数组
void test_3(void) {
	// C
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (p1 == nullptr) {
		cout << "内存分配失败" << endl;
		return;
	}

	// C++
	int* pInt = new int[10];

	char* pChar = new char[10];

	// 如果在堆区开辟自定义类型的数组，这个类型必须有默认构造函数
	// 原因:每个在堆区的自定义类型对象创建时必须调用默认构造函数,无法调用其他构造函数
	Person* persons = new Person[10];

	// 释放堆区的数组,加[]
	delete[] persons;
}

// 在栈上开辟数组的时候，可以没有默认构造函数
void test_4(void) {
	Person pArray[3] = { Person(10), Person(10), Person(10) };
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}