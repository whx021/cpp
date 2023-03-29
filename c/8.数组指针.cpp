// 71.数组指针
#include <iostream>
using namespace std;

void test_1(void) {
    int array[] = { 1, 2, 3, 4, 5 };

    // 除了两种情况,数组名都可以认为是数组中的第一个元素的地址, 数组名不退化
    // 特殊情况1 : sizeof(), 获取整个数组大小
    cout << "the size of array is : " << sizeof(array) << endl;
    // 特殊情况2 : 对数组名去地址
    cout << "&array = " << &array << endl;
    cout << "&array + 1 = " << &array + 1 << endl;

    // 使用指针指向数组
    int* p = array;
    // int** p = array;    // int* 类型不能给 int** 类型赋值

    // 指针常量 : int* const p
    // 常量指针 : const int* p

    // 数组指针 : 指针常量, (array)指向不可以改变, (*array)指向的值可以改变
    *array = 10;
    // array = nullptr; // error

    // 利用[]访问数组中的元素, 原理通过指针偏移访问数组元素
    // []本质 : *()
    // []中index可以为负数, 前提不可以越界访问
    p += 3;
    cout << "p[-1] = " << p[-1] << endl;
    cout << "*(p-1) = " << *(p-1) << endl;
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}