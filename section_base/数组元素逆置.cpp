// 35、数组元素逆置
#include <iostream>
using namespace std;
int main(void) {
	// 1、创建一个数组
	int array[5] = { 1, 3, 2, 5, 4 };
	cout << "数组逆置前的结果：" << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
		cout << array[i] << "\t";
	}
	cout << endl;
	
	// 2、实现数组的逆置
	// 2.1记录起始索引位置
	// 2.2记录结束索引位置
	// 2.3起始索引位置于结束索引位置的元素交换
	// 2.4++起始索引，--结束索引
	// 2.5循环执行以上四步，知道起始索引 >= 结束索引
	
	int left = 0;
	int right = sizeof(array) / sizeof(array[0]) - 1;
	while (left < right) {
		// 2.3起始索引位置于结束索引位置的元素交换
		int temp = array[left];
		array[left] = array[right];
		array[right] = array[left];
		// 2.4++起始索引，--结束索引
		++left;
		--right;
	}

	// 3、打印逆置后的数组
	cout << "数组逆置后的结果：" << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
		cout << array[i] << "\t";
	}
	cout << endl;

	// system("pause");
	return 0;
}