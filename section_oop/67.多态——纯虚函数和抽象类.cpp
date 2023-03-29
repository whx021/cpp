// 67、多态——纯虚函数和抽象类

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此，可以将虚函数写为纯虚函数 

// 纯虚函数的语法：
//	virtual 返回值类型 函数名(参数列表) = 0;

// 当类中有了纯虚函数，这个类也成为抽象类

// 抽象类特点：
//	1、无法实例化对象
//	2、子类中必须重写父类中的纯虚函数，否则也为抽象类

// 写纯虚函数的意义：
//	强制子类重写虚函数，否则无法实例化对象

#include <iostream>
using namespace std;

class Base {
public:
	// 纯虚函数
	virtual void function(void) = 0;
};

class Son : public Base {
public:
	virtual void function(void) {
		cout << "function函数调用" << endl;
	}
};

void test_1(void) {
	// 错误：抽象类无法实例化对象
	// Base b;		// 在栈区创建对象（实例化对象）
	// new Base;	// 在堆区创建对象（实例化对象）

	// 子类中必须重写父类中的纯虚函数，否则也为抽象类
	// Son s;

	Base* s = new Son;
	s->function();
}

int main(void) {
	test_1();
	return EXIT_SUCCESS;
}