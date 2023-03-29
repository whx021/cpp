// auto (since C++11) 语法糖
// 自动推导数据类型

/*
 * 用途 : 
 *  1.代替冗长复杂的变量声明
 *  2.在模板中, 用于声明以来模板参数的变量
 *  3.函数模板以来模板参数的返回值
 *  4.lambda表达式中
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// past write
void test_1(void) {
    list<string> c;
    // ...
    list<string>::iterator ite;
    ite = find(c.begin(), c.end(), "target");
}

// now write
void test_2(void) {
    list<string> c;
    // ...
    auto ite = find(c.begin(), c.end(), "target");

    // auto 必须立即推出数据类型
    // auto ite;    // [Error] 无法推导“auto”类型(需要初始值设定项)
    // ite = find(c.begin(), c.end(), "target");
} 

double func(int a, double b, const char* c, float d, short e, long f) {
    std::cout << "a = " << a << "b = " << b << "c = " << c << "d = " << d << "e = " << e << "f = " << f << std::endl;
    return 5.5;
}

void test_3(void) {
    // 声明函数指针
    double (*pf)(int, double, const char*, float, short, long);
    pf = func;
    pf(1, 2, "wang", 3, 4, 5);

    // 使用auto
    auto pf1 = func;
    pf1(1, 2, "wang", 3, 4, 5);
}

int main(void) {
    test_3();
    return EXIT_SUCCESS;
}