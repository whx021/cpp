#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void test_1(void) {
    printf("the size of sockaddr = %d\n", sizeof(sockaddr));            // 16
    printf("the size of sockaddr_in = %d\n", sizeof(sockaddr_in));      // 16
    printf("the size of sockaddr_in6 = %d\n", sizeof(sockaddr_in6));    // 28
    printf("the size of in_addr = %d\n", sizeof(in_addr));              // 4
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}