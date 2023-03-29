// 20、switch语句

/*
 switch语句缺点：只能判断整型、字符型，不可以是一个区间
 switch语句优点：结构清晰、执行效率高
 */

#include <iostream>
using namespace std;

int main(void) {
	// 给电影进行打分
	// 10~9	经典
	// 8~7 	非常好
	// 6~5 	一般
	// 5以下 烂片
	
	cout << "请给电影进行打分：" << endl;
	int score = 0;
	cin >> score;
	cout << "您打的分数是：" << endl;

	// 根据用户输入的结果提示用户最后的结果
	switch (score) {
	case 10:
		cout << "您认为是经典电影" << endl;
		break;	// 退出当前分支
	case 9:
		cout << "您认为是经典电影" << endl;
		break;
	case 8:
		cout << "您认为电影非常好" << endl;
		break;
	case 7:
		cout << "您认为电影非常好" << endl;
		break;
	case 6:
		cout << "您认为电影一般" << endl;
		break;
	case 5:
		cout << "您认为电影一般" << endl;
		break;
	default:
		cout << "您认为电影是烂片" << endl;
		break;
	}

	return 0;
}