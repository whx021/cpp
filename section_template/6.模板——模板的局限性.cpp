// 6、模板——模板的局限性
//
// 模板的通用型并不是万能的：无法直接处理特定数据类型
//
// C++解决方案：
//  提供模板的重载，可以为特定的数据类型提供具体化的模板
//
// C++解决模板无法处理自定义类型数据方法：
//  1、运算符重载
//  2、函数模板重载
//
// 总结：
//  1、利用具体化的函数模板，可以解决自定义类型的通用化
//  2、学习模板并不是为了写模板，而是为在STL中能够运用系统提供的模板

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(string name, int age) : member_name(name) , member_age(age) {}

    string member_name;
    int member_age;
};

// 对比函数模板
template<typename T>
bool myCompare(const T& a, const T& b) {
    if (a == b) {
        return true;
    }
    else {
        return false;
    }
}

// 2、函数模板重载(函数模板特化)
// 利用具体化Person的函数模板的版本实现代码，具体化优先调用
// template：告诉编译器为函数模板的重载版本
template<typename T> 
bool myCompare(const Person& a, const Person& b) {
    if (a.member_name == b.member_name && a.member_age == b.member_age) {
        return true;
    }
    else {
        return false;
    }
}

void test_1(void) {
    int a = 10;
    int b = 20;
    bool result = myCompare<int>(a, b);
    
    if (result) {
        cout << "a == b" << endl;
    }
    else {
        cout << "a != b" << endl;
    }
}

void test_2(void) {
    Person p1("Tom", 18);
    Person p2("Tom", 18);

    bool result = myCompare<Person>(p1, p2);
    
    if (result) {
        cout << "p1 == p2" << endl;
    }
    else {
        cout << "p1 != p2" << endl;
    }
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}