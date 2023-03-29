// 5、模板——普通函数和函数模板的调用规则
//
// 1、如果普通函数和函数模板都可以实现，优先调用普通函数
// 2、可以通过空模板参数列表来强调调用函数模板
// 3、函数模板也可以发生重载
// 4、如果函数模板可以产生更好的匹配，优先调用函数模板
//
// 总结：
//  提供函数模板，最好不要提供普通函数，否则容易产生二义性错误


#include <iostream>
using namespace std;

void myPrint(const int& a, const int& b) {
    cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(const T& a, const T& b) {
    cout << "调用函数模板" << endl;
}

// 函数模板也可以发生重载
template<typename T>
void myPrint(const T& a, const T& b, const T& c) {
    cout << "调用重载函数模板" << endl;
}

void test_1(void) {
    int a = 10, b = 20;
    // 如果普通函数和函数模板都可以实现，优先调用普通函数
    // 如果普通函数只声明，未实现，依然会调用普通函数，但程序会在编译阶段产生错误
    // myPrint(a, b);

    // 可以通过空模板参数列表来强调调用函数模板
    myPrint<>(a, b);

    // 函数模板也可以发生重载
    myPrint(a, b, 100);

    // 如果函数模板可以产生更好的匹配（不用发生隐式类型转换），优先调用函数模板
    char c = 'a';
    char d = 'b';
    myPrint(c, d);
}

int main(void) {
    test_1();   
    return EXIT_SUCCESS;
}