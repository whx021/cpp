// 9、模板——类模板中成员函数创建时机
//
// 类模板中成员函数与普通成员函数创建时机的区别：
//  1、普通类中成员函数一开始就可以创建（程序运行前创建，存放在代码区）
//  2、类模板成员函数在调用时才创建（确定了成员函数的参数类型后创建，程序运行时创建）

#include <iostream>
using namespace std;

class Person1 {
public:
    void showPerson1(void) const {
        cout << "Person1 show" << endl;
    }
};

class Person2 {
public:
    void showPerson2(void) const {
        cout << "Person2 show" << endl;
    }
};

template<class T>
class myClass {
public:
    T object;

    // 不指明类模板中的成员属性，可以通过编译
    // 说明：类模板的成员函数，只有在被调用时创建
    void func_1(void) const {
        object.showPerson1();
    }
    void func_2(void) const {
        object.showPerson2();
    }
};

void test_1(void) {
    myClass<Person2> mc;
    mc.func_1();
    // 不指明类模板中的成员属性，可以通过编译
    // 说明：类模板的成员函数，只有在被调用时创建
    mc.func_2();
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}