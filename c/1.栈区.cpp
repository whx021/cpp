// 1.栈区

// 不要返回局部变量的 地址 || 引用

#include "iostream" 
using namespace std;

char* getString() {
    char str[] = "apple";   // str[]局部变量
    // "apple" : 字符串常量保存在字符串常量区
    // str ： 字符串数组（局部变量），指向栈区拷贝的"apple"字符首地址
    return str;
}

void test_1(void) {
    char* p = nullptr;
    p = getString();    // error : 指向空间已不属于程序维护
}

// 栈的生长方向
// 栈底——高地址
// 栈顶——低地址
void test_2(void) {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    cout << &a << endl; // 高地址 
    cout << &b << endl; 
    cout << &c << endl;
    cout << &d << endl; // 低地址
}

// 调用惯例
// 出栈方：主调函数 || 被调函数管理参数出栈 
// 参数传递：参数入栈顺序
// 函数名称修饰：函数内部名

void test_3(void) {
    int a = 0x11223344;
    char* p = (char*)&a;
    // 计算机组成原理中主存储器

    // 小端对齐模式 ：家庭电脑
    // 低位字节数据 放在低地址端 
    // 高位字节数据 放在高地址端
    // 大端对齐模式 ：服务器
    // 低位字节数据 放在高地址端
    // 高位字节数据 放在低地址端
    printf("%x\n", *p);       // 44 低地址数据
    printf("%x\n", *(p + 1)); // 33 
    printf("%x\n", *(p + 2)); // 22 
    printf("%x\n", *(p + 3)); // 11 高地址数据
}

int main() {
    test_2();
    return EXIT_SUCCESS;
}