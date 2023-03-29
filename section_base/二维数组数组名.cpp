// 38、二维数组的数组名用途

#include <iostream>
using namespace std;

int main(void) {
	// 1、查看二维数组所占的内存空间
	int array[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	cout << "二维数组所占用的内存空间为：" << sizeof(array) << endl;
	cout << "二维数组一行所占用的内存空间：" << sizeof(array[0]) << endl;
	cout << "二维数组每个元素占用的内存空间：" << sizeof(array[0][0]) << endl;
	cout << "二维数组一共有 " << sizeof(array) / sizeof(array[0]) << " 行" << endl;
	cout << "二维数组一共有 " << sizeof(array[0]) / sizeof(array[0][0]) << " 列" << endl;
	cout << "二维数组一共有 " << sizeof(array) / sizeof(array[0][0]) << " 元素" << endl;

	// 2、获取二维数组的首地址
	cout << "二维数组的首地址为：" << array << endl;
	cout << "二维数组的第一行首地址为：" << array[0] << endl;
	cout << "二维数组的第二行首地址为：" << array[1] << endl;

	cout << "二维数组的第一个元素的首地址：" << &array[0][0] << endl;
	cout << "二维数组的第二个元素的首地址：" << &array[0][1] << endl;

	// system("pause");
	return 0;
}