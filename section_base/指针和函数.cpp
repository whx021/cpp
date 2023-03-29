// 50、指针和函数
// 作用：利用指针作为函数的参数，可以修改实参的值
// 应用：想修改实参，使用地址传递；不想修改实参，使用值传递

#include <iostream>
using namespace std;

void swap01(int num1, int num2);
void swap02(int* p1, int* p2);

int main(void) {
	// 1、值传递
	// 不可以修改实参，原理：内存中实参和形参是不同内存的空间
	int a = 10;
	int b = 20;
	swap01(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 2、地址传递
	// 可以修改实参，原理：直接在内存中修改变量的值
	swap02(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// system("pause");
	return 0;
}

void swap01(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "in swap01 num1 = " << num1 << endl;
	cout << "in swap01 num2 = " << num2 << endl;
}

void swap02(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}