#include <iostream>
#include <string>
using namespace std;

int main(void) {
	// 1、C风格的字符串
	// 注意事项：char 字符串名[]
	// 注意事项：用双引号包含支付串
	char str[] = "hello C++";
	cout << str << endl;

	// 2、C++风格的字符串
	// 包含头文件string
	string str2 = "hello C++";
	cout << str2 << endl;

	// system("pause");
	return 0;
}