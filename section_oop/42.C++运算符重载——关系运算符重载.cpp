// 42、C++运算符重载——关系运算符重载
// 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

#include <iostream>
#include <string>
using namespace std;

// 关系运算符重载

class Person {
public:
	Person(string name, int age) : member_name(name), member_age(age) {
		// member_name = name;
		// member_age = age;
	}

	// 重载关系运算符'=='
	bool operator==(Person& p) {
		if (this->member_name == p.member_name && this->member_age == p.member_age) {
			return true;
		}
		return false;
	}

	// 重载关系运算符'!='
	bool operator!=(Person& p) {
		if (this->member_name == p.member_name && this->member_age == p.member_age) {
			return false;
		}
		return true;
		
		// // 一下代码效果相同（德摩根律）
		// if (this->member_name != p.member_name || this->member_age != p.member_age) {
		// 	return true;
		// }
		// return false;
	}
	string member_name;
	int member_age;
};


void test_1(void) {
	Person p1("Tom", 18);
	Person p2("Tom", 18);

	if (p1 == p2) {
		cout << "p1和p2相等" << endl; 
	}
	else {
		cout << "p1和p2不相等" << endl;
	}

	if (p1 != p2) {
		cout << "p1和p2不相等" << endl;
	}
	else {
		cout << "p1和p2相等" << endl;
	}
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}