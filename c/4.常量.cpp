// 常量区：
// const 修饰的变量
// 字符串常量
// 字面量

#include <iostream>
using namespace std;

// const 修饰全局变量，存放在常量区中，受到常量区保护，一旦修改程序崩溃
const int c_a = 10;
void test_1(void) {
    // c_a = 10; // 直接修改：失败

    // 间接修改：程序崩溃
    // int* p = (int*)&c_a;
    // *p = 20;
    // cout << c_a << endl;

    // const 修饰局部变量
    const int c_b = 10;
    // c_b = 20; // 直接修改：失败

    // 间接修改
    int* p = (int*)&c_b;
    *p = 20;
    cout << c_b << endl;

    int arr[c_b];
}

// 字符串常量
void test_2(void) {
    
    // windows vs 中将相同字符串只存储一次
    const char* p1 = "apple";
    const char* p2 = "apple";
    const char* p3 = "apple";

    cout << &"apple" << endl;
    cout << &p1 << endl;
    cout << &p2 << endl;
    cout << &p3 << endl;

    
    // char* p4 = "apple";  // 字符串常量，字符串常量（不可修改）
    char p4[] = "apple";    // 字符串变量，拷贝常量区的字符在栈区存储（可修改）
    cout << p4[0] << endl;
    p4[0] = 'x';
    cout << p4[0] << endl;
}

int main(void) {
    test_2();

    return EXIT_SUCCESS;
}