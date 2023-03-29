/**
 * @file 19_const_constexpr.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief
 *  const 用于为修饰的变量添加“只读”属性；
 *  
 *  constexpr 关键字则用于指明其后是一个常量（或者常量表达式），
 *  编译器在编译程序时可以顺带将其结果计算出来，而无需等到程序运行阶段，
 *  这样的优化极大地提高了程序的执行效率。 
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// C++98 : const : 只读 常量
// C++11 :
// const : 只读变量(read-only variable)
// constexpr : 常量(constant)

// constant : 编译阶段确定, 存储在符号表中
// read-only variable : 运行阶段确定, 无法通过变量自身修改自身的值, 可以通过其他变量间接修改

#include <iostream>
#include <array>
using namespace std;

void test_1() {
    // read-only property != non-modifiable property
    int a = 10;
    const int& con_b = a;
    cout << con_b << endl;

    // modify read-only variable
    a = 20;
    cout << con_b << endl;
}

constexpr int sqr1(int arg) {
    return arg * arg;
}
const int sqr2(int arg) {
    return arg * arg;
}
void test_2(void) {
    // constexpr : constant : can initialize array container
    array<int, sqr1(10)> myList1;   // yes

    // const : read-only variable : can't initialize array container    
    // array<int, sqr2(10)> myList2;   // no
}

int main() {
    test_1();
    return EXIT_SUCCESS;
}