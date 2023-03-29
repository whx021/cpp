// reference 语法糖
// 本质 : 
// const (typename)*
// 
// object reference 大小相同 地址相同(全都是假象) 
// sizeof(reference) == sizeof(object)
// &reference == &object

// reference 通常不用于声明变量
// 而用于参数类型(parameter type)和放回类型(return type)的描述

#include <iostream>
using namespace std;

void test_1(void) {
    int x = 0;
    int* p = &x;    // p is a point to x
    int& r = x;     // r is a reference to x
    
    int x2 = 5;
    r = x2;
    int& r2 = r;
}

int main(void) {

    return EXIT_SUCCESS;
}

// pass by value & pass by reference 不能作为函数重载的条件
// 原因 : 函数签名相同("same signature"), 而这不能同时存在, 调用时产生二意性
double imag(const int im);
double imag(const int& im); // [Error] Ambiguity

/* other question : 
Q : 成员函数和成员常函数修饰对象this指针的const是不是函数签名的一部分, 及能否作为函数重载的条件
A : 是
 */