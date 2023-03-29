// 49、指针和数组
// 作用：利用指针访问数组中元素

#include <iostream>
using namespace std;

int main(void) {
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << "数组中第一个元素为：" << array[0] << endl;
	int* p = array;	// 数组名就是数组的首地址
	cout << "利用指针访问第一个元素：" << *p << endl;
	++p;	// 让指针向后偏移4个字节
	cout << "利用指针访问第二个元素：" << *p << endl;

	cout << "利用指针遍历数组" << endl;
	int* p2 = array;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
		cout << *p2 << endl;
		++p2;
		// 等效于
		// cout << "第" << i + 1 << "元素的值为：" << *(p2++) << endl;
	}

	// system("pause");
	return 0;
}