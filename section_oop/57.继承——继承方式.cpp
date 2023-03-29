// 57、继承——继承方式
//
// 继承语法：
//	class 子类 : 继承方式 父类
//  
// 三种继承方式：
// 	1、公有继承
// 	2、保护继承
// 	3、私有继承

#include <iostream>
using namespace std;

class Base_1 {
public:
	int member_A;
protected:
	int member_B;
private:
	int member_C;
};

// 1、公共继承
class Son_1 : public Base_1 {
public:
	void function(void) {
		// 公共继承方式
		// 
		// 父类中的public权限成员，可以被子类以public方式继承，权限为public权限，
		// 该成员在子类Son_1中为public权限，该成员在子类外，能被访问，能被继承
		member_A = 10;	
		// 父类中的protected权限成员，可以被子类以public方式继承，权限为protected权限
		// 该成员在子类Son_1中为protected权限，该成员在子类外，不能被访问，能被继承
		member_B = 10;	
		// 父类中的private权限成员，不可以被子类以public方式继承
		// member_C = 10;
	}
};

void test_1(void) {
	Son_1 s1;

	// 该成员在子类Son_1中为public权限，该成员在子类外，能被访问，能被继承
	s1.member_A = 100;

	// 该成员在子类Son_1中为protected权限，该成员在子类外，不能被访问，能被继承
	// s2.member_B = 100;
}


class Base_2 {
public:
	int member_A;
protected:
	int member_B;
private:
	int member_C;
};

// 2、保护继承
class Son_2 : protected Base_2 {
public:
	void function(void) {
		// 保护继承方式
		//
		// 父类中的public权限成员，可以被子类以protected方式继承，权限为protected权限，
		// 该成员在子类Son_2中为protected权限，该成员在子类外，不能被访问，能被继承
		member_A = 100;
		// 父类中的protected权限成员，可以被子类以protected方式继承，权限为protected权限
		// 该成员在子类Son_2中为protected权限，该成员在子类外，不能被访问，能被继承
		member_B = 100;
		// 父类中的私有权限成员，不可以被子类以protected方式继承
		// member_C = 100;
	}
};

void test_2(void) {
	Son_2 s2; 
	// 该成员在子类Son_2中为protected权限，该成员在子类外，不能被访问，能被继承
	// s2.member_A = 1000;
	
	// 该成员在子类Son_2中为protected权限，该成员在子类外，不能被访问，能被继承
	// s2.member_B = 1000;
}


class Base_3 {
public:
	int member_A;
protected:
	int member_B;
private:
	int member_C;
};

// 3、私有继承
class Son_3 : private Base_3 {
public:
	void function(void) {
		// 私有继承方式

		// 父类中的public权限成员，可以被子类以private方式继承，权限为private权限，
		// 该成员在子类Son_3中为private权限，该成员在子类外，不能被访问，不能被继承
		member_A = 100;
		// 父类中的protected权限成员，可以被子类以private方式继承，权限为private权限
		// 该成员在子类Son_3中为private权限，该成员在子类外，不能被访问，不能被继承
		member_B = 100;
		// 父类中的私有权限成员，不可以被子类以private方式继承
		// member_C = 100;
	}
};

void test_3(void) {
	Son_3 s3;
	// 该成员在子类Son_3中为private权限，该成员在子类外，不能被访问，不能被继承
	// s3.member_A = 1000;
	// 该成员在子类Son_3中为private权限，该成员在子类外，不能被访问，不能被继承
	// s3.member_B = 1000;
}

class GrandSon_3 : public Son_3 {
public:
	void function(void) {
		// 该成员在子类Son_3中为private权限，该成员在子类外，不能被访问，不能被继承
		// member_A = 1000;
		// member_B = 1000;
	}
};

int main(void) {
	// system("pause");
	return EXIT_SUCCESS;
}