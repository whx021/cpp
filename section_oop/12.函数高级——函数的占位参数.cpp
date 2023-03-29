// 12、函数高级——函数的占位参数
// 函数中的形参列表里可以有占位参数，调用函数时必须填补该位置
// 语法：返回值类型 函数名 (数据类型) {函数体}

#include <iostream>
using namespace std;

// 目前阶段的占位参数，我们还用不到，后面的课程中会用到
// 占位参数可以有默认参数
void function12(int a, int = 10) {
	cout << "This is a function." << endl;
}

int main(void) {
	function12(10);

	// system("pause");
	return 0;
}