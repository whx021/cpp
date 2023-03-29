#include "myString.h"

// 有参构造
MyString::MyString(const char* str) {
    this->m_string = new char[sizeof(str) + 1];
    strcpy(this->m_string, str);
    this->m_length = strlen(str);
} 

// 拷贝构造
MyString::MyString(const MyString& myStr) {
    this->m_string = new char[sizeof(myStr.m_string) + 1];
    strcpy(this->m_string, myStr.m_string);
    this->m_length = myStr.m_length;
}

// 析构
MyString::~MyString() {
    if (this->m_string != nullptr) {
        delete[] this->m_string;
        this->m_string = nullptr;
    }
    this->m_length = 0;
}

// 重载"<<"运算符
ostream& operator<<(ostream& cout, MyString& myStr) {  
    cout << myStr.m_string;
    return cout;
}

// 重载">>"运算符
istream& operator>>(istream& cin, MyString& myStr) {
    if (myStr.m_string != nullptr) {
        delete[] myStr.m_string;
        myStr.m_string = nullptr;
    }
    char buffer[1024] = {0};
    cin >> buffer;
    myStr.m_string = new char[sizeof(buffer) + 1];
    strcpy(myStr.m_string, buffer);
    myStr.m_length = strlen(buffer);

    return cin;
}

// 重载"="运算符
MyString& MyString::operator=(const char* str) {
    if (this->m_string != nullptr) {
        delete[] this->m_string;
        this->m_string = nullptr;
    }
    this->m_string = new char[sizeof(str) + 1];
    strcpy(this->m_string, str);
    this->m_length = strlen(str);
    return *this;
}
MyString& MyString::operator=(const MyString& myStr) {
    if (this->m_string != nullptr) {
        delete[] this->m_string;
        this->m_string = nullptr;
    }
    this->m_string = new char[sizeof(myStr.m_string) + 1];
    strcpy(this->m_string, myStr.m_string);
    this->m_length = strlen(myStr.m_string);
    return *this;
}

// 重载"[]"运算符
char& MyString::operator[](const unsigned int& pos) {
    if (pos < 0 || pos >> this->m_length) {
        // TODO:抛出越界访问数组异常
    }
    return this->m_string[pos];
}

// 重载"+"运算符
MyString MyString::operator+(const char* str) {
    int new_size = this->m_length + strlen(str) + 1;
    char* buffer = new char[new_size];
    memset(buffer, 0, new_size + 1);
    strcat(buffer, this->m_string);
    strcat(buffer, str);
    MyString newString(buffer);
    delete[] buffer;
    return newString;
}
MyString MyString::operator+(const MyString& myStr) {
    int new_size = this->m_length + myStr.m_length + 1;
    char* buffer = new char[new_size];
    memset(buffer, 0, new_size);
    strcat(buffer, this->m_string);
    strcat(buffer, myStr.m_string);
    MyString newString(buffer);
    delete[] buffer;
    return newString;
}

// 重载"=="运算符
bool MyString::operator==(const char* str) {
    if (strcmp(this->m_string, str) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool MyString::operator==(const MyString& myStr) {
    if (strcmp(this->m_string, myStr.m_string) == 0) {
        return true;
    }
    else {
        return false;
    }
}