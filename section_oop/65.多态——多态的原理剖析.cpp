// 65、多态——多态的原理剖析

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
	// // 重写：函数返回值类型 函数名称 参数列表 完全相同
	// // virtual可写可不写
	// virtual void Speak(void) {
	// 	cout << "小猫在说话" << endl;
	// }
};

// 狗类
class Dog : public Animal {
public:
	void Speak(void) {
		cout << "小狗在说话" << endl;
	}
};

// 执行说话的函数
// 地址早绑定：在编译阶段就确定了函数的地址

// 动态多态的满足条件
//	1、有继承关系
//	2、子类要重写父类的虚函数

// 动态多态使用：
//	父类的指针或引用 指向子类的对象

void doSpeak(Animal& animal) {
	animal.Speak();
}

void test_1(void) {
	Cat cat;
	// C++中允许 父类 与 子类 之间的类型转换
	// Animal64& animal = cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test_2(void) {
	cout << "size of Animal = " << sizeof(Animal) << endl;	// 4Byte	一个vfptr大小
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return EXIT_SUCCESS;
}