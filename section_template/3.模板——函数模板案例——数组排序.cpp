// 3、模板——函数模板案例——数组排序

#include <iostream>
using namespace std;

// 交换函数模板
template<class T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 简单选择排序函数模板
template<class T>
void mySort(T array[], int length) {
    for (int i = 0; i < length; ++i) {
        int min = i;
        for (int j = i + 1; j < length; ++j) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        if (min != i) {
            mySwap(array[min], array[i]);
        }
    }
}

// 打印数组模板
template<class T>
void myPrintArray(T array[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << array[i] << "\t"; 
    }
    cout << endl;
}

void test_1(void) {
    // 测试char数组
    char charArray[] = "badcged";
    int array_length = sizeof(charArray) / sizeof(charArray[0]);
    mySort(charArray, array_length);
    myPrintArray(charArray, array_length);
}

void test_2(void) {
    // 测试int数组
    int intArray[] = {0, 5, 7, 2, 5, 68, 17, 9};
    int array_length = sizeof(intArray) / sizeof(intArray[0]);
    mySort(intArray, array_length);
    myPrintArray(intArray, array_length);
}

int main(void) {
    test_1();
    test_2();
    return EXIT_SUCCESS;
}