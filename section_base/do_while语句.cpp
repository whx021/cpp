// 23、do...while语句

#include <iostream>
using namespace std;

int main(void) {
	int num = 0;
	// do...while和while的区别在于，do...while会先执行一次循环语句
	do {
		cout << num << endl;
		++num;
	} while (num);

	while (num) {
		cout << num << endl;
		++num;
	}

	// system("pause");
	return 0;
}