/**
 * @file 26_macro_#_##_variadic_args.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief macro : 
 *  # operator : 用宏参数创建字符串 
 *  ## operator : 预处理器黏合剂
 *  variadic args macro : 接受可变参数的宏
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 *   宏的替换体 is 记号(token)型字符串, 而不是字符型字符串
 *      记号型字符串 : 空格 视为替换体中各记号的分隔符
 *      字符型字符串 : 空格 视为替换体的一个部分
 *  # operator 
 *      将 宏参数(记号型字符串) translate to 宏参数(字符型字符串) by # operator
*/
#include <cstdio>

#define PSQR(x) printf("The square of " #x " is %d\n", ((x)*(x)))
void test_1(void) {
    int y = 5;
    PSQR(y);
    // 调用过程 
    printf("The square of " "y" " is %d\n", ((y)*(y)));
    // ANSI C 字符串的串联特性 上下两行相等
    printf("The square of y is %d\n", ((y)*(y)));
    PSQR(2 + 4);
}

/**
 * @brief 
 *  ## operator
 *      将 记号组合为一个新的标记符
 */
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);
void test_2(void) {
    int XNAME(1) = 14;  // translate to : int x1 = 14;
    int XNAME(2) = 20;  // translate to : int x2 = 20;
    int x3 = 30;
    PRINT_XN(1);    // translate to : printf("x1 = %d\n", x1);
    PRINT_XN(2);    // translate to : printf("x2 = %d\n", x2);
    PRINT_XN(3);    // translate to : printf("x3 = %d\n", x3);
}

/**
 * @brief 
 *  variadic args macro : 接受可变参数的宏
 */
#include <cmath>
// 通过printf()接受数量可变的参数, 实现自定义打印
#define PR(x, ...) printf("Message " #x ": " __VA_ARGS__)
void test_3(void) {
    double x = 48;
    double y;

    y = sqrt(x);
    PR(1, "x = %g\n", x);
    // 调用过程
    printf("Message " "1" ": " "x = %g\n", x);
    printf("Message 1: x = %g\n", x);

    PR(2, "x = %.2f, y = %.4f\n", x, y);
}
// ... 只能代替最后的宏参数
// #define WRONG(x, ..., y) #X #__VA_ARGS__ #y // no


int main(void) {
    // test_1();
    // test_2();
    test_3();
    return 0;
}