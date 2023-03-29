// 22、猜数字

#include <iostream>
#include <ctime>
using namespace std;

int main(void) {
	// 从新播种：利用当前系统时间生成随机数
	srand((unsigned int)time(NULL)); 

	// 1、系统生成随机数
	int num = rand() % 100 + 1;	// rand()%100+1 生成0+1~99+1的随机数
	cout << num << endl;
	// 2、玩家进行猜测
	int val = 0;


	cin >> val;
	// 3、判断玩家的猜测
	while (1) {
		// 猜错：提示猜的结果，过大或则过小，从新返回第二步
		if (val > num) {
			cout << "猜测过大" << endl;
		}
		else if (val < num) {
			cout << "猜测过小" << endl;
		}
		// 猜对：退出游戏
		else if (val = num) {
			cout << "猜测正确" << endl;
			break;	// 退出循环
		}
		cin >> val;
	}
	
	// system("pause");
	return 0;
}