// 23、构造函数的分类及调用
//
// 两种分类方式：
// 	按参数分为：有参构造和无参构造
// 	按类型分为：普通构造和拷贝构造
// 
// 三种调用方法：
//  括号法
// 	显示法
// 	隐式转换法

#include <iostream>
using namespace std;

class Person {
public:
	// 构造函数两种分类方式：
	
	// 按参数分为：
	// 	无参构造（默认构造）
	Person() {
		cout << "Person的无参构造函数调用" << endl;
	}
	// 	有参构造
	Person(int a) {
		member_age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	// 按类型分为：
	//	拷贝构造函数
	Person(const Person& p) {
		// 将传入的对象的信息的所用属性，拷贝到我身上
		member_age = p.member_age;
		cout << "Person的有参拷贝构造函数调用" << endl;
	}

	~Person() {
		cout << "Person的析构函数调用" << endl;
	}
	
	int member_age;
};

// 调用
void test(void) {
	// 1、括号法
	Person p1;		// 默认构造函数调用
	Person p2(10);	// 有参构造函数调用
	Person p3(p2);	// 拷贝构造函数调用
	// 注意事项1：
	// 调用默认构造函数时，不要加"()"
	// 原因：因为下一行代码，
	// 编译器会认为是一个函数的声明（返回值为Person类型，函数名为p1，无参数）
	// 不会认为在创建一个对象
	// Person p1();

	// void function();	// 在函数体内声明的函数（作用域为函数体内部）

	// 拷贝构造的作用
	cout << "p2的年龄：" << p2.member_age << endl;
	cout << "p3的年龄：" << p3.member_age << endl;

	// 2、显示法
	Person p4;				// 默认构造函数调用
	Person p5 = Person(10);	// 有参构造函数调用	
	Person p6 = Person(p5);	// 拷贝构造函数调用

	// 匿名对象
	// 特点：当前行执行结束后，系统会立即回收释放掉匿名对象
	Person(10);
	cout << "aaaaa" << endl;

	// 注意事项2：
	// 不要利用拷贝构造函数，初始化匿名对象
	// 重定义错误：编译器认为是一个对象的声明
	// 编译器认为：Person(p6) == Person p6，和要拷贝的对象重定义
	// Person(p6);

	// 3、隐式转换法
	// 编译器转化为：Person p7 = Person(10);			有参构造
	Person p7 = 10;	

	// 编译器转化为：Person23 p8 = Person23(p7);		有参拷贝构造
	Person p8 = p7;
}


int main(void) {
	test();

	// system("pause");
	return 0;
}