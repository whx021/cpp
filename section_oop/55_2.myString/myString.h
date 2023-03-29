#include <iostream>
#include <cstring>
using namespace std;

// 自定义字符串类型
class MyString {
    // 重载"<<"运算符
    friend ostream& operator<<(ostream& cout, MyString& myStr);
    // 重载">>"运算符
    friend istream& operator>>(istream& cin, MyString& myStr);
public:
    // 有参构造函数
    MyString(const char* str);
    // 拷贝构造函数
    MyString(const MyString& myStr);
    // 析构函数
    ~MyString();
    // 重载"="运算符
    MyString& operator=(const char* str); 
    MyString& operator=(const MyString& myStr);
    // 重载"[]"运算符
    char& operator[](const unsigned int& pos);
    // 重载"+"运算符
    MyString operator+(const char* str);
    MyString operator+(const MyString& myStr);
    // 重载"=="运算符
    bool operator==(const char* str);
    bool operator==(const MyString& myStr);
private:
    char* m_string;
    int m_length;
};