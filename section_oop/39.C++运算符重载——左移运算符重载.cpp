// 39、C++运算符重载——左移运算符重载'<<'
// 作用：输出自定义类型
// 总结：重载运算符配合友元可以实现输出自定义数据类型

#include <iostream>
using namespace std;

class Person {
	// 将全局重载左移运算符函数作为类Person的友元，可以访问Person类的私有属性
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a, int b) {
		member_A = a;
		member_B = b;
	}
private:
	// 利用成员函数重载'<<'左移运算符
	// 本质写法：p.operator<<(p, cout); （p为默认隐藏参数，this指向p）
	// 简化写法：p << cout
	// 通常不会使用成员函数重载'<<'左移运算符
	// 因为无法实现cout在左侧
	// void operator<<(cout) {}

	int member_A;
	int member_B;
};


// 只能应用全局运算符重载'<<'左移运算符
// 本质写法：operator<<(cout, p)
// 简化写法：cout << p
// cout的数据类型ostream（标准输出流对象类型）
// 放回值为ostream的引用类型——链式编程思想
// 使用引用类型的原因：ostream类型的cout为标准类，全局只能有一个
// 引用类型中可以在重载运算符函数中给cout起别名out（可以但没必要）
ostream& operator<<(ostream& cout, Person& p) {
	cout << "member_A = " << p.member_A << "\tmember_B = " << p.member_B;
	return cout;
}

void test_1(void) {
	Person p(10, 10);
	// p.member_A = 10;
	// p.member_B = 10;
	cout << p << "\thello world" << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}