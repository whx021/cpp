// 73.二维数组的数组名
#include <iostream>
using namespace std;

// 遍历二维数组的函数
// void printArray(int arr[3][3], int row, int col)
// void printArray(int arr[][3], int row, int col)
void printArray(int(*arr)[3], int row, int col) {
    for (int i = 0 ; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
            cout << *(*(arr + i) + j) << " ";
        } 
        cout << endl;
    }
}

void test_1(void) {
    int array_1[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 } 
    };

    int array_2[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int array_3[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 除了两种特殊情况, 二位数组的数组名可以理解为 : 指向第一个一维数组的数组名, 数组指针退化
    int (*arrayP)[3] = array_1;
    cout << "array[1][2] = " << array_1[1][2] << endl;
    cout << "*(*(arrayP + 1) + 2) = " << *(*(arrayP + 1) + 2) << endl;
    // 解释 : 
    // arrayP : 指向一维数组类型的指针(二维数组名)
    // *(array + 1) : 指针向后偏移1个sizeof(一维数组类型)后解引用, 为指向int类型的指针(一维数组名)
    // *(*(array + 1) + 2) : 指针向后偏移2个sizeof(int类型)后解引用, 为int元素

    cout << "*(*arrayP + 5) = " << *(*arrayP + 5) << endl;
    // 解释 : 
    // *arrayP : 解引用为指向int类型的指针(一维数组名), 
    // *(*arrayP + 5) : 通过偏移量访问int元素

    // 两种特殊情况
    // 1.sizeof()
    cout << "sizeof(array_1) = " << sizeof(array_1) << endl;
    // 2.对数组名取地址
    int (*p)[3][3] = &array_1;

    // 遍历二维数组的元素
    int row = sizeof(array_1) / sizeof(array_1[0]);
    int col = sizeof(array_1[0]) / sizeof(array_1[0][0]);
    printArray(array_1, row, col);

    // 指针指向的地址相同, 但步长不同(即指向类型不同)
    cout << "&array[0][0] = " << &array_1[0][0] << endl;            // 元素大小
    cout << "&array[0][0] + 1 = " << &array_1[0][0] + 1 << endl;    // offset 4byte 
    cout << "array = " << array_1 << endl;          // 一维数组大小      
    cout << "array + 1 = " << array_1 + 1 << endl;  // offset 12byte
    cout << "&array = " << &array_1 << endl;        // 二维数组大小
    cout << "&array + 1" << &array_1 + 1 << endl;   // offset 36byte
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}