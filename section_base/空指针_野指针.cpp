// 47、空指针&野指针
// 
// 空指针和野指针指向不是程序中申请的内存空间，不可以随意访问
// 
// 1、空指针作用：初始化指针变量
// 2、注意：空指针指向的内存不可访问
// （0~255之间的内存编号时系统占用的，不可被访问）
// 
// 1、野指针：指向了程序未申请的内存空间
// 2、程序中尽量避免出现野指针

#include <iostream>
using namespace std;

int main(void) {
	int* null_pointer = nullptr;

	// *p = 100;	// 错误：空指针不可被访问

	int* wild_pointer = (int*)0x1100;

	return 0;
}