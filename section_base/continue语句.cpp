// 30、continue语句

#include <iostream>
using namespace std;

int main(void) {
	for (int i = 0; i <= 100; ++i) {
		// 若为奇数输出，偶数不输出
		if (i % 2 == 0) {
			continue;	// 可以筛选条件，执行到此，不再执行，执行下一次循环
			// break;	// 退出循环
		}
		cout << i << endl;
	}

	// system("pause");
	return 0;
}