// 45、文件操作——文本文件——读文件
// 总结：
// 读文件可以利用ifstream类，或者fstream类
// 利用is_open()函数可以判断文件是否打开成功
// close关闭文件

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test_1(void) {
	// 1、包含头文件

	// 2、创建流对象(输入文件流对象Input File Stream)
	ifstream ifs;

	// 3、打开文件并且判断是否打开成功
	// 本质将流对象ifs与文件"test.txt"关联，并制定关联类型
	ifs.open("test.txt", ios::in);
	// 使用流对象ifs中的成员函数is_open()判断文件是否关联成功
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	// 4、读数据
	// // 第一种
	// char buffer[1024] = { 0 };
	// // 将对象ifs中的字符逐个存入buffer中，知道读到'EOF'
	// while (ifs >> buffer) {
	// 	cout << buffer << endl;
	// }

	// // 第二种
	// char buffer[1024] = { 0 };
	// // 使用ifs对象的成员函数ifs.getline()
	// // 逐行将ifs关联的文件存放入字符数组buffer中，直到为无内容空行（只有'\r'、'\n'空行有内容）
	// while (ifs.getline(buffer, sizeof(buffer))) {
	// 	cout << buffer << endl;
	// }

	// // 第三种
	// string buffer;
	// // 使用全局函数getline()
	// // 逐行将ifs关联的文件存放入字符数组buffer中，直到为无内容空行（只有'\r'、'\n'空行有内容）
	// while (getline(ifs, buffer)) {
	// 	cout << buffer << endl;
	// }

	// 第四种
	char c;
	// 这个字符读
	// EOF：end of file 文件尾部的标志
	// 使用流对象ifs中的成员函数get()逐个将字符存入char型变量c中，直到读取到EOF
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}

	// 5、关闭文件
	ifs.close();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}