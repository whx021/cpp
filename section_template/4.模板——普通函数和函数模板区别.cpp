// 4、模板——普通函数和函数模板区别
//
// 区别：
//  1、普通函数类型调用时可以发生自动类型转换（隐式类型转换）
//  2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//  3、函数模板调用时，如果利用指定类型方式，可以发生隐式类型转换
//
// 总结：
//  建议使用显示指定类型方式调用函数模板，因为可以确定自己的通用类型T

#include <iostream>
using namespace std;

// 普通函数（可以发生自动类型转换）
int myAdd_1(const int& a, const int& b) {
    return (a + b);
}

// 函数模板
template<class T>
T myAdd_2(const T& a, const T& b) {
    return (a + b);
}

void test_1(void) {
    int a = 10; 
    int b = 20;

    // 普通函数（可以发生自动类型转换）(int型 转换为 char型)
    char c = 'c';
    cout << myAdd_1(a, c) << endl;

    // 函数模板（自动类型推导）不会发生隐式类型转换
    // cout << myAdd_2(a, c) << endl;    //错误
    
    // 原因：无法推出 统一的通用的数据类型T

    // 函数模板（显示指定类型）可以发生隐式类型转换
    cout << myAdd_2<int>(a, c) << endl;
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}