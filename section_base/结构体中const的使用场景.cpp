// 57、结构体中const的使用场景
// 作用：用const防止误操作

// 值传递耗费空间
// 采用传地址的方式调用函数，
// 函数中参数改为指针，可以减少内存空间，不会复制一个新的副本

#include <iostream>
#include <string>
using namespace std;

// 定义结构体变量
struct Student {
	string name;
	int age;
	int score;
};

void print_students(const Student* p) {
	// p->age = 150;	// 加入const之后，一旦有修改就会报错，可以防止误操作
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
}

int main(void) {
	// 创建结构体变量
	Student s = {"张三", 15, 70};
	// 通过函数打印结构体变量的信息
	print_students(&s);
	cout << "函数外侧 年龄：" << s.age << endl;

	// system("pause");
	return 0;
}