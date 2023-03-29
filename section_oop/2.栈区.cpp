// 2、栈区
// 由编译器管理分配和释放
// 注意事项：不要返回局部变量的地址

#include <iostream>
using namespace std;

int* function(int b) {
	b = 100;
	int a = 10;	// 局部变量，存放在栈区，函数执行结束后自动释放
	return &a;	// 返回局部变量的地址
}

int main(void) {
	int* p = function(1);	// 接受function的返回值

	// 当前取值正确的原因是程序，
	// 该地址在栈区被释放了，
	// 但是还没有被其他函数覆盖
	// 但当前该地址已不属于程序管理维护
	cout << *p << endl;		
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	// system("pause");
	return 0;
}