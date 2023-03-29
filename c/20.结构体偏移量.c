// 20.结构体偏移量
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct Person {
    char a;
    int b;
}Person; 

// 计算结构体中变量的偏移量
void test_1(void) { 
    Person p;
    int offset_1 = offsetof(Person, b);
    int offset_2 = (int)&p.b - (int)&p;
    printf("setoff_1 = %d\n", offset_1);
    printf("setoff_2 = %d\n", offset_2);
}

// 通过偏移量访问结构体中变量数据
void test_2(void) {
    Person p = { 'a', 10 };
    printf("p.d = %d\n", *(int*)((char*)&p + offsetof(Person, b)));
}

// 结构体中嵌套结构体
typedef struct Person2 {
    char a;
    int b;
    Person c;
}Person2;

void test_3(void) {
    Person2 p = { 'a', 10, { 'b', 20 } };
    printf("p.c.b = %d\n", p.c.b);
    int offset_1 = offsetof(Person2, c);
    int offset_2 = offsetof(Person, b);
    printf("p.c.b = %d\n", *(int*)((char*)&p + offset_1 + offset_2));
    printf("p.c.b = %d\n", ((Person*)((char*)&p + offset_1))->b);
    printf("p.c.b = %d\n", (*((Person*)((char*)&p + offset_1))).b);
}

int main(void) {
    test_3();
    return 0;
}