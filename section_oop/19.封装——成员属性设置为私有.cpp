// 19、成员属性设置为私有 
// 优点1：将所有权限设置为私有，可以自己控制读写权限
// 优点2：对于写权限，我们可以写入接口（写入成员函数）检测数据的有效性

#include <iostream>
#include <string>
using namespace std;

// 设计人类
class Person {
public:
	// 写（设置）姓名
	void setName(string name) {
		member_name = name;
	}
	// 读（获取）姓名
	string getName() {
		return member_name;
	}
	// 读（获取）年龄
	int getAge() {
		// member_age = 0;	// 初始化年龄为0岁
		return member_age;
	}
	// 写（设置）年龄
	void setAge(int age) {
		// 检测数据的有效性
		if (age < 0 || age > 150) {
			member_age = 0;
			cout << "你这个老妖精！" << endl;
			return;
		}
		member_age = age;
	}
	// 写（设置）情人
	void setLover(string lover) {
		member_lover = lover;
	}

private:
	// 姓名	可读可写
	string member_name;
	// 年龄	可读，控制写入
	int member_age;
	// 情人	只写
	string member_lover;
};

int main(void) { 
	Person p;
	p.setName("张三");
	cout << "姓名：" << p.getName() << endl;
	
	// p.member_age = 18;	// 没有提供写入接口，私有权限 
	p.setAge(1000);
	cout << "年龄：" << p.getAge() << endl;

	p.setLover("苍井");
	// cout << "情人：" << p.member_lover << endl;	// 没有提供访问接口，不可以访问

	// system("pause");
	return 0;
}