// 27、对象特性——初始化列表
// 作用：C++中提供初始化列表语法，用来初始化属性
// 语法：构造函数(): 属性1(值1), 属性2(值2), ...{}

#include <iostream>
using namespace std;

class Person {
public:
	// 传统初始化操作：使用有参构造函数，运行效率没有使用初始化列表高
	// Person(int a, int b, int c) {
	// 	member_A = a;
	// 	member_B = b;
	// 	member_C = c;
	// }

	// 初始化列表初始化属性
	Person(int a, int b, int c) : member_A(a), member_B(b), member_C(c) {}

	int member_A;
	int member_B;
	int member_C;
};

void test_1(void) {
	// Person p(10, 20, 30);
	Person p(30, 20, 10);
	cout << "member_A = " << p.member_A << endl;
	cout << "member_B = " << p.member_B << endl;
	cout << "member_C = " << p.member_C << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}