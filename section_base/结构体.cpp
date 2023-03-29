// 52、结构体
// 结构体：用户自定义的数据类型，允许用户存储不同类型的数据

#include <iostream>
using namespace std;

// 1、创建学生的数据类型：学生包括（姓名、年龄、分数）
// 自定义的数据类型，一些类型集合组成的类型
// 语法：struct 类型名称 {成员列表}；
struct Student {
					//成员列表
	string name;	//姓名
	int age;		//年龄
	int score; 		//分数
} s3;

// 2、通过学生类型创建具体学生
// C++中，定义结构体类型时，不可以省略struct关键字
// C++中，创建结构体变量时，可省略struct关键字
// 给s1属性赋值，通过'.'访问结构体变量中的属性

int main(void) {
	// 2.1 struct Student s1;
	Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;
	cout << "姓名：" << s1.name << "年龄：" << s1.age << "分数：" << s1.score << endl;

	// 2.2 struct Student s2 = {初始值};
	struct Student s2 = { "李四", 19, 80};
	cout << "姓名：" << s2.name << "年龄：" << s2.age << "分数：" << s2.score << endl;

	// 2.3 在创建结构体时顺便创建结构体变量
	s3.name = "王五";
	s3.age = 20;
	s3.score = 60;
	cout << "姓名：" << s3.name << "年龄：" << s3.age << "分数：" << s3.score << endl;
	
	// system("pause");
	return 0;
}