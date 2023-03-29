/**
 * @file 2_server.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief 
 *  web server
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

// 进程级 file descriptor : 
// 1 : standard input stream
// 2 : standard output stream
// 3 : standard error output stream
// linux 下万物皆文件, 创建 一个 socket 需要指定一个 file descriptor 
// 如果 该进程 创建 文件 连接失败 return file descriptor == -1 (invalid value)

int main(int argc, char** argv) {
    // 第一步 : 创建服务端监听socket
    int listenFD;   // record listen port socket file descriptor 
    // socket() function
    // int socket(int domain, int type, int protocol);
    /**
     * @brief Construct a new if object
     *  domain：即协议域，又称为协议族（family）。
     *      常用的协议族有，
     *      AF_INET、
     *      AF_INET6、
     *      AF_LOCAL（或称AF_UNIX，Unix域socket）、
     *      AF_ROUTE等等。
     *      协议族决定了socket的地址类型，在通信中必须采用对应的地址，
     *      如AF_INET决定了要用ipv4地址（32位的）与端口号（16位的）的组合、
     *      AF_UNIX决定了要用一个绝对路径名作为地址。
     *      type：指定socket类型。
     *  常用的socket类型有，
     *      SOCK_STREAM、
     *      SOCK_DGRAM、
     *      SOCK_RAW、
     *      SOCK_PACKET、
     *      SOCK_SEQPACKET等等（socket的类型有哪些？）。
     *  protocol：故名思意，就是指定协议。
     *      常用的协议有 : 
     *      IPPROTO_TCP     TCP传输协议
     *      IPPROTO_UDP     UDP传输协议
     *      IPPROTO_SCTP    STCP传输协议
     *      IPPROTO_TIPC    TIPC传输协议
     */
    if ((listenFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket creation error");
        return EXIT_FAILURE;
    }

    // 第二步 : specifies socket information : bind server ip and port to listen socket
    struct sockaddr_in serverSocket;    // create the serverSocket structure 
    memset(&serverSocket, 0, sizeof(serverSocket)); // initialize the serverSocket
    serverSocket.sin_family = AF_INET;  // specifies the protocol family (ipv4)
    // serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);   // specifies any ip
    serverSocket.sin_addr.s_addr = inet_addr("192.168.190.134");    // specifies ip
    // atoi() : const char* translate into int 
    // htons() : host to net short int 
    serverSocket.sin_port = htons(atoi(argv[1]));   // specifies port

    /**
     * @brief 
     *  bind the socket file descriptor to socket 
     * @param file_descriptor   int 
     * @param socket            const struct sockaddr*
     * @param length            unsigned int 
     * @return int 
     */
    // extern int bind
    // (int file_descriptor, const struct sockaddr* socket, unsigned int length);
    if (bind(listenFD, (struct sockaddr* )&serverSocket, sizeof(serverSocket)) != 0) {
        perror("socket binding error");
        abort();
    }
    
}