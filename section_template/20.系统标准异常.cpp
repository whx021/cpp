// 20、系统标准异常

#include <iostream>
// 包含C++标准异常类
#include <stdexcept>    // std:标准  except:异常
using namespace std;

class Person {
public:
    Person(int age) {
        if (age < 0 || age > 150) {
            throw out_of_range("age is out of range");
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
        // 返回方式：C++标准异常继承类 out_of_range 类型
        // 接受方式：C++标准异常基类 exception 引用类型
        // 调用 C++标准异常继承类out_of_range 重写的 基类虚函数 what()
        std::cerr << e.what() << '\n';
        // cerr 标准错误输入流
    }
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}