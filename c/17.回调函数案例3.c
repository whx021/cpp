// 17.回调函数案例3
// 对任意类型数组进行排序
// 提高程序接口的复用性

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(void* array, int elementSize, int len, bool myCompare(void*, void*)) {
    char* temp = malloc(elementSize);   // 定义交换时的临时数据
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            char* pJ = (char*)array + elementSize * j;
            char* pJPlus = (char*)array + elementSize * (j + 1);
            // if (*pJPlus > *pJ)
            if (myCompare(pJPlus, pJ)) {
                // 不知道交换数据数据类型, 仅知道数据类型大小的情况, 交换数据在数组中的位置
                memcpy(temp, pJ, elementSize);
                memcpy(pJ, pJPlus, elementSize);
                memcpy(pJPlus, temp, elementSize);
            }
        }
    }
    if (temp != NULL) {
        free(temp);
        temp = NULL;
    }
}

bool myCompareInt(void* data1, void* data2) {
    int* num_1 = data1;
    int* num_2 = data2;
    if (*num_1 > *num_2) {
        return true;
    }
    else {
        return false;
    }
}

void test_1(void) {
    int array[5] = { 1, 2, 3, 4, 5 };
    int elementSize = sizeof(array[0]);
    int len = sizeof(array) / sizeof(array[0]); 
    bubbleSort(array, elementSize, len, myCompareInt);
    for (int i = 0; i < len; ++i) {
        printf("%d\n", array[i]);
    }
}

typedef struct Person {
    char name[64];
    int age;
} Person;

bool myComparePerson(void* data_1, void* data_2) {
    Person* p1 = data_1;
    Person* p2 = data_2;
    // if (p1->age < p2->age) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    return p1->age < p2->age;
}

void test_2(void) {
    Person personArray[5] = {
        { "aaa", 19 },
        { "bbb", 46 },
        { "ggg", 43 },
        { "jjj", 16 },
        { "eee", 27 }
    };
    int elementSize = sizeof(personArray[0]);
    int len = sizeof(personArray) / sizeof(personArray[0]);
    bubbleSort(personArray, elementSize, len, myComparePerson);
    for (int i = 0; i < len; ++i) {
        printf("姓名 : %s\t", personArray[i].name);
        printf("年龄 : %d\n", personArray[i].age);
    }
}

int main(void) {
    test_1();

    return 0;
}