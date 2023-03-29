// 59、继承——构造和析构顺序
//
// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 
// 问题：父类和子类的构造和析构顺序是谁先谁后？
// 答案：与类对象作为类成员相似（栈区特点：LIFO）
//	类成员构造->类构造->类析构->类成员析构
//	父类构造->子类构造->子类析构->父类析构


#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base构造函数调用" << endl;
	}
	~Base() {
		cout << "Base析构函数调用" << endl;
	}
};

class Son : public Base {
public:
	Son() {
		cout << "Son构造函数调用" << endl;
	}
	~Son() {
		cout << "Son析构函数调用" << endl;
	}
};

void test(void) {
	Son s;
}

int main(void) {
	test(); 
	// system("pause");
	return EXIT_SUCCESS;
}