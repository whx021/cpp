#include <iostream>
using namespace std;

int main(void) {
	// 默认情况下 输出一个浮点数，会显示6位有效数字
	// 1、单精度 float
	float f1 = 3.1415926f;
	cout << "f1 = " << f1 << endl;
	// 2、双精度 double
	double d1 = 3.1415926;
	cout << "d1 = " << d1 << endl;

	cout << "float 占用的内存空间为：" << sizeof(float) << endl;
	cout << "double 占用的内存空间为：" << sizeof(double) << endl;

	// 科学计数法
	float f2 = 3e2;		//3 * 10^2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2;	//3 * 10^-2
	cout << "f3 = " << f3 << endl;
	
	// system("pause");
	return 0;
}