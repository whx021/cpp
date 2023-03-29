// 8、模板——类模板与函数模板区别
//
// 类模板与函数模板区别的两点：
//  1、类模板没有自动类型推导的使用方式（使用时必须指定好参数列表）
//  2、类模板在模板参数列表中可以有默认参数
//
// 总结：
//  1、类模板只能使用显示指定类型方式
//  2、类模板在模板参数列表中可以有默认参数
//
// 经验1：声明类模板时，填写默认参数
// 经验2：使用模板函数和类模板时建议指定好参数列表（显示指定类型方法）


#include <iostream>
#include <string>
using namespace std;

// 2、类模板在模板参数列表中可以有默认参数
template<class NameType, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) : member_name(name), member_age(age) {}

    void showPerson(void) const {
        cout << "name: " << this->member_name << endl;
        cout << "age: " << this->member_age << endl;
    }
private:
    NameType member_name;
    AgeType member_age;
};

// 1、类模板没有自动类型推导的使用方式
void test_1(void) {
    // Person p1("harry", 1000);   // 错误：类模板无法自动类型推导

    // 正确：只能用显示指定类型
    Person<string, int> p2("harry", 1000);
    p2.showPerson();
}

// 2、类模板在模板参数列表中可以有默认参数
void test_2(void) {
    Person<string> p1("tom", 999);
    p1.showPerson();
}

int main(void) {
    test_2();   
    return EXIT_SUCCESS;
}