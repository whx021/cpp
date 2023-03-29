// 21.内存对齐
// CUP读取内存中的数据是按块读取的
// 如果没有内存对齐, CPU读取数据时可能产生二次访问的现象, 以空间换时间

// 内置数据类型 : 数据存放在该类型的整数倍
// 编译器通常将程序中使用的同一类型数据存放在相邻的内存地址

// 自定义数据类型 : 数据存放有一套对齐规则 
//  1.第一个属性开始, 从偏移量0位置开始存储
//  2.第二个属性开始, min(该类型大小, 对齐模数)的整数倍
//  3.整体计算完毕后, 做二次对齐, 结构体大小必须是
//  min(该结构体类型中最大数据类型, 对齐模数)整数倍, 不足要补齐

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// vs 上查看对齐模数, 默认是8
#pragma pack(show)
// #pragma pack(1) // 修改对齐模数, 可以为 2^n

typedef struct Person {
    int a;
    char b;
    double c;
    float d;
} Person;

void test_1(void) {
    printf("size of Person is : %d\n", sizeof(Person));
}

// 结构体嵌套结构体
typedef struct Student {
    char a;
    Person b;
    double c;
} Student;

int main(void) {
    test_1();
    return 0;
}