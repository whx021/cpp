// 28、乘法口诀表

#include <iostream>
using namespace std;

int main(void) {
	// 列数 * 行数 = 计算结果
	// 列数 <= 行数

	for (int i = 1; i <= 9; ++i) {
		// cout << i << endl; // 打印行数
		for (int j = 1; j <= i; ++j) {
			cout << j << "*" << i << j * i << "\t"; // 打印列数
		}
		cout << endl;
	}
	
	// system("pause");
	return 0;
}