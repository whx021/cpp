// 45、指针
// 指针的作用：通过指针间接访问内存
// 内存：存储变量
// 内存地址：变量在内存中的地址
// 利用指针变量保存地址

#include <iostream>
using namespace std;

int main(void) {
	// 1、定义指针
	int a = 10;
	// 指针定义的语法：数据类型 * 指针变量名;
	int* p;
	// 让指针记录变量的地址
	p = &a;

	cout << "a的地址为：" << &a << endl;
	cout << "指针p为：" << p << endl;

	// 2、使用指针
	// 通过解应用的方式来找到指针指向的内存
	// 解引用：指针前面加一个'*'，指针指向的内存中的数据
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	// system("pause");
	return 0;
}