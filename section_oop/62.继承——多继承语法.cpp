// 62、继承——多继承语法
// C++中允许一个类继承多个类
//
// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2... 
//
// 多继承可能引发父类中同名	成员出现，需要加作用于区分，否则产生二义性错误
// 
// C++实际开发中不建议用多继承

#include <iostream>
using namespace std;

class Base_1 {
public:
	Base_1() : member_A(100) {
		// member_A = 100;
	}
	int member_A;
};

class Base_2 {
public:
	Base_2() : member_A(200) {
		// member_A = 200;
	}
	int member_A; 
};

// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2...	
class Son : public Base_1, public Base_2 {
public:
	Son() : member_C(300), member_D(400) {
		// member_C = 300;
		// member_D = 400;
	}
	int member_C;
	int member_D;
};

void test(void) {
	Son s;
	cout << "size of Son = " << sizeof(Son) << endl;
	// 当父类中出现了同名成员，需要加作用域区分
	cout << "Base_1 中 member_A = " << s.Base_1::member_A << endl;
	cout << "Base_2 中 member_A = " << s.Base_2::member_A << endl;
}

int main(void) {
	test();  
	// system("pause");
	return EXIT_SUCCESS;
}