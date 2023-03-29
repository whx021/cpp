// 38、C++运算符重载——加号运算符重载
//
// 运算符重载：
// 	对已有的运算符重新进行定义，赋予另一种功能，以适应不同的数据类型
// 
// 对于内置的数据类型，编译器知道如何进行运算
// 而自定义数据类型，需要重载运算符进行计算
//
// 总结：
// 	1、对于内置的数据类型的表达式的运算符是不可能改变的
// 	2、不要滥用运算符重载

#include <iostream>
using namespace std;

// 加号运算符重载

class Person {
public:
	// // 1、通过成员函数重载加号'+'，
	// // 通过成员函数重载运算符的函数中同样含有隐藏默认参数（当前调用该成员函数的实例化对象）
	// Person operator+(Person& p) {
	// 	Person temp;
	// 	temp.member_A = this->member_A + p.member_A;
	// 	temp.member_B = this->member_B + p.member_B;
	// 	return temp;
	// }

	int member_A;
	int member_B;
};

// 2、通过全局函数重载加号'+'
Person operator+(Person& p1, Person& p2) {
	Person temp;
	temp.member_A = p1.member_A + p2.member_A;
	temp.member_B = p1.member_B + p2.member_B;
	return temp;
} 

// 全局函数重载'+'运算符的重载函数
Person operator+(Person& p1, int num) {
	Person temp;
	temp.member_A = p1.member_A + num;
	temp.member_B = p1.member_B + num;
	return temp;
}

void test_1(void) {
	Person p1;
	p1.member_A = 10;
	p1.member_B = 10;

	Person p2;
	p2.member_A = 10;
	p2.member_B = 10;

	// 成员函数重载'+'运算符的本质调用
	// Person p3 = p1.operator+(p2);
	// Person p3 = p1.operator+(p1, p2);
	// （p1为隐藏默认参数，成员函数内有this pointer指向p1）
	
	// 全局函数重载'+'运算符的本质调用
	// Person p3 = operator+(p1, p2);
	
	// 成员函数和全局函数重载'+'运算符的简化调用
	Person p3 = p1 + p2;

	// 运算符重载也可以发生函数重载
	// 全局函数重载'+'运算符的本质调用
	// Person p4 = operator+(p1, 100);
	Person p4 = p1 + 100;	//Person + int

	cout << "p3.member_A = " << p3.member_A << endl;
	cout << "p3.member_B = " << p3.member_B << endl;

	cout << "p4.member_A = " << p4.member_A << endl;
	cout << "p4.member_B = " << p4.member_B << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}