// 18.一级指针易错点
#include <stdio.h>

// 1.指针越界

// 2.返回局部变量的地址

// 3.同一块内存多次释放

// 4.释放偏移后的指针
void test_4(void) {
    char str[] = "whx";
    char* p = malloc(sizeof(char) * 64);
    // 解决方法 : 从新定义一个遍历指针
    for (int i = 0; i < strlen(str); ++i) {
        *p = str[i];
        ++p;
    } 
    free(p);
}

int main(void) {

    return 0;
}