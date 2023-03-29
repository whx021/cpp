// 21、编写自己的异常类
//
// 总结：
//  自定义异常类（基类为C++标准异常基类exception）
//
// 知识点：string类对象 与 const char* 之间的转换
//
// const char* 可以隐式转换为 string类对象
// string类对象 不可以隐式转换为 const char* 
// string类对象 可以通过其成员函数 c_str(); 转换为 const char*
//
// string类底层实现：
//  用一个指向堆区的 const char* 指针维护堆区的字符数组
//  并添加了许多字符数组处理的成员函数 

#include <iostream>
#include <stdexcept>
using namespace std;

// 自定义异常类（基类为C++标准异常基类exception）
class my_out_of_range : public exception {
public:
    // 有参构造函数
    my_out_of_range(const char* errInfo) {
        // const char* 可以隐式转换为 string类对象
        this->m_ErrInfo = errInfo;
    }

    // 拷贝构造函数
    my_out_of_range(const string& errInfo) {
        // const char* 可以隐式转换为 string类对象
        this->m_ErrInfo = errInfo;
    }

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
        // string类对象 不可以隐式转换为 const char* 
        // string类对象 可以通过其成员函数 c_str(); 转换为 const char*
        return this->m_ErrInfo.c_str();
    }
private:
    string m_ErrInfo;
};

class Person {
public:
    Person(int age) {
        if (age < 0 || age > 150) {
            // 抛出自定义异常类有参构造对象
            throw my_out_of_range("age is out of range");
        }
        else {
            this->m_age = age;
        }
    }
private:
    int m_age;
};

void test_1(void) {
    try {
        Person p(1000);
    }
    catch(const std::exception& e) {
        // 多态体现：
        // 接受方式：C++标准异常基类exception 引用类型
        // 调用 自定义继承类my_out_of_range 重写的 基类虚函数 what()
        std::cerr << e.what() << '\n';
    }
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}