// 16、封装案例
#include <iostream>
#include <string>
using namespace std;

// 设计学生类
class Student {
public:	// 公共权限
	// 类中的属性和行为统一称为：成员
	// 属性又称：成员属性、成员变量
	// 行为又称：成员函数、成员方法

	// 属性
	string member_name;	// 姓名
	string member_id;	// 学号

	// 行为
	void setName(string name) {
		member_name = name;
	}
	void setId(string id) {
		member_id = id;
	}
	// 显示姓名和学号
	void showInfo() {
		cout << "姓名：" << member_name << '\t';
		cout << "学号：" << member_id << endl;
	}
};


int main(void) {
	// 实例化对象
	Student s1;
	// s1.member_name = "张三";
	s1.setName("张三");
	// s1.member_id = "1";
	s1.setId("1");
	s1.showInfo();

	Student s2;
	// s2.member_name = "李四";
	s2.setName("李四");
	// s2.member_id = "2";
	s2.setId("2");
	s2.showInfo();

	// system("pause");
	return 0;
}