#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::thread;

volatile int a = 0; // volatile 关键字解决不了多核处理器并发程序

void func(void) {
    for (int i = 0; i < 1000000; ++i) {
        ++a;
    }
}

void test_1(void) {
    // func();
    // func();

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    cout << "a = " << a << endl;
}   

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}