// this_thread 的全局函数
/*
 * C++11 提供 std namespace 的 子命名空间 this_thread namespace 来表示当前线程, 
 * this_thread namespace 中有四个函数 : get_id(), sleep_for(), sleep_until(), yield()  
 */

/*
 * get_id() : 
 * thread::id get_id() noexcept;
 * 该函数用于获取线程ID, thread类也有同名的成员函数
 */

/* 
 * sleep_for()  VS : Sleep() 单位 : ms linux : sleep() 单位 : s
 * template<class Rep, class Period>
 * void sleep_for(const chrono::duration<Rep, Period>& rel_time);
 * 该函数让线程休眠一段时间
 */

/*
 * sleep_until()
 * template<class Clock, class Duration>
 * void sleep_until(const chrono::time_point<Clock, Duration>& abs_time);
 * 该函数让线程休眠至指定时间(可实现定时任务)
 */

/*
 * yield()
 * void yield() noexcept;
 * 该函数主动让出自己已经抢到的CPU时间片
 */

/* 
 * void swap(std::thread& other);                   // 交换两个线程对象
 * static unsigned hardware_concurrency() noexcept; // 返回硬件线程上下文的数量
 */

/* hardware_concurrency() 返回硬件支持并发数
*/



#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <ctime>
using std::thread;

void func(int b, const std::string& str) {
    std::cout << "子线程ID : " << std::this_thread::get_id() << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << b << "号子任务执行中...\n";
        fflush(stdout);
        // sleep(1);
        // TODO : use chrono 
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
}

void test_1(void) {
    thread t1(func, 1, "normal function 1");
    thread t2(func, 2, "normal function 2");

    std::cout << "主线程ID : " << std::this_thread::get_id() << std::endl;
    std::cout << "线程t1ID : " << t1.get_id() << std::endl;
    std::cout << "线程t2ID : " << t2.get_id() << std::endl;

    t1.swap(t2);
    std::cout << "线程t1ID : " << t1.get_id() << std::endl;
    std::cout << "线程t2ID : " << t2.get_id() << std::endl;

    thread t3 = move(t2);

    t1.join();
    t3.join();
}

int main(void) {
    test_1();

    return EXIT_SUCCESS;
}