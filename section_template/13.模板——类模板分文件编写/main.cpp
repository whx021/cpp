// 13、模板——类模板分文件编写
//
// 问题：
// 类模板成员函数创建是在调用阶段，导致分文件编写时链接不到
//
// 解决：
//  方法一：直接包含.cpp源文件
//  方法二（主流方法）：将声明和实现写到同一文件中，并更改后缀名为.hpp，
//  .hpp是约定的名称，并不是强制，告诉别人是一个类模板

#include <iostream>
#include <string>
using namespace std;
#include "person.hpp"

// template<class T1, class T2>
// class Person {
// public:
//     T1 member_name;
//     T2 member_age;

//     Person(T1 name, T2 age);

//     void showPerson(void) const;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age) : member_name(name), member_age(age) {}

// template<class T1, class T2>
// void Person<T1, T2>::showPerson(void) const {
//     cout << "name:" << this->member_name << endl;
//     cout << "age:" << this->member_age << endl; 
// }

void test_1(void) {
    Person<string, int> p("Harry", 18);
    p.showPerson();
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}