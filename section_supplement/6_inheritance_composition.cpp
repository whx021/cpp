// inheritance composition
#include <iostream>
using namespace std;

/*
 * 构造函数调用顺序(base class composition class 顺序不影响 构造由内向外)
 * 1 : base class构造函数调用
 * 2 : composition class 构造函数调用
 * 3 : derived class构造函数调用
 * 
 * 析构函数调用顺序(base class composition class 顺序不影响 析构由外向内)
 * 1 : derived class构造函数调用
 * 2 : composition class 构造函数调用
 * 3 : base class构造函数调用 
 */

class Other {
public:
    Other() {
        cout << "composition class构造函数调用" << endl;
    }
    ~Other() {
        cout << "composition class析构函数调用" << endl;
    }
};

class Base {
public:
    Base() {
        cout << "base class构造函数调用" << endl;
    }
    ~Base() {
        cout << "base class析构函数调用" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "derived class构造函数调用" << endl;
    }
    Derived() {
        cout << "derived class析构函数调用" << endl;
    }
private:
    Other other;
};

void test(void) {
    Derived derived;
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}