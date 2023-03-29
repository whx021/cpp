// 7、模板——类模板基本语法
//
// 类模板作用：
//  通过建立一个通用类，类中的成员 数据类型 可以不具体制定，用一个虚拟的类型来代表
//
// 总结：
//  1、类模板声明：声明模板后面加类
//  2、类模板使用：创建对象时，使用模板参数列表，指定建立对象的成员属性

#include <iostream>
#include <string>
using namespace std;

// 类模板
template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) : member_name(name), member_age(age) {}

    void showInfo(void) const {
        cout << "name: " << this->member_name << endl;
        cout << "age: " << this->member_age << endl;
    }
private:
    NameType member_name;
    AgeType member_age;
};

void test_1(void) {
    // "<className, className>" 模板参数列表
    Person<string, int> p1("tom", 18);
    Person<string, int> p2("jarry", 19);
    p1.showInfo();
    p2.showInfo();
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
