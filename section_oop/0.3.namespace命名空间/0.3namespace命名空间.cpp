// 0_3namespace命名空间
//
// 1、命名空间的用途：解决名称冲突
// 2、命名空间下，可以存储：变量、函数、结构体、类...
// 3、命名空间必须声明在全局作用域下
// 4、命名空间可以嵌套命名空间
// 5、命名空间是开放的，可以随时向空间中添加新成员，合并
// 6、命名空间可以是匿名的
// 7、命名空间可以起别名

#include <iostream>
using namespace std;
#include "0.3.附加1game1.h"
#include "0.3.附加2game2.h"

// 1、命名空间的用途：解决名称冲突
void test_1(void) {
	// 函数重定义错误，不同头文件中含有相同的函数，
	LOL::goAttack03();
	KingGlory::goAttack03();

	// std命名空间的标准输出流对象cout
	// std::cout;
}

// 2、命名空间下，可以存储：变量、函数、结构体、类...
namespace A {
	int member_A = 10;
	void function(void){};
	struct Person{};
	class Animal{};
}

// 3、命名空间必须声明在全局作用域下
void test_2(void) {
	// namespace B {

	// }
}

// 4、命名空间可以嵌套命名空间
namespace B {
	int m_A = 10;
	namespace C {
		int m_A = 20;
	}
}

void test_3(void) {
	cout << "namespace B 中的 m_A = " << B::m_A << endl;
	cout << "namespace C 中的 m_A = " << B::C::m_A << endl;
}

// 5、命名空间是开放的，可以随时向空间中添加新成员，合并
namespace B {
	int m_B = 30;
}

void test_4(void) {
	cout << "namespace B 中的 m_A = " << B::m_A << endl;
	cout << "namespace B 中的 m_B = " << B::m_B << endl;
}

// 6、命名空间可以是匿名的，相当于全局命名空间
namespace {
	int m_C = 100;
	int m_D = 200;
}

void test_5(void) {
	// 匿名命名空间访问的两种方式（和全局变量的访问方式相同）
	cout << "m_C = " << m_C << endl;
	cout << "m_D = " << ::m_D << endl;
}

// 7、命名空间可以起别名
namespace veryLongName {
	int m_E = 1000;
}
void test_6(void) {
	// 给命名空间起别名
	namespace veryShortName = veryLongName;
	
	cout << veryLongName::m_E << endl;
	cout << veryShortName::m_E << endl;
}


int main(void) {
	test_6();

	return EXIT_SUCCESS;
}