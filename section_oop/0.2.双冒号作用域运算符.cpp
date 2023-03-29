// "::"双冒汗作用域运算符

#include <iostream>
using namespace std;

int attack_0 = 1000;

void test(void) {
	int attack_0 = 2000;
	cout << "局部变量：attack = " << attack_0 << endl;
	
	// 如果"::"前没有任何内容，表示使用全局作用域
	cout << "全局变量：attack = " << ::attack_0 << endl;
}

int main(void) {
	test();

	return EXIT_SUCCESS;
}