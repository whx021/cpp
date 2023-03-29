// 76.函数指针
#include <iostream>
using namespace std;

void func(void) {
    cout << "Hello World" << endl;
}

void test_1(void) {
    // func();
    cout << "func = " << func << endl;

    // 函数名 : 本质函数指针 指向函数的入口地址(即函数机器码的的第一条指令的地址)
    void(*p)() = (void(*)())&func;
    p();
}

void func_1(int, char) {
    cout << "Hello World" << endl;
}

// 函数指针的定义方法
void test_2(void) {
    // 1.先定义函数类型, 在通过函数类型定义函数指针变量
    typedef void(FUNC_TYPE)(int, char); // FUNC_TYPE为函数数据类型
    FUNC_TYPE* funcPtr_1 = &func_1;

    // 2.先定义函数指针类型, 在通过函数指针类型, 定义函数指针变量
    typedef void(*FUNC_PTR)(int, char); // FUNC_TYPE为函数指针数据类型
    FUNC_PTR funcPtr_2 = &func_1;

    // 3.直接定义函数指针类型
    void(*funcPtr_3)(int, char) = &func_1;
}

void myFunc_1(void) {
    cout << "func_11函数调用" << endl;
}

void myFunc_12(void) {
    cout << "func_12函数调用" << endl;
}

void myFunc_13(void) {
    cout << "func_13函数调用" << endl;
}

// 函数指针数组
void test_3(void) {
    // 语法
    void(*funcArr[3])(void);
    // 调用
    for (int i = 0; i < 3; ++i) {
        funcArr[i]();
    }
}

int main(void) {    
    test_1();

    return EXIT_SUCCESS;
}