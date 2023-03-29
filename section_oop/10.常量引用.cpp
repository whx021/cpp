// 10、常量引用
// 作用：修饰形参，防止误操作

#include <iostream>
using namespace std;

// 打印数据函数：形参为应用类型
// 常量引用：修饰形参，防止误操作
void showValue(const int& a) {
	// a = 1000;
	cout << "a = " << a << endl;
}

int main(void) {
	// int& ref = 10;	// 错误：引用必须引用一块合法的内存空间

	// 加入const后，编译器自动优化代码：int temp = 10; const int& ref = temp;
	const int& ref = 10;
	// ref = 20;	// 错误：加入const后变为只读，不可修改

	int a = 100;
	showValue(a);
	cout << "a = " << a << endl;

	// system("pause");
	return 0;
}