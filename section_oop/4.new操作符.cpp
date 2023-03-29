// 4、new操作符

#include <iostream>
using namespace std;

// 1、new的基本语法
int* function(void) {
	int* p = new int(10);
	return p;
}

void test_1(void) {
	int* p = function();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	
	// 由程序员管理分配和释放
	// 使用delete操作符删除分配在堆区的空间
	delete p;
	// cout << *p << endl;	// 错误：内存已被释放，再次访问就是非法操作
}

// 2、使用new在堆区开辟数组
void test_2(void) {
	// 在堆区分配长度为10的int型数组
	int* array = new int[10];
	// 给堆区的数组赋初始值
	for (int i = 0; i < 10; ++i) {
		array[i] = i + 100;
	}
	// 访问堆区的数组中的元素
	for (int i = 0; i < 10; ++i) {
		cout << array[i] << endl;
	}
	// 释放堆区数组时，要加[]
	delete[] array;
}


int main(void) {
	test_1();
	test_2();

	// system("pause");
	return 0;
}