#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstddef>
using namespace std;

/*
 * FunctionName : void *memcpy(void *str1, const void *str2, size_t n) 
 * Standard Library : <cstring> 
 * Description : 从存储区 str2 复制 n 个字节到存储区 str1
 * Parameter 1 : str1 -- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
 * Parameter 2 : str2 -- 指向要复制的数据源，类型强制转换为 void* 指针。
 * Parameter 3 : n -- 要被复制的字节数。
 * Return : 该函数返回一个指向目标存储区 str1 的指针。
 */

void test_1(void) {
    char buffer[] = {0};
    int a = 1000;
    memcpy(buffer, &a, sizeof(int));
    char* p = buffer;
    printf("%d\n", *(int*)p);
}

struct Person {
    char a; // 0~3
    int b;  // 4~7
    char buffer[64];    // 8~71
    int d;  // 72~75
};

/*
 * FunctionName : offsetof(type, member)
 * Description : 计算对象中成员的偏移量
 * Strand Library : <cstddef>
 */

void test_2(void) {
    struct Person p = {'a', 10, "hello world", 1000};
    
    // d的偏移量
    cout << "a成员的偏移量 : " << offsetof(struct Person, a) << endl;
    cout << "b成员的偏移量 : " << offsetof(struct Person, b) << endl;
    cout << "buffer成员的偏移量 : " << offsetof(struct Person, buffer) << endl;
    cout << "d成员的偏移量 : " << offsetof(struct Person, d) << endl;

    // 通过偏移量，获取d内存
    *(int*)((char*)&p + offsetof(struct Person, d)) = 10000;
    cout << "d的值为 : " << *(int*)((char*)&p + offsetof(struct Person, d)) << endl;
    cout << "buffer值为 : " << (char*)&p + offsetof(struct Person, buffer) << endl;
}

int main(void) {
    test_2();

    return EXIT_SUCCESS;
}