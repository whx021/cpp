// 15.回调函数案例1
// 提供一个函数打印任意一个数组

#include <stdio.h>

void printAllArray(void* array, int elementSize, int len, void (*printArray)(void*)) {
    char *p = array;
    for (int i = 0; i < len; ++i) {
        char* elementArr = p + elementSize * i;
        printArray(elementArr);
    }
}

void myPrintIntArray(void* data) {
    int* num = data;
    printf("%d\n", *num);
}

void test_1(void) {
    int array_1[5] = { 1, 2, 3, 4, 5 };
    int len = sizeof(array_1) / sizeof (array_1[0]);
    int elementSize = sizeof(array_1[0]);
    printAllArray(array_1, elementSize, len, myPrintIntArray);
}

typedef struct Person {
    char name[64];
    int age;
} Person;

void myPrintPersonArray(void* data) {
    Person* p = data;
    printf("姓名 : %s\n", p->name);
    printf("年龄 : %d\n", p->age);
}

void test_2(void) {
    Person personArray[5] = {
        { "a", 12 },
        { "b", 13 },
        { "c", 14 },
        { "d", 15 },
        { "e", 16 }
    };
    int elementSize = sizeof(personArray[0]);
    int len = sizeof(personArray) / sizeof(personArray[0]);
    printAllArray(personArray, elementSize, len, myPrintPersonArray);
}

int main(void) {
    test_2();
    return 0;
}