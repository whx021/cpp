#include <iostream>
using namespace std;

int main(void)
{
	// 1、创建bool数据类型
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;

	// 本质上 1代表true 0代表false

	// 2、查看bool类型数据所占空间大小
	cout << "bool类型所占的空间：" << sizeof(bool) << endl;

	// system("pause");
	return 0;
}