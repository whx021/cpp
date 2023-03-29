// 77.函数指针做函数参数-回调函数
#include <stdio.h>

// 提供一个函数打印任意数据类型
void printDate(void* data, void(*myPrint)(void*)) {
    // printf("%d/n", *(int*)data);
    myPrint(data);
}

void myPrintInt(void* data) {
    // C++强类型语言, 无法实现使用void* 类型指针 直接对 int* 指针变量赋值, 需要进行类型转化
    // C 可以
    int* num = data;
    printf("%d\n", *num);
}

void test_1(void) {
    int a = 10;
    printDate(&a, myPrintInt);
}

struct Person {
    char name[64];
    int age;
};

void myPrintPerson(void* data) {
    struct Person* person = data;
    printf("姓名 : %s\n", person->name);
    printf("年龄 : %d\n", person->age);
}

void test_2(void) {
    struct Person p = { "杜硕硕", 20 };
    printDate(&p, myPrintPerson);
}

int main(void) {
    test_2();
    return 0;
}