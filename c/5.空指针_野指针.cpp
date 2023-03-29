// 5.空指针_野指针

#include  <iostream>
using namespace std;

/* 
 * 野指针常见出现场景：
 * 1、指针变量未初始化
 * 2、释放堆区指针后，没有分配指向
 * 3、函数返回局部变量的地址和应用
 */

// 空指针指向堆区空间可以释放free、delete
// 野指针 不 指向堆区空间可以释放free、delete

int main(void) {
    return EXIT_SUCCESS;
}