#include <iostream>
using namespace std;

int main(void) {
	//逻辑运算符

	// ！非
	int a = 10;

	// C++中除了0都为真
	cout << !a << endl;
	cout << !!a << endl;

	// && 与
	int a2 = 10, b2 = 10;
	cout << (a2 && b2) << endl;

	a2 = 0;
	b2 = 10;
	cout << (a2 && b2) << endl;

	a2 = 0;
	b2 = 0;
	cout << (a2 && b2) << endl;

	// || 或
	int a3 = 10, b3 = 10;
	cout << (a3 || b3) << endl;

	a3 = 10;
	b3 = 0;
	cout << (a3 || b3) << endl;

	a3 = 0;
	b3 = 0;
	cout << (a3 || b3) << endl;

	// system("pause");
	return 0;
}