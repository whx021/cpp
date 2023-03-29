// 40、C++运算符重载——'++'递增运算符重载
// 作用：通过重载'++'递增运算符，实现自己的整形数据
// 总结：前置递增返回引用，后置递增返回值

// ++的类型是const Age，自然不能对它进行前置++、后置++、赋值等操作。
// ++a的类型是Age&，当然可以对它进行前置++、后置++、赋值等操作

#include <iostream>
using namespace std;

// '++'递增运算符重载

// 自定义的整型变量
class MyInteger_1 {
	// friend ostream& operator<<(ostream& cout, MyInteger_1& myInt);
	friend ostream& operator<<(ostream& cout, MyInteger_1 myInt);
public:
	MyInteger_1() {
		member_num = 0;
	}

	// '++'递增运算符重载

	// 重载前置'++'递增运算符
	// 返回引用：为对一个数据进行递增操作（链式编程思想）
	// 给成员函数的参数实际存在 默认隐藏参数 当前调用该成员函数的实例化对象
	MyInteger_1& operator++(void) {
		// 先进行'++'运算
		// ++this->member_num;
		++member_num;

		// 再将自身放回
		return *this;
	}

	// 重载后置'++'递增运算符
	// void operator++(int)	// int为占位参数，可以用于区分前置和后置递增
	// 后置递增直接返回MyInteger类型，因为temp为成员函数的局部变量，
	// 不可以放回局部变量的引用类型，成员函数执行结束后，该变量的内存空间不属于程序维护
	MyInteger_1 operator++(int) {
		// 先 记录当时结果
		MyInteger_1 temp = *this;
		// 后 递增
		++member_num;
		// 最后返回记录结果
		return temp;
	}
private:
	int member_num;
};

// // 全局函数重载'<<'左移运算符
// ostream& operator<<(ostream& cout, MyInteger_1& myInt) {
// 	cout << myInt.member_num;
// 	return cout;
// }

// 全局函数重载'<<'左移运算符，输入自定义类型MyInteger_1
ostream& operator<<(ostream& cout, MyInteger_1 myInt) {
	cout << myInt.member_num;
	return cout;
}

void test_1(void) {
	MyInteger_1 myInt;
	cout << ++(++myInt) << endl;
	cout << myInt << endl;
}

void test_2(void) {
	MyInteger_1 myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main(void) {
	test_1();
	int a = 1;
	cout << ++(++a) << endl;
	cout << a << endl;

	test_2();
	// system("pause");
	return 0;
}