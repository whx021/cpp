// 47、文件操作——二进制文件——读文件
//
// 二进制方式读文件主要利用流对象成员函数read
// 函数原型：
//	istream& read(char* buffer, int len);
//	parameter1：字符指针buffer指向内存中一段存储空间
//	parameter2：len读写的字节数(可以使用函数sizeof()获取)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
	char member_name[64];
	int member_age;
};

void test(void) {
	// 1、包含头文件

	// 2、创建流对象
	ifstream ifs;

	// 3、打开文件并判断文件是否打开成功
	ifs.open("person46.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	// 4、读文件
	// 使用实例对象p接受二进制文件输出
	// ？：不知道二进制文件中的存储的某种类型的数据个数怎样全部读取二进制文件
	
	// ？：不知道二进制文件中的存储的数据类型，怎样读取（文件后缀名：判断文件类型）
	// 答:二进制文件读取函数在设计程序时编写,可直接根据程序对象中的存储的数据类型编写对应的读取函数
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.member_name << "\t年龄：" << p.member_age << endl;
	
	// 5、关闭文件
	ifs.close();
}

int main(void) {
	test();
	// system("pause");
	return 0;
}