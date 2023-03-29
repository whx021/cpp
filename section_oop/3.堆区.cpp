// 3、堆区

#include <iostream>
using namespace std;

int* function() {
	// new关键字，在堆区开辟内存空间
	// p指针：局部变量，存放在栈区
	// p指针维护的数据，存放在堆区
	int* p = new int(10);
	return p;
}

int main(void) {
	// 在堆区开辟空间

	int* p = function();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	// system("pause");
	return 0;
}