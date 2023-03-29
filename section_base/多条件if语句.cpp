// 16、选择结构中的多条件if语句
#include <iostream>
using namespace std;

int main(void) {
	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;
	cout << "您输入的分数是：" << score << endl;

	// 第一个条件判断
	if (score > 600) {
		cout << "A" << endl;
	}
	// 第二个条件判断
	else if (score > 500) {
		cout << "B" << endl;
	}
	// 第三个条件判断
	else if (score > 400) {
		cout << "C" << endl;
	}
	else {
		cout << "D" << endl;
	}
	
	// system("pause");
	return 0;
}