// 11、模板——类模板与继承
//
// 当类模板碰到继承时，需注意：
//  1、当子类继承的父类是一个类模板时，子类在声明的时候，需指定出父类中T的类型
//  2、如果不指定，编译器无法给子类分配内存
//  3、如果想灵活指定出父类中T的类型，子类也需要是类模板
//
// 总结：
//  子类继承的父类是一个类模板时，子类在声明的时候，需指定出父类中T的类型

#include <iostream>
using namespace std;

template<class T>
class Base {
public:
    T member;
};

// 当子类继承的父类是一个类模板时，子类在声明的时候，需指定出父类中T的类型
// class Son : public Base // 编译器需要知道非模板子类的内存大小，才能定义

class Son : public Base<int> {
public:
};

void test_1(void) {
    Son s;
}

// 3、如果想灵活指定出父类中T的类型，子类也需要是类模板
template<class T1, class T2>
class Son_2 : public Base<T2> {
public:
    Son_2() {
        cout << "T1的数据类型：" << typeid(T1).name() << endl;
        cout << "T2的数据类型：" << typeid(T2).name() << endl;
    }

    T1 object;
};

void test_2(void) {
    Son_2<int, char> s2;
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}