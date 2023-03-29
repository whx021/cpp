// 33、对象特性——空指针访问成员对象
// C++中空指针可以调用成员函数，但是也要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性

#include <iostream>
using namespace std;

class Person {
public:
	void showClassName(void) {
		cout << "this is a Person class" << endl;
	}

	void showPersonAge(void) {
		// 如果传入的指针为nullptr，直接返回，提高代码健壮性 
		if (this == nullptr) {
			return;
		}

		// 报错原因：
		// 并没有实例化一个对象，this指针没有指向
		// 因为传入的指针为nullptr，访问了Person类型nullptr指针的成员
		// 非静态成员函数中属性前面默认加入"this->属性"：当前对象的属性
		// 并没有实例化一个对象，this指针没有指向，产生错误
		cout << "age = " << this->member_age << endl;
	}

	int member_age;
};

void test_1(void) {
	Person* p = nullptr;

	// NULL指针可以访问类成员，
	// 但不能调用：调用了成员属性的非静态成员函数（造成this指针无指向）
	p->showClassName();

	p->showPersonAge();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}