// 50、explicit关键字
// explicit关键字的作用:防止利用隐式法创建对象

#include <iostream>
using namespace std;

class Person {
public:
	// explicit关键字的作用：
	// 防止利用隐式法创建对象
	explicit Person(int a) {
		cout << "Person的构造函数调用" << endl;
	}
};

void test(void) {
	// 构造函数中加入了explicit关键字
	// Person p = 10;

	Person p1(10);

	Person p2 = Person(10);
}

int main(void) {
	test();
	return EXIT_SUCCESS;
}