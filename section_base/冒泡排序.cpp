// 36、冒泡排序
#include <iostream>
using namespace std;

int main(void) {
	// 利用冒泡排序实现升序序列
	int array[9] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	cout << "排序前的结果：" << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
		cout << array[i] << "\t";
	}
	cout << endl;

	// 排序的次数 = 元素的个数 - 1;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]) - 1; ++i) {
		//每轮对比的次数 = 元素的个数 - 排序的轮数(i + 1);
		for (int j = 0; j < 9 - i - 1; ++j) {
			//若array[j] > array[j + 1]，交换两个数字
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	//冒泡排序后的结果
	cout << "冒泡排序后的结果：" << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
		cout << array[i] << "\t";
	}
	cout << endl;

	// system("pause");
	return 0;
}