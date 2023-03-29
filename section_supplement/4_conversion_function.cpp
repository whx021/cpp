// conversion function 
#include <iostream>
// 一般不采用 conversion function, 而是使用member function converse type
// 特殊 : fraction conversion function converse to double in STL

void test_1(void) {
    std::string name = "Harry";     // 隐式转换
    // string class don't have conversion function from string to const char*
    // const char* ptr = name;      
    // but string class give member method get the const char* : c_str()   
    const char* ptr = name.c_str(); 
}

class Person {
public:
    int m_age;
    double m_weight;
    std::string m_name;
    // default constructor
    Person() : m_age(0), m_weight(0) {
        m_name.clear();
    }
    // C++11 : explicit 修饰 conversion function
    explicit operator int() const {
        return m_age;
    }
    operator double() const {
        return m_weight;
    }
    operator std::string() const {
        return m_name;
    }
};

void test_2(void) {
    Person p;
    // call conversion method 1 : 隐式转化法
    int a = p;
    std::cout << "a = " << a << std::endl;
    // call conversion method 2 : 强制类型转换法
    double b = (double)p;
    std::cout << "b = " << b << std::endl;
    // call conversion method 3 : 直接调用转化函数法
    std::string c = std::string(p);
    std::cout << "c = " << c << std::endl;
    // ambiguity error : int || double
    short d = p; 
    // answer : 
    // 1. 强制类型转换法
    // 2. 直接调用转化函数法
    // 3. int || double conversion function used explicit 
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
} 