// typeid运算符 type_info类
#include <iostream>
#include <typeinfo>
// typeid : 获取数据类型的信息
// grammar :
// 1. typeid(数据类型)
// 2. typeid(变量名 || 表达式)
// return : type_info class (include <typeinfo>) object reference
// type_info class member method name() return : (string)class name
// type_info class overloaded '==' && '!=', compare two classes
// typeid(*ptr), ptr == nullptr, 如果ptr多态类型, 将引发 bad_typeid exception

void test_1(void) {
    int ii = 3;
    int* pii = &ii;
    int& rii = ii;
    std::cout << "typeid(int) = " << typeid(int).name() << std::endl;
    std::cout << "typeid(ii) = " << typeid(ii).name() << std::endl;
    std::cout << "typeid(int*) = " << typeid(int*).name() << std::endl;
    std::cout << "typeid(pii) = " << typeid(pii).name() << std::endl;
    std::cout << "typeid(int&) = " << typeid(int&).name() << std::endl;
    std::cout << "typeid(rii) = " << typeid(rii).name() << std::endl;
}

class Person {
public:
    Person() {}
};

void test_2(void) {
    Person p;
    Person* pp = &p;
    Person& rp = p;
    std::cout << "typeid(Person) = " << typeid(Person).name() << std::endl;
    std::cout << "typeid(p) = " << typeid(p).name() << std::endl;
    std::cout << "typeid(Person*) = " << typeid(Person*).name() << std::endl;
    std::cout << "typeid(pp) = " << typeid(pp).name() << std::endl;
    std::cout << "typeid(Person&) = " << typeid(Person&).name() << std::endl;
    std::cout << "typeid(rp) = " << typeid(rp).name() << std::endl;

    // type_info class overloaded '==' && '!=', compare two classes
    if (typeid(Person) == typeid(p)) {
        std::cout << "typeid of Person == typeid of p" << std::endl;
    }
    else {
        std::cout << "typeid of Person != typeid of p" << std::endl;
    }

    if (typeid(Person) == typeid(*pp)) {
        std::cout << "typeid of Person == typeid of *pp" << std::endl;
    }
    else {
        std::cout << "typeid of Person != typeid of *pp" << std::endl;
    }

    if (typeid(Person) == typeid(rp)) {
        std::cout << "typeid of Person == typeid of rp" << std::endl;
    }
    else {
        std::cout << "typeid of Person != typeid of rp" << std::endl;
    }

    if (typeid(Person*) == typeid(pp)) {
        std::cout << "typeid of Person* == typeid of pp" << std::endl;
    }
    else {
        std::cout << "typeid of Person* != typeid of pp" << std::endl;
    }
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}