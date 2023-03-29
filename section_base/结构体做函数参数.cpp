// 56、结构体做函数参数
// 将结构体作为参数向函数中传递
// 传递的方式
// 1、值传递
// 2、地址传递

#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

void print_student1(struct Student s);
void print_student2(struct Student* p);

int main(void) {
	Student s;
	s.name = "张三";
	s.age = 20;
	s.score = 85;

	print_student1(s);
	print_student2(&s);
	cout << "main函数中打印 姓名：" << s.name << '\t' << "年龄：" << s.age << '\t' << "分数：" << s.score << endl;

	// system("pause");
	return 0;
}

// 1、值传递
void print_student1(struct Student s) {
	s.age = 100;
	cout << "子函数中 姓名：" << s.name << '\t' << "年龄：" << s.age << '\t' << "分数：" << s.score << endl;
}

// 2、地址传递
void print_student2(struct Student* p) {
	p->age = 200;
	cout << "子函数二中 姓名：" << p->name << '\t' << "年龄：" << p->age << '\t' << "分数：" << p->score << endl;
}