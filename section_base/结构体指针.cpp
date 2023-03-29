// 54、结构体指针
// 通过结构体的指针访问结构体中的成员
// 利用'->'可以通过结构体指针访问结构体属性

#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

int main(void) {
	// 1、创建结构体变量
	Student s = {"张三", 18, 100};
	
	// 2、通过指针指向结构体变量
	Student* p = &s;

	// 3、通过指针访问结构体变量的数据
	// 利用'->'可以通过结构体指针访问结构体属性
	cout << "姓名" << p->name << "年龄" << p->age << "分数" << p->score << endl;

	// system("pause");
	return 0;
}