#include <iostream>
#include <arpa/inet.h>

void test() {
    // 192.168.190.140
    
    // 网络 : 大端存储
    // 11000000 10101000 10111110 10000110
    // 十进制大小 : 3232284294
    printf("%ld\n", 3232284294);

    // x86 : 小端存储
    // 10000110 10111110 10101000 11000000
    // 十进制大小 : 2260641984
    
    /**
     * @brief 
     *  htonl : 转化为网络大端存储
     */
    printf("%lu\n", htonl(3232284294));
}

int main() {
    test();
    return EXIT_SUCCESS;
}