// native_handle 函数
/*
 * 使用说明 :
 * C++11定义了线程标准, 不同的平台和编译器在实现的时候,
 * 本质都是对操作系统的线程库进行封装, 会损失一部分功能.
 * thread class 提供 native_handle()成员函数, 用于获得与操作系统相关的原生线程句柄, 
 * 操作系统原生线程库就可以用原生线程句柄操作线程
 */
// linux : 原生线程库pthread
#include <iostream>
#include <thread>
#include <pthread.h>
#include <chrono>
using std::thread;

void func(void) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "times = " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void test_1(void) {
    thread t(func);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pthread_t os_handle = t.native_handle();    // 获取linux操作系统原生的线程句柄
    pthread_cancel(os_handle);                  // 取消线程
    t.join();
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}