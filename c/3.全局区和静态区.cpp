// 3.全局区和静态区
// data : 存放已初始化数据（字符串常量）
// bss : 存放未初始化数据
// 该区未初始化的变量，会有默认值初始化

#include <iostream>
using namespace std;

// 全局变量：均隐藏添加了关键值extern，属于外部链接属性
// extern int a = 10;
void test_1(void) {
    // 告诉编译器，该全局变量可能在其他链接的目标文件中定义，在全局区/静态区寻找变量global_a 
    extern int global_a;    
    cout << global_a << endl;
}

// 没有初始化的全局变量，默认初始化为0
int global_b;
void test_2(void) {
    cout << global_b << endl;

    // 局部变量未初始化
    int b;
    cout << b << endl;
}

void function(void) {
    static int a = 10;
    a++;
    cout << a << endl;  
}

// 静态变量 static
// 属于内部链接属性，只能在本文件中使用
void test_3(void) {
    // 属于内部链接属性，只能在本文件中使用
    // extern int s_a;
    // cout << s_a << endl;

    // 静态变量智慧初始化一次
    function(); // 局部变量 11 // static变量 11
    function(); // 局部变量 11 // static变量 12
    function(); // 局部变量 11 // static变量 13
}   

void test_4(void) {
    // 没有初始化的全局变量，默认初始化为0
    static int s_b;
    cout << s_b << endl;
}

int main(void) {
    test_3();

    return EXIT_SUCCESS;
}