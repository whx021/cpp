// socket()返回本质是一个文件描述符(句柄), 是一个整数
#include <iostream>

namespace whx_1 {

// IP 地址数据结构
struct in_addr {

};

// IP_address和port捆绑关系的数据结构(标识进程的端结点)
struct sockaddr_in {
    short           sin_family;     // AF_INET : 地址族 
    u_short         sin_port;       // port : 端口号
    struct in_addr  sin_addr;       // IP address : IP地址
    char            sin_zero[8];    // align : 对齐
};

// 域名和IP地址的数据结构
// 作为调用域名解析函数时的参数
// 返回后, 将IP地址拷贝到sockaddr_in的IP地址部分
struct hostent {
    char*   h_name;         // 主机域名
    char*   h_aliases;      // 主机一系列别名(二维字符数组)                
    int     h_addrtype;     // 
    int     h_length;       // 地址长度
    char**  h_addr_list;    // IP地址列表
    #define h_addr h_addr_list[0];
};

}   // namespace whx_1