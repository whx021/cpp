// 0_4、using声明和using编译指令

#include <iostream>
using namespace std;

namespace LOL {
	int sunWuKong = 1;
}

namespace KingGlory {
	int sunWuKong = 3;
}

// 1、using声明
void test_1(void) {
	// int sunWuKong = 2;

	// 1、using声明
	// 注意：using声明和就近原则，有二义性错误，不要同时出现，尽量避免
	using LOL::sunWuKong;
	cout << sunWuKong << endl;
}

// 2、using编译指令
void test_2(void) {
	int sunWuKong = 2;
	
	// using编译指令和就近原则同时出现，优先就近原则
	using namespace LOL;
	using namespace KingGlory;
	// 当使用多个using编译指令，并且重名的情况，使用数据应当加作用域
	cout << sunWuKong << endl;	// 当前函数作用域中的变量
	cout << LOL::sunWuKong << endl;
	cout << KingGlory::sunWuKong << endl;
}

int main(void) {
	test_2();

	return EXIT_SUCCESS;
}