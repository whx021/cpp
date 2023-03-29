// 14

// 顺序结构：程序顺序执行，不发生跳转
// 选择结构：依据条件是否满足，有条件的执行相应语句
// 循环结构：依据条件是否满足，循环多次的执行相应语句

#include <iostream>
using namespace std;

int main(void) {
	// 选择结构中的单行if语句
	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;
	cout << "您输入的分数是：" << score << endl;

	// if语句
	// 注意事项：if判断语句后面，不要加分号
	if (score > 600) {
		cout << "恭喜您！" << endl;
	}

	return 0;
}