// 17、嵌套if语句
#include <iostream>
using namespace std;

int main(void) {
	int score = 0;
	cout << "请您输入考试分数：" << endl;
	cin >> score;
	cout << "您的分数是：" << score << endl;

	if (score > 600) {
		cout << "A" << endl;
		if (score > 700) {
			cout << "A+" << endl;
		}
		else if (score > 650) {
			cout << "A=" << endl;
		}
		else {
			cout << "A-" << endl;
		}
	}
	else if (score > 500) {
		cout << "B" << endl;
	}
	else if (score > 400) {
		cout << "C" << endl;
	}
	else {
		cout << "D" << endl;
	}

	// system("pause");
	return 0;
}