// 10、模板——类模板对象做函数参数
//
// 三种传入方式：
//  1、指定传入的类型     --直接显示对象的数据类型
//  2、参数模板化         --将对象中的参数变为模板进行传递
//  3、整个类模板化       --将这个对象类型模板化进行传递
//
// 总结：
//  使用比较广泛的是第一种（简单明了）
//  后两种方式为函数模板配合类模板
//
//  使用 typeid(type_name).name() 类的函数查看type_name类型的名称

#include <iostream>
using namespace std;

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) : member_name(name), member_age(age) {}

    void showPerson(void) const {
        cout << "name:" << this->member_name << endl;
        cout << "age:" << this->member_age << endl;
    }
private:
    T1 member_name;
    T2 member_age;
};

// 1、指定传入的类型     --直接显示对象的数据类型
void PrintPerson_1(const Person<string, int>& p) {
    p.showPerson();
}

void test_1(void) {
    Person<string, int> p1("Tom", 18);
    PrintPerson_1(p1);
}

// 2、参数模板化         --将对象中的参数变为模板进行传递
template<class T1, class T2>
void PrintPerson_2(const Person<T1, T2>& p) {
    p.showPerson();
    cout << "T1的类型为：" << typeid(T1).name() << endl;
    cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test_2(void) {
    Person<string, int> p2("harry", 18);
    PrintPerson_2(p2);
}

// 3、整个类模板化       --将这个对象类型模板化进行传递
template<class T>
void PrintPerson_3(const T& p) {
    p.showPerson();
    cout << "T的类型为：" << typeid(T).name() << endl;
}

void test_3(void) {
    Person<string, int> p3("jack", 19);
    PrintPerson_3(p3);
}

int main(void) {
    test_3();
    return EXIT_SUCCESS;
}