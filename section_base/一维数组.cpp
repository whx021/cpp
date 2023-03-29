// 32、一维数组

#include <iostream>
using namespace std;

int main(void) {
	/*
	 1、数据类型 数组名[数组长度];
	 2、数据类型 数组名[数组长度] = {值1, 值2, ...}
	 3、数据类型 数组名[] = {值1, 值2, ...};
	 */

	// 1、数据类型 数组名[数组长度];
	int array[5];
	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 40;
	array[4] = 50;
	cout << array[0] << endl;
	cout << array[1] << endl;
	cout << array[2] << endl;
	cout << array[3] << endl;
	cout << array[4] << endl;

	//2、数据类型 数组名[数组长度] = { 值1, 值2, ... }
	//若初始化数组时，没有给全体数组元素赋值，会用0填补剩余的元素
	int array2[5] = {10, 20, 30,};
	for (int i = 0; i < 5; ++i) {
		cout << array2[i] << endl;
	}

	//3、数据类型 数组名[] = { 值1, 值2, ... };
	//定义数组时，必须有初始长度
	int array3[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
	for (int i = 0; i < 9; ++i) {
		cout << array3[i] << endl;
	}

	// system("pause");
	return 0;
}