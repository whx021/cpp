// 14、模板——类模板与友元
//
// 目标：掌握类模板配合友元函数的类内和类外实现
//
// 全局函数类内实现：直接在类内声明友元即可
// 全局函数类外实现：需要提前让编译器知道全局函数的存在
//
// 总结：
//  没有特殊需求，建议全局函数类内实现，用法简单，而且编译器可以直接识别


#include <iostream>
using namespace std;

// 通过全局函数打印Person信息

// 声明Person类模板让编译器提前知道Person类模板的存在
template <class T1, class T2>
class Person;

// 让编译器提前知道函数模板printPerson_2的存在
// 全局函数，类外实现（函数模板的实现）
template <class T1, class T2>
void printPerson_2(const Person<T1, T2> &p) {
    cout << "类外实现" << endl;
    cout << "name:" << p.m_name << endl;
    cout << "age:" << p.m_age << endl;
}

template <class T1, class T2>
class Person {
    // 全局函数，类内实现
    friend void printPerson_1(const Person<T1, T2> &p) {
        cout << "类内实现" << endl;
        cout << "name:" << p.m_name << endl;
        cout << "age:" << p.m_age << endl;
    }

    // 普通函数的声明（需要声明为函数模板，即加上空模板参数列表"<>"）
    // 全局函数类外实现：需要提前让编译器知道全局函数的存在
    // 原因：
    friend void printPerson_2<>(const Person<T1, T2> &p);
public:
    Person(T1 name, T2 age) : m_name(name), m_age(age) {}
private:
    T1 m_name;
    T2 m_age;
};

// 全局函数，类内实现测试
void test_1(void) {
    Person<string, int> p("Tom", 18);
    printPerson_1(p);
}

// 全局函数，类外实现测试
void test_2(void) {
    Person<string, int> p("Jerry", 18);
    printPerson_2(p);
}

int main(void) {
    // test_1();
    test_2();
    return EXIT_SUCCESS;
}
