// call_once 函数
// 使用场景 : 在多线程环境中, 某些函数只能被调用一次(初始化函数)
// std::call_once()保证某个函数只被调用一次
#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>    // std::once_flag() std::call_once() 头文件
using std::thread;

std::once_flag onceflag;    // once_flag全局变量, 本质是取值为0或1的锁

void func_once(const int b, const std::string& str) {
    std::cout << "once_func() b = " << b  << "str = " << str << std::endl;
}

void func(int b, const std::string& str) {
    std::call_once(onceflag, func_once, 0, "func_once function call");

    std::cout << "子线程ID : " << std::this_thread::get_id() << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << b << "号子任务执行中...\n";
        fflush(stdout);
        sleep(1);
    }
    std::cout << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
}

void test_1(void) {
    thread t1(func, 1, "normal function 2");
    thread t2(func, 2, "normal function 1");

    t1.join();
    t2.join();
}

int main(void) {
    test_1();

    return EXIT_SUCCESS;
}