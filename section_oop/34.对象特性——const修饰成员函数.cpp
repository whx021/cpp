// 34、对象特性——const修饰成员函数（只读）
//
// 常函数：
// 	1、常函数：成员函数后加const后
// 	2、常函数内不可以修改成员属性，指针常量this指针指向的值不可以修改
//		(const className* const this = &objectName;)
// 	3、成员属性声明时加关键字mutable后，在常函数中依然可以修改
// 
// 常对象：
// 	1、常对象：声明对象前加const
//	2、常对象只能调用常函数

#include <iostream>
using namespace std;

class Person {
public:
	Person() {}
	// this指针的本质：指针常量（指针的指向是不可以修改的）
	// Person* const this;

	// 常量成员函数后加const，修饰的为this指针
	// this指针改变为：指向常量的指针常量
	// const Person* const this;
	void showPerson(void) const { 
		// 非静态成员函数内部有this指针指向被调用成员函数所属的对象
		// 以下语句默认：this->member_A = 100;
		// member_A = 100;
		
		// this指针不可以修改指针的指向（指针常量）
		// this = nullptr;

		// 特殊变量，加上关键字mutable，即使在常函数中，也可以修改这个值
		this->member_B = 100;
	}

	void function(void) {}

	int member_A;
	// 特殊变量，加上关键字mutable，即使在常函数中，也可以修改这个值
	mutable int member_B;	
};

void test_1(void) {
	Person p;
	p.showPerson();
}

void test_2(void) {
	// 常对象：在对象前面加上const
	const Person p;
	// p.member_A = 100;	// 不可以修改常对象的成员变量
	// 类Person中特殊变量member_B，加上关键字mutable，
	// 即使在常函数中，常对象中，也可以修改这个值
	p.member_B = 100;

	// 常对象只能调用常函数
	p.showPerson();
	
	// 常对象不能调用普通的成员函数，
	// 因为普通的成员函数可以修改对象属性，而常对象定义不可以修改对象属性
	// p.function();
}

int main(void) {
	// system("pause");
	return 0;
}