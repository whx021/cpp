// 19、三目运算符
#include <iostream>
using namespace std;

int main(void) {
	// 创建三个变量a、b、c
	// 将a与b作比较，将较大的赋值给c
	int a = 10, b = 20, c = 0;

	c = (a > b ? a : b);
	cout << "c = " << c << endl;

	// 在C++中，三目运算符返回值是变量，可以继续赋值
	(a < b ? a : b) = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// system("pause");
	return 0;
}