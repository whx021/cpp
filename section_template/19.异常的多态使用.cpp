// 19、异常的多态使用

#include <iostream>
using namespace std;

// 异常的基类
class BaseException {
public:
    virtual void printError() const = 0;
};

// 空指针异常
class NULLPointer : public BaseException {
public:
    virtual void printError() const {
        cout << "空指针异常" << endl;
    }
};

// 越界异常
class OutOfRange : public BaseException {
public:
    virtual void printError() const {
        cout << "越界异常" << endl;
    }
};

void func(void) {
    // throw NULLPointer();
    throw OutOfRange();
}

void test_1(void) {
    try {
        func();
    }
    catch(const BaseException& e) {
        e.printError(); // 体现多态，使用父类引用类型引用子类对象
    }
}

int main(void) {   
    test_1();
    return EXIT_SUCCESS;
}