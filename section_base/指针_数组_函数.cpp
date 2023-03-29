// 51、指针_数组_函数

#include <iostream>
using namespace std;

void bubblingSort(int* array, int length);
void PrintArray(int* array, int length);

int main51(void) {
	// 1、创建一个数组
	int array[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
	int length = sizeof(array) / sizeof(array[0]);
	// 2、创建函数，实现冒泡排序
	bubblingSort(array, length);
	// 3、打印排序后的数组
	PrintArray(array, length);
	
	// system("pause");
	return 0;
}

void bubblingSort(int* array, int length) {
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void PrintArray(int* array, int length) {
	for (int i = 0; i < length; ++i) {
		cout << array[i] << endl;
	}
}