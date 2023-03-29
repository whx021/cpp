// 54、智能指针和C++运算符重载——重载指针运算符

#include <iostream>
using namespace std;

class Person {
public:
	Person(int age) : member_age(age) {
		cout << "Person有参构造函数的调用" << endl;
		// this->member_age = age;
	}

	void showPerson(void) {
		cout << "年龄为：" << this->member_age << endl;
	}

	~Person() {
		cout << "Person析构函数的调用" << endl;
	}

	int member_age;
};

// 智能指针类
class smartPointer {
public:
	smartPointer(Person* p) {
		cout << "smartPointer构造函数的调用" << endl;
		this->member_pointer = p;
	}

	// 重载"->"指针指向运算符
	Person* operator->(void) {
		return this->member_pointer;
	}

	// 重载"*"指针解引用运算符
	// 采用返回引用类型，防止调用拷贝构造函数的浅拷贝，

	// 如果直接返回的Person54类的类型，是调用了拷贝函数，
	// 返回拷贝了一份函数处理后的结果，返回的对象的地址与原对象不同，
	// 但在该对象所在的函数调用结束时，释放对象在栈区的内存空间，
	// 调用对象的析构函数，导致对象的指针类型成员属性在堆区创建的空间重复释放
	Person& operator*(void) {
		return *(this->member_pointer);
	}

	~smartPointer() {
		cout << "smartPointer析构函数的调用" << endl;
		if (this->member_pointer != nullptr) {
			delete this->member_pointer;
			this->member_pointer = nullptr;
		}
	}

	Person* member_pointer;
};

void test_1(void) {
	// 什么年代了，还在用传统指针？

	// 使用传统指针，忘记释放堆区内存，造成内存泄露
	// Person* p1 = new Person(20);
	// p1->showPerson(); 
	// (*p1).showPerson();
	// delete p1;

	// 利用智能指针，托管new出来的对象，不用再写delete，不会造成内存泄露
	// 
	// 智能指针在函数中调用中被使用时，
	// 	在栈区实例化一个智能指针（首先调用了其指针类型成员变量中指向的类的构造函数，
	// 	然后调用智能指针的构造函数）
	//
	// 智能指针所在的函数调用结束时，
	// 	释放智能指针在栈区的内存（首先调用智能指针的析构函数（包含释放其在堆区申请的空间的语句）
	// 	然后调用用了其指针类型成员变量中指向的类的析构函数）
	// 
	// 同时在smartPointer类中重载"->"指针指向运算符、重载"*"指针解引用运算符，
	// 使smartPointer的使用方法和指针相同
	smartPointer sp(new Person(20));
	sp->showPerson();	// 本质调用：sp->->showPerson();	// 编译器优化了写法
	(*sp).showPerson();	
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}