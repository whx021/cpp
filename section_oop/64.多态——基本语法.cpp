// 64、多态——基本语法
// 静态多态 : 函数重载, 运算符重载, 函数地址早绑定(编译阶段确定函数地址)
// 动态多态 : 派生类和虚函数, 函数地址晚绑定(运行阶段确定函数地址)		
#include <iostream>
using namespace std;

// 动物类
class Animal {
public:
	// 虚函数
	virtual void Speak(void) {
		cout << "动物在说话" << endl;
	}
};

// 猫类
class Cat : public Animal {
public:
	// 重写：函数返回值类型 函数名称 参数列表 完全相同
	// virtual可写可不写
	virtual void Speak(void) {
		cout << "小猫在说话" << endl;
	}
};

// 狗类
class Dog : public Animal {
public:
	void Speak(void) {
		cout << "小狗在说话" << endl;
	}
};

// 执行说话的函数
// 地址早绑定：在编译阶段就确定了函数的地址（静态绑定）

// 动态多态的满足条件
//	1、有继承关系
//	2、子类要重写父类的虚函数

// 动态多态使用：
//	父类的指针或引用指向子类的对象

void doSpeak(Animal& animal) {
	animal.Speak();
}

void test_1(void) {
	Cat cat;
	// C++中允许 父类 与 子类 之间的类型转换
	// Animal& animal = cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}