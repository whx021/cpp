/**
 * @file 3_client.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief client
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    
    // 第一步 : 创建 client socket
    int socketFD;   // socket file descriptor
    if (socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) == -1) {
        perror("socket creation error");
        return EXIT_FAILURE;
    }

    // 第二步 : 
    struct sockaddr_in server_address;
    struct hostent* host_ip;
    
    /**
     * @brief domain name(const char*) translate to hostent*  
     * 
     * @param name 
     * @return struct hostent* 
     */
    // struct hostent* gethostbyname(const char* name);
    if ((host_ip = gethostbyname(argv[1])) == 0) {  // specifies the server ip 
        perror("gethostbyname failed");
        close(socketFD);    // free socket file descriptor
        return EXIT_FAILURE;
    }
}