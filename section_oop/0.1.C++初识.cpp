// 0_1、C++初识

// 包含头文件，输入输出流（类似于C中的stdio.h）
// i:input	o:output	stream 流 

#include <iostream>	

// C++头文件风格：不带.h后缀名
#include <time.h>	// C风格
#include <ctime>	// C++风格
#include <math.h>	// C风格
#include <cmath>	// C++风格

// 使用标准命名空间
using namespace std;

// 程序入口函数
int main(void) {
	// cout：标准输出流对象，可以利用这个对象，像屏幕上打印信息
	// "<<"：插入运算符，C++中进行了重载，配合cout，输出信息
	// C++提倡使用cout，C输出需要记住转义字符（"%d"，"%f"，"%c"，"%lf"等）
	// endl：end line	刷新缓存区并且换行，C++提倡使用endl;换行
	// C中换行在不同系统中不一样，(linux：\n)(windows：\r\n)(maxOS：\r)
	cout << "hello c++" << endl;

	// 两个语句相同
	cout << endl;			// endl：刷新缓存区并且换行
	cout << "\n" << fflush;	// fflush：刷新缓存区

	// 面向过程：
	// 程序 = 数据结构 + 算法

	// C++思想：
	// 面向对象(opp:Object Oriented Programming)
	// 泛型编程
	
	// 面向对象：
	// 面向对象三大特性：封装、继承、多态
	// 对象 = 数据结构 + 算法
	// 程序 = 对象 + 对象 + 对象 + ...

	return EXIT_SUCCESS;
}