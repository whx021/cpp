#include <iostream>
using namespace std;

int main(void) {
	// 1、short整型（-32768 ~ 32767）
	short num1 = 32768;
	// 2、int整型
	int num2 = 32768;
	// 3、long整型
	long num3 = 10;
	// 4、long long整型
	long long num4 = 10;

	//sizeof(数据类型/变量)
	cout << "num1 = " << num1 << endl;
	cout << "short类型所占内存空间为：" << sizeof(short) << endl;

	cout << "num2 = " << num2 << endl;
	cout << "int类型所占内存空间为：" << sizeof(int) << endl;

	cout << "num3 = " << num3 << endl;
	cout << "long类型所占内存空间为：" << sizeof(long) << endl;

	cout << "num4 = " << num4 << endl;
	cout << "long long类型所占内存空间为：" << sizeof(long long) << endl;
	// short < int <= long <= long long 	

	return 0;
}