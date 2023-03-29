// 16.回调函数案例2
// 查找任意数组中元素是否存在
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printAllArray(void* array,  int elementSize, int len, void(*myPrint)(void*)) {
    char* p = array;
    for (int i = 0; i < len; ++i) {
        // printf("%d\n", *(int*)(p + elementSize * i));
        char* elementArr = p + elementSize * i;
        myPrint(elementArr);
    }
}

bool findArrayElement
(void* array, int elementSize, int len, void* data, bool(*myCompare)(void*, void*)) {
    char* p = array;
    for (int i = 0; i < len; ++i) {
        char* elementAdd = p + elementSize * i;
        // if (*(int*)elementArr == *(int*)data) 
        if (myCompare(elementAdd, data)) {
            return true;
        }
    }
    return false;
}

bool myCompareInt(void* arrayElement, void* data) {
    int* num_1 = arrayElement;
    int* num_2 = data;
    if (*num_1 == *num_2) {
        return true;
    }
    else {
        return false;
    }
}

void test_1(void) {
    int array[5] = { 1, 2, 3, 4, 5 };
    int num = 3;
    int elementSize = sizeof(array[0]);
    int len = sizeof(array) / sizeof(array[0]);
    bool result = findArrayElement(array, elementSize, len, &num, myCompareInt);
    if (result == true) {
        printf("数组中找到了%d\n", num);
    }
    else {
        printf("数组中没有找到了%d\n", num);
    }
}

typedef struct Person {
    char name[64];
    int age;
} Person;

bool myComparePerson(void* arrayElement, void* p) {
    Person* p1 = arrayElement;
    Person* p2 = p;
    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
        return true;
    }
    else {
        return false;
    }
}

void printDate(void* data, void(*myPrint)(void*)) {
    // printf("%d/n", *(int*)data);
    myPrint(data);
}

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
    Person p = { "e", 16 };
    int result = findArrayElement(personArray, elementSize, len, &p, myComparePerson);
    if (result) {
        printf("找到了\n");
        printDate(&p, myPrintPersonArray);
    }
    else {
        printf("没有找到\n");
        printDate(&p, myPrintPersonArray);
    }
}

int main(void) {
    test_2();
    return 0;
}