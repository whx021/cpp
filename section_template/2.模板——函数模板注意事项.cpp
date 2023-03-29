// 2、模板——函数模板注意事项
//
// 注意事项：
//  1、自动类型推导，必须推导出一致的数据类型T，才可以使用
//  2、模板必须要确定出T的数据类型，才可以使用
//
// 总结：
//  使用模板时必须确定 统一的通用的数据类型T

#include <iostream>
using namespace std;

// "typename"可以替换"class"
template<class T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test_1(void) {
    int a = 10;
    int b = 20;

    mySwap(a, b);
    
    char c = 'c';

    // 1、自动类型推导，必须推导出一致的数据类型T，才可以使用
    // mySwap(a, c);    // 错误：推导不出一致的数据类型T
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func(void) {
    cout << "func()调用" << endl;
}

void test_2(void) {
    // 2、模板必须要确定出T的数据类型，才可以使用，函数题才可以构建
    // func();  // 错误：没有确定出T的数据类型

    func<int>();
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}