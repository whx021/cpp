// 33、一维数组数组名

#include <iostream>
using namespace std;

int main(void) {
	// 数组名是一个常量（存放数组的首地址），不可以进行赋值操作
	// array = 100;

	// 1、可以统计整个数组在内存空间的长度
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "整个数组占用内存空间为：" << sizeof(array) << endl;
	cout << "每个元素占用内存空间为：" << sizeof(array[0]) << endl;
	cout << "数组中元素个数为：" << sizeof(array) / sizeof(array[0]) << endl;
	
	// 2、可以获取数组在内存空间中的首地址
	cout << "数组的地址为：" << array << endl;
	cout << "数组中第一元素的地址为：" << &array[0] << endl;
	cout << "数组中第二元素的地址为：" << &array[1] << endl;

	// system("pause");
	return 0;
}