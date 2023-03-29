// 29、静态成员变量
//
// 静态成员：在成员变量和成员函数前面加上关键字static 
//
// 静态成员变量：
//	1、所有对象共享同一份数据
//	2、在编译阶段分配内存（分配在全局区，作用域仅在class内部）
//	3、类内声明，类外初始化
// 静态成员函数：
//	1、所有对象共享同一函数
//	2、静态成员函数只能访问静态成员变量（不含有this指针）


#include <iostream>
using namespace std;

class Person {
public:
	// 静态成员变量：
	// 所有对象共享同一份数据
	// 在编译阶段分配内存（分配在全局区）
	// 类内声明，类外初始化
	static int member_A;
	// 静态成员变量也是有访问权限的
private:
	static int member_B;
};

//类外初始化
int Person::member_A = 100;
int Person::member_B = 200;

void test_1(void) {
	Person p1;
	cout << p1.member_A << endl;

	Person p2; 
	p2.member_A = 200;

	// 100 ? 200，结果为200，member_A为类Person的静态变量，所有对象共享同一静态变量
	cout << p1.member_A << endl;
}

void test_2(void) {
	// 静态成员变量：不属于某一个对象，所有对象共享一份数据
	// 因此静态成员变量有两种访问方式

	// 1、通过对象进行访问
	Person p3;
	cout << p3.member_A << endl;

	// 2、通过类名进行访问
	cout << Person::member_A << endl;

	// 私有作用域下的静态成员变量无法在函数外直接访问
	// （需要提供成员函数作为接口，或将访问的函数设置为被访问类的友元）
	// cout << Person29::member_B << endl;
}

int main(void) {
	// test_1();
	test_2();

	// system("pause");
	return 0;
}