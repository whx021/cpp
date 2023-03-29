// 58、结构体案例1
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

struct Student {
	string sName;
	int score;
};

// 老师的结构体类型定义
struct Teacher {
	string tName;		// 老师姓名
	Student sArray[5];	// 学生数组
};

// 给老师和学生赋值的函数
void allocateSpace(Teacher tArray[], int length) {
	// 给老师赋值
	string nameSeed = "ABCDE";
	for (int i = 0; i < length; ++i) {
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];

		// 通过循环给老师带的学生赋值
		for (int j = 0; j < 5; ++j) {
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			int random = rand() % 61 + 40;	// 40 ~ 100
			tArray[i].sArray[j].score = random;
		}
	}
}

// 打印所有信息的
void printInfo(Teacher tArray[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << "老师的姓名：" << tArray[i].tName << endl;
		for (int j = 0; j < 5; ++j) {
			cout << "\t学生姓名：" << tArray[i].sArray[j].sName
				<< " 学生分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main(void) {
	srand((unsigned int)time(NULL));
	// 1、创建3名老师的数组
	struct Teacher tArray[3];

	// 2、通过函数给三名老师的信息赋值，并且给老师带的学生也赋值
	int length = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, length);

	// 3、打印所有老师及所带的学生的信息
	printInfo(tArray, length);

	// system("pause");
	return 0;
}