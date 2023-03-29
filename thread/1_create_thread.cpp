// create thread
#include <iostream>
#include <unistd.h> // sleep()
// head file
#include <thread>
// thread class
using std::thread;

// 编译命令(compile command)
// g++ <source_file_name> -o <executable_file_name> -std=c++11 -lpthread
// -lpthread // linux thread static libraries

/* constructor function
 * 
 * (1)default constructor function :  
 * thread() noexcept
 * Description : 构造一个线程对象, 不执行任何任务(不会创建/启动子线程)
 * 
 * (2)member template constructor function : 
 * template<class Function, class... Args>
 * explicit thread(Function&& fx, Args&&... args);
 * Description : 创建线程对象, 在线程中执行任务函数fx中的代码, args是要传递给任务函数fx的参数
 * 任务函数fx可以是普通函数, 类的非静态成员函数, 类的静态成员函数, lambda函数, 仿函数
 * 
 * (3)copy constructor function :
 * thread(const thread&) = delete;
 * Description : 线程对象是一种特殊的类, 线程对象不允许拷贝, 删除拷贝构造函数
 * 
 * (4)move constructor function
 * thread(thread&& other) noexcept;
 * Description : 移动构造函数, 
 * 将线程other的资源所有权转移给新创建的线程对象, 
 * 转移之后, 原来的线程对象不再代表线程
 * 
 * (5) 赋值函数
 * thread& operator = (thread&& other) noexcept;
 * thread& operator = (const other&) = delete;
 * 线程中的资源不能被复制, 但是可以转移
 */

/*
 * 关于线程的生命周期 : 
 *  1. 先创建的子线程不一定跑得最快(程序运行的速度有很大的偶然性)
 *  2. 线程的任务函数返回后, 程序将终止
 *  3. 如果主程序(主线程)退出(不论是正常退出还是意外终止), 全部子线程将强行终止 
 */

/*
 * 线程资源回收 : 
 *  同一个进程的多个线程共享进程空间, 但是每个子线程在进程栈中拥有自己的私有栈空间,
 *  所以, 线程结束时需要回收资源
 * 回收子线程的资源两种方法 :
 *  1. 在主线程中, 调用join()成员函数等待子线程退出, 回收资源. 
 *      如果子线程退出, join()函数立即返回, 否则产生阻塞, 直到子线程退出
 *  2. 在主程序中, 调用detach()成员函数分离子线程, 子线程退出时, 系统自动回收资源. 
 *      分离后的子线程不可join()
 * 
 */

/* 
 * 使用joinable()成员函数可以判断子线程的分离状态, 函数返回bool类型
 */

// normal function
void func(int b, const std::string& str) {
    std::cout << b << "号子任务执行中..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << b << "号子任务执行中...\n";
        fflush(stdout);
        sleep(1);
    }
    std::cout << std::endl;
    std::cout << b << "号子任务执行中..." << std::endl;
}

// functor
class myThread {
public:
    void operator () (int b, const std::string& str) {
        std::cout << b << "号子任务执行中..." << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << b << "号子任务执行中...\n";
            fflush(stdout);
            sleep(1);
        }
        std::cout << std::endl;
        std::cout << b << "号子任务执行中..." << std::endl;
    }
};

// class with member static function
class myThreadClass_1 {
public:
    static void func(int b, const std::string& str) {
        std::cout << b << "号子任务执行中..." << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << b << "号子任务执行中...\n";
            fflush(stdout);
            sleep(1);
        }
        std::cout << std::endl;
        std::cout << b << "号子任务执行中..." << std::endl;
    }
};

// class with member normal function
class myThreadClass_2 {
public:
    void func(int b, const std::string& str) {
        std::cout << b << "号子任务执行中..." << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << b << "号子任务执行中...\n";
            fflush(stdout);
            sleep(1);
        }
        std::cout << std::endl;
        std::cout << b << "号子任务执行中..." << std::endl;
    }
};

// multithreading
void test_1(void) {
    // 用普通函数创建线程
    // thread t1(func, 1, "normal function 1");
    // thread t2(func, 2, "normal function 2");
    
    // 用lambda函数创建线程
    auto f = [](int b, const std::string& str) {
        std::cout << b << "号子任务执行中..." << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << b << "号子任务执行中...\n";
            fflush(stdout);
            sleep(1);
        }
        std::cout << std::endl;
        std::cout << b << "号子任务执行中..." << std::endl;
    };
    // thread t3(f, 3, "lambda expression 1");

    // 用仿函数创建线程
    // thread t4(myThread(), 4, "functor 1");

    // 用类的静态成员函数创建线程
    // thread t5(myThreadClass_1::func, 5, "static member function");

    // 用类的普通函数创建线程
    // note : 必须创建类对象, 必须保证对象生命周期比子线程要长
    // reason : 类的普通成员函数可能访问类的不同成员变量, 如果对象销毁, 会发生内存泄漏
    myThreadClass_2 myth;   
    // Parameter 1 : the normal member function
    // Parameter 2 : must be this pointer
    // Other Parameter
    thread t6(&myThreadClass_2::func, &myth, 6, "normal member function");

    std::cout << "主线程任务开始." << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "主线程任务执行中...\n";
        fflush(stdout); // 刷新IO缓冲区
        sleep(1);       // 单位 : s
    }
    std::cout << std::endl;
    std::cout << "主线程任务完成." << std::endl;

    // 回收 normal function thread t1 资源
    // t1.join();
    // 回收 normal function thread t2 资源
    // t2.join();
    // 回收 lambda expression thread t3 资源
    // t3.join();
    // 回收 functor thread t4 资源
    // t4.join();
    // 回收 static member function thread t5 资源
    // t5.join();
    // 回收 normal member function thread t6 资源
    t6.join();
}

void test_2(void) {
    thread t1(func, 1, "normal function 1");
    thread t2(func, 2, "normal function 2");
    t1.detach();    // 分离子线程t1
    t2.detach();    // 分离子线程t2

    // std::cout << "主线程任务开始." << std::endl;
    // for (int i = 0; i < 12; ++i) {
    //     std::cout << "主线程任务执行中...\n";
    //     fflush(stdout); // 刷新IO缓冲区
    //     sleep(1);       // 单位 : s
    // }
    // std::cout << std::endl;
    // std::cout << "主线程任务完成." << std::endl;

    // t1.join();  // 回收线程t1资源
    // t2.join();  // 回收线程t2资源
    sleep(12);
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}