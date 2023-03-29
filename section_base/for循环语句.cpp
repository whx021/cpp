// 25、for循环语句

#include <iostream>
using namespace std;
int main(void) {
	for (int i = 0; i < 10; ++i) {
		cout << i << endl;
	}

	int n = 0;
	for (; ; ) {
		if (n >= 10) {
			break;
		}
		cout << n << endl;
		++n;
	}

	// system("pause");
	return 0;
}