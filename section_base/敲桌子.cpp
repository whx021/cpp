// 26、敲桌子
#include <iostream>
using namespace std;

int main(void) {
	// 1、先输出1~100数字
	for (int i = 1; i <= 100; ++i) {
		//2、从100个数字找到特殊数字，打印“敲桌子”
		//若个位有7，十位有7，7的倍数，打印“敲桌子”
		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0) {
			cout << "敲桌子" << endl;
		}
		else {
			cout << i << endl;
		}
	}

	// system("pause");
	return 0;
}