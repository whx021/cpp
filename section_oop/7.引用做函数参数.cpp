// 7、引用做函数参数
// 作用：函数传参数时，可以应用引用的技术让形参修改实参
// 优点：可以简化指针修改实参
// 总结：通过应用参数产生的效果同按地址是一样的，引用的语法更加清晰简单

#include <iostream>
using namespace std;

// 交换函数

// 1、值传递
void swap_1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "in swap_2 a = " << a << endl;
	cout << "in swap_1 b = " << b << endl;
}

// 2、地址传递
void swap_2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 3、引用传递
void swap_3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	int a = 10;
	int b = 20;

	// 值传递，形参不会修改实参
	swap_1(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 地址传递，形参会修改实参
	swap_2(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 引用传递，形参会修改实参
	swap_3(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// system("pause");
	return 0;
}