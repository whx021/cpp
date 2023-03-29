// 55、结构体嵌套结构体
// 作用：结构体中的成员可以是另一个结构体

#include <iostream>
#include <string>
using namespace std;

// 定义学生的结构体
struct Student {
	string name;
	int age;
	int score;
};

// 定义老师的结构体
struct Teacher {
	int id;
	string name;
	int age;
	struct Student stu;
};

int main(void) {
	Teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "老师姓名：" << t.name << "老师编号：" << t.id << "老师年龄" << t.age << "老师辅导的学生姓名：" << t.stu.name << "学生年龄" << t.stu.age << "学生成绩：" << t.stu.score << endl;

	// system("pause");
	return 0;
}