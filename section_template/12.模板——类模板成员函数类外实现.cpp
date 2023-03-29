// 12、模板——类模板成员函数类外实现
//
// 总结：
//  类模板中成员函数类外实现时，需要加上模板参数列表

#include <iostream>
using namespace std;

template <class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);
    // {
    //     this->member_name = name;
    //     this->member_age = age;
    // }

    void showPerson(void);
    // {
    //     cout << "name:" << this->member_name << endl;
    //     cout << "age:" << this->member_age << endl;
    // }

    T1 member_name;
    T2 member_age;
};

// 类模板成员函数的类外实现
// 记忆方法：
// template<class T1, class T2>:
// 声明类外函数所使用的数据类型T1, T2，且告诉编译器该函数是一个模板函数
// className<T1, T2>:
// 声明其作用域为一个类模板内部
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) 
{
    this->member_name = name;
    this->member_age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson(void) {
    cout << "name:" << this->member_name << endl;
    cout << "age:" << this->member_age << endl;
}

void test(void) {
    Person<string, int> p("tom", 18);
    p.showPerson();
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}