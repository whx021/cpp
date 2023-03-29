// socket structure

#ifndef SOCKET_STRUCTURE_H
#define SOCKET_STRUCTURE_H

struct sockaddr {
    unsigned short  sa_family;      // 地址类型(2Byte)
    char            sa_data[14];    // 端口和地址(14Byte)
};

struct socketaddr_in {
    short int           sin_family;     // 地址类型(2Byte)
    unsigned short int  sin_port;       // 端口(2Byte)
    struct in_addr      sin_addr;       // 地址(4Byte)
    unsigned char       sin_zero[8];    // pad(8Byte) : 保持与sockaddr大小一致, 实现转化 
};

struct in_addr {
    unsigned long   s_addr;   // 地址(ipv4)
};

struct hostent {
    char*   h_name;         // 主机名
    char**  h_aliases;      // 主机所有别名的字符串数组(同一IP可以绑定多个域名)
    int     h_addrtype;     // 主机IP地址类型
    int     h_length;       // 主机IP地址长度(ipv4地址长度为4, ipv6地址长度为16)
    char**  h_addr_list;    // 主机 name server IP地址表(网络字节序存储(big endian))
    #define h_addr h_addr_list[0]   // for backward compatibility
};

/**
 * @brief 
 *  利用域名(字符串)获取IP(网络字节顺序地址)
 * @param name 
 * @return struct hostent* 
 */
struct hostent* gethostbyname(const char* name);

/**
 * @brief 
 *  IP地址(字符串) -> IP地址(32bit网络字节序地址 int)
 * @param cp 
 * @param inp 
 * @return int 
 */
int inet_aton(const char* cp, struct in_addr* inp);

/**
 * @brief 
 *  IP地址(32bit网络字节序地址 int) -> IP地址(字符串)
 * @param in 
 * @return char* 
 */
char* inet_ntoa(struct in_addr in);

/**
 * @brief 
 *  IP地址(字符串) -> IP地址(32bit网络字节序地址 int)
 * @param cp 
 * @return in_addr 
 */
in_addr inet_addr(const char* cp);

#endif  // SOCKET_STRUCTURE_H