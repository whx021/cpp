// 1、模板——函数模板基本语法
//
// C++编程思想：面向对象，泛性编程，主要利用的技术就是模板
//
// C++提供两种模板机制：
//  1、函数模板
//  2、类模板
//
// 函数模板作用：
// 建立一个通用函数，其函数返回值类型，形参类型可以不具体制定，用一个虚拟的类型来代表
//
// 函数模板语法：
//  template<typename T>
//  template<class T>
// 函数声明或定义
//
// 函数模板利用关键字：template
// 使用函数模板的两种类型：自动类型推导，显示指定类型
// 模板的目的：提高复用性，将函数参数化

#include <iostream>
using namespace std;

// 交换两个整形函数
void swapInt(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// 交换两个浮点形函数
void swapDouble(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// 函数模板
// 声明一个模板，T为通用数据类型
template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test_1(void) {
    int a = 10; 
    int b = 20;
    
    // swapInt(a, b);
    
    // 两种方式使用函数模板
    // // 1、自动类型推导
    // mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // double c = 1.1;
    // double d = 2.2;
    
    // // swapDouble(c, d);
    
    // cout << "c = " << c << endl;
    // cout << "d = " << d << endl;
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}