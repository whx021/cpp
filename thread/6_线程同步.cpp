/* 
 * 线程同步 : 多线程协同工作, 协商如何使用共享资源
 * 1. 互斥锁
 * 2. 条件变量
 * 3. 生产/消费者模型
*/

/* 互斥锁 : 
 * 1. 加锁和解锁, 确保同一时间只有一个线程访问共享资源
 * 2. 访问共享资源之间加锁, 访问完成后释放锁
 * 3. 如果某线程持有锁, 其他的线程形成等待队列 
*/

/* C++11提供了四种互斥锁 : 
 * #include <mutex> 头文件中
 * 1. mutex : 互斥锁
 * 2. timed_mutex : 带超时机制的互斥锁
 * 3. recursive_mutex : 递归互斥锁
 * 4. recursive_timed_mutex : 带超时机制的递归互斥锁
*/

/* mutex class
 * 1. member function : lock()      // 加锁
 * 如果互斥锁是未锁定状态, 调用lock()成员函数的线程会得到互斥锁的所有权, 并将其上锁
 * 如果互斥锁是锁定状态, 调用lock()成员函数的线程会阻塞等待, 直到互斥锁变为未锁定状态
 *
 * 2. member function : unlock()    // 解锁
 * 只有持有锁的线程才能解锁
 * 
 * 3. member function : try_lock()  // 尝试加锁
 *  如果互斥锁是未锁定状态, 则加锁成功, 函数返回true
 *  如果互斥锁是锁定状态, 则加锁失败, 函数返回false (线程不会阻塞)
*/

/* timed_mutex class
 * 增加了成员函数 : 
 * bool try_lock_for(时间长度)
 * bool try_lock_until(时间点)
*/

/* recursive_mutex class
 * 递归互斥锁允许同一线程多次获得互斥锁, 可以解决多次加锁造成的死锁问题
*/

/* lock_guard class : lock_guard is template class
 * lock_guard 在构造函数中加锁, 在析构函数中解锁
 * 可以简化互斥锁使用, 也更安全, 采用了RALL思想
 * RALL : 构造函数中分配资源, 析构函数中释放资源, 保证资源在离开作用域时自动释放
 * 智能指针 : RALL思想
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;
namespace test_1 {
// cout为唯一全局对象, 多线程同时使用时, 输出错乱
// 创建互斥锁对象, 保护共享资源cout对象
mutex mtx;  
// normal function
void func(int b, const std::string& str) {
    std::cout << b << "号子任务执行中..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        mtx.lock();     // cout使用开始前, 申请加锁
        std::cout << b << "号子任务执行中...\n";
        mtx.unlock();   // cout使用结束, 解锁 
        fflush(stdout);
        sleep(1);
    }
    std::cout << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
}
void test(void) {
    thread t1(func, 1, "thread 1");
    thread t2(func, 2, "thread 2");
    thread t3(func, 3, "thread 3");
    thread t4(func, 4, "thread 4");
    thread t5(func, 5, "thread 5");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}
}   // namespace test_1

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <chrono>
using namespace std;

namespace test_2 {
int a = 0;
mutex mtx;
void func(void) {
    for (int i = 0; i < 1000000; ++i) {
        cout << "线程ID : " << this_thread::get_id() << "申请加锁..." << endl;
        mtx.lock();
        cout << "线程ID : " << this_thread::get_id() << "加锁成功..." << endl;
        ++a;
        this_thread::sleep_for(chrono::seconds(5));
        mtx.unlock();
        cout << "线程ID : " << this_thread::get_id() << "释放了锁..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void test(void) {
    // func();
    // func();

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    cout << "a = " << a << endl;
}  
}   // namespace test_2

namespace test_3 {
class Person {
    recursive_mutex m_mtx;
public:
    void func_1(void) {
        m_mtx.lock();
        cout << "call func_1()" << endl;
        m_mtx.unlock();
    }

    void func_2(void) {
        m_mtx.lock();
        cout << "call func_2()" << endl;
        func_1();   // 死锁 : func_2进程加锁后, func_1进程不可能申请到锁
        // 解决方案使用 recursive_mutex
        m_mtx.unlock();
    }
};

void test(void) {
    Person p;
    // p.func_1();
    p.func_2();    
}

}   // namespace test_3

namespace test_4 {
int a = 0;
mutex mtx;
void func(void) {
    for (int i = 0; i < 1000000; ++i) {
        lock_guard<mutex> s_mtx(mutex);
        // mtx.lock();
        ++a;
        // mtx.unlock();
    }
}

void test(void) {
    // func();
    // func();

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    cout << "a = " << a << endl;
}  
}   // namespace test_4

int main(void) {
    test_4::test();
    return EXIT_SUCCESS;
}