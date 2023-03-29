// 18、三只小猪称体重

#include <iostream>
using namespace std;

int main(void) {
	// 三只小猪称体重，判断那只小猪最重
	
	// 1、创建三只小猪的体重变量
	int num1 = 0, num2 = 0, num3 = 0;

	// 2、用户输入三只小猪的重量
	cout << "请输入小猪A的体重：" << endl;
	cin >> num1;
	cout << "请输入小猪B的体重：" << endl;
	cin >> num2;
	cout << "请输入小猪C的体重：" << endl;
	cin >> num3;
	cout << "小猪A的体重：" << num1 <<endl;
	cout << "小猪B的体重：" << num2 << endl;
	cout << "小猪C的体重：" << num3 << endl;

	//3、判断那只小猪最重
	if (num1 > num2) {
		if (num1 > num3) {
			cout << "小猪A最重" << endl;
		}
		else {
			cout << "小猪C最重" << endl;
		}
	}
	else {
		if (num2 > num3) {
			cout << "小猪B最重" << endl;
		}
		else {
			cout << "小猪C最重" << endl;
		}
	}

	// system("pause");
	return 0;
}