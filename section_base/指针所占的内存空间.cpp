// 46、指针所占的内存空间
// 与所指向的数据类型无关
// 32位操作系统：指针占用4byte（32bit）
// 64位操作系统：指针占用8byte（64bit）

#include <iostream>
using namespace std;

int main(void) {
	int a = 10;
	int* p = &a;

	cout << "size of (int*) = " << sizeof(int*) << endl;
	cout << "size of (float*) = " << sizeof(float*) << endl;
	cout << "size of (double*) = " << sizeof(double*) << endl;
	cout << "size of (char*) = " << sizeof(char*) << endl;

	// system("pause");
	return 0;
}