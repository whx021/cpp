// assertion
// 断言是用来检查非法情况而不是错误情况的，用来帮开发者快速定位问题的位置。
// 异常处理用于对程序发生异常情况的处理，增强程序的健壮性和容错性。

// assert header file
#include <cassert>  

// gammer
// assert(expression)
// if expression == false, call abort()
// if expression == true, the program execute normally

#include <iostream>
using std::cout;
using std::endl;
void copyData(void* ptr_1, void* ptr_2) {
    // assert ptr_1 and ptr_2 neither is nullptr
    assert(ptr_1 != nullptr && ptr_2 != nullptr);
    cout << "the program execute normally" << endl;
}

void test_1(void) { 
    int i = 0, j = 0;
    copyData(nullptr, &j);
}

// C++11 static assertion
// assert : 宏, 程序运行时检查代码
// static_assert : 编译时检查代码

// static_assert(常量表达式, 提示信息);

void test_2(void) {
    const int i = 1;
    static_assert(i, "i is invalid argument");
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}