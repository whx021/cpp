// 15、选择结构中的多行if语句

#include <iostream>
using namespace std;

int main(void) {
	// 1、输入考试分数
	int score = 0;
	cout << "请输入一个考试分数：" << endl;
	cin >> score;
	// 2、提示用户输入的分数
	cout << "您输入分数为：" << score << endl;
	// 3、判断
	if (score > 600) {
		cout << "您考上了！" << endl;
	}
	else {
		cout << "您没有考上。" << endl;
	}
	// system("pause");
	return 0;
}