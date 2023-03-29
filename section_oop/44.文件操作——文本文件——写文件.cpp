// 44、文件操作——文本文件——写文件
// 读文件可以利用ofstream类，或者fstream类
// 利用"<<"可以向文件中写入数据

#include <iostream>
#include <fstream>
using namespace std;

void test_1(void) {
	// 1、包含头文件

	// 2、创建流对象(输出文件流对象Output File Stream)
	ofstream ofs;

	// 3、指定打开方式（输入输出流中的写文件）
	// 本质将流对象ofs使用其成员函数open与文件"test.txt"关联，并制定关联类型
	ofs.open("test.txt", ios::out);

	// 4、写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	// 5、关闭文件
	ofs.close();
}

int main(void) {
	test_1(); 
	// system("pause");
	return 0;
}