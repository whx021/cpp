// 72.数组指针的定义方式
#include <iostream>
using namespace std;

void test_1(void) {
    int array[5] = { 1, 2, 3, 4, 5 };

    // 1.先定义数组类型, 在通过数组类型定义数组指针变量
    typedef int(ARRAY_TYPE)[5]; // ARRAY_TYPE : 存放5个int元素的数组数据类型
    ARRAY_TYPE* arrP = &array;

    // 通过数组指针访问数组元素 *arrP == array
    for (int i = 0; i < 5; ++i) {
        cout << "(*arrP)[i] = " << (*arrP)[i] << endl;
        cout << "*((*arrP) + i)" << *((*arrP) + i) << endl;
    }
}

void test_2(void) {
    int array[5] = { 1, 2, 3, 4, 5 };
    // 直接定义数组指针类型, 通过数组指针类型定义数组指针变量
    typedef int(*ARRAY_PTR)[5]; // ARRAY_PTR : 指向存放5个int元素数组的指针数据类型
    ARRAY_PTR p = &array;

    for (int i = 0; i < 5; ++i) {
        cout << "(*p)[i] = " << (*p)[i] << endl;
        cout << "*((*p) + i)" << *((*p) + i) << endl;
    }
}

void test_3(void) {
    // 直接定义数组指针变量
    int array[5] = { 1, 2, 3, 4, 5 };
    int(*arrP)[5] = &array;
    for (int i = 0; i < 5; ++i) {
        cout << "(*arrP)[i] = " << (*arrP)[i] << endl;
        cout << "*((*arrP) + i) = " << *((*arrP) + i) << endl; 
    }
}

int main(void) {
    return EXIT_SUCCESS;
} 