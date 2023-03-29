// 49、externC浅析
// externC的主要用途：C++中调用C语言的文件

#include <iostream>
using namespace std;
#include "49.附加1test.h"

// 解决方式1：告诉编译器，利用C语言的方式链接show函数（函数过多时不方便）
// extern "C" 函数返回值 函数名(函数参数);
// extern "C" void show(void);

// 解决方法2：在头文件中添加条件编译的代码

void test(void) {
	// 可不可以成功调用show()
	// 不可以，编译器使用C++的方式去找show，可能对函数名进行修饰（修饰为_Z4show49v）的形式
	// 无法直接调用C的函数
	show();
}

int main(void) {
	test();
	
	// system("pause");
	return EXIT_SUCCESS;
}