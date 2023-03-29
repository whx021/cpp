// 46、文件操作——二进制文件——写文件
// 指定打开方式：ios::binary
//
// 二进制方式写文件主要利用流对象调用成员函数write
// 函数原型：
//	ostream& write(const char* buffer, int len)
//	parameter1：字符指针buffer指向内存中的一段空间
//	parameter2：len是读写字节数(可以使用函数sizeof()获取)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
	char member_name[64];
	int member_age;
};

void test_1(void) {
	// 1、包含头文件

	// 2、创建流对象
	ofstream ofs;

	// 利用ofstream类中的有参构造函数直接指定打开文件和打开方式
	// ofstream ofs("person46.txt", ios::out | ios::binary);

	// 3、打开文件
	ofs.open("person46.txt", ios::out | ios::binary);

	// 4、写文件
	// 隐式转换法调用构造函数初始化实例对象p
	Person p = { "张三", 18 };
	ofs.write((const char*)&p, sizeof(p));
	
	// 5、关闭文件
	ofs.close();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}