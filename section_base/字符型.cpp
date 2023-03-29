#include <iostream>
using namespace std;

int main(void) {
	// 1、字符型变量创建方式
	char ch = 'a';
	cout << ch << endl;

	// 2、字符型变量所占空间大小
	cout << "char型变量所占的内存：" << sizeof(ch) << endl;

	// 3、字符型变量常见错误
	// char ch2 = "b";	//创建字符型变量时要用单引号
	// char ch3 = 'abcdef';//创建字符型变量时，单引号中只能有一个字符

	// 4、字符型变量对应的ASCII码
	// a - 97
	// A - 65
	cout << (int)ch << endl;

	// system("pause");
	return 0;
}