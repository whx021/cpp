// 自动类型转化
#include <iostream>

// class 隐式转换场景
// 1. 将Person对象初始化为int型时.      Person p = 8;
// 2. 将int型赋值给Person object时.    Person p; p = 8;
// 3. 将int型传递给接受Person参数的函数时. 
// 4. 函数返回值被声明为Person函数, 并试图返回int值时.
// 5. 上述任意一种情况下, 使用可转化为int类型的内置类型时.

// explicit : 关闭自动类型转化

// note :
// 1. 自动类型转化有二义性, 编译器报错 [Error] ambiguity

class Person {
public:
    int m_age;
    double m_weight;
    std::string m_name;

    // default constructor
    Person() : m_age(0), m_weight(0) {
        m_name.clear();
        std::cout << "default constructor call" << std::endl; 
    }
    // copy constructor
    Person(int age) : m_age(age), m_weight(0) {
        m_name.clear();
        std::cout << "Person(int) constructor call" << std::endl;
    }
    Person(double weight) : m_age(0), m_weight(weight) {
        m_name.clear();
        std::cout << "Person(double) constructor call" << std::endl;
    }
    // show method
    void show(void) const {
        std::cout << "age : " << m_age << std::endl;
        std::cout << "weight : " << m_weight << std::endl;
        std::cout << "name : " << m_name << std::endl;
    }
};

// 3. 将int型传递给接受Person参数的函数时. 
void func_1(Person p) {
    p.show();
}

// 4. 函数返回值被声明为Person函数, 并试图返回int值时
Person func_2(void) {
    return 8;
}

// 5. 上述任意一种情况下, 使用可转化为int类型的内置类型时.
Person func_3(void) {
    char c = 8;
    return c;
}

void test_1(void) {
    // Person p1(8);   // 常规调用constructor
    // Person p1 = Person(8);  // 显示转化 : 实质调用class中默认 operator = () method
    // // 隐式转换实质 : 
    // //  1. 调用 object p1 default constructor  
    // //  2. 调用 constructor temporary object Person(8)
    // //  3. 调用 class 中默认 operator = () function : Person p1 = Person(8);
    // // 隐式转换的一部写法
    // Person p1 = 8;    
    // 隐式转换的两部写法 
    Person p1;
    p1 = 8.7;
    p1.show();
}

void test_2(void) {
    // class 隐式转换场景
    // 将int传递给Person参数函数时
    // func_1(8);
    func_3();
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}