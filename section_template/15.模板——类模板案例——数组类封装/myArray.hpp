#ifndef _MyArray_HPP_
#define _MyArray_HPP_

#include <iostream>
#include <string>
#include <cassert>
using namespace std;


template<class T>
class MyArray {
private:
    T* pAddress;    // 指向堆区的数组数据
    int m_Capacity; // 记录数组的容量
    int m_Size;     // 记录数组的大小
public:
    // 构造函数
    MyArray(int capacity) : m_Capacity(capacity), m_Size(0), pAddress(new T[capacity]) {
        // cout << "myArray有参构造函数调用" << endl;
    }

    // 拷贝构造函数（防止浅拷贝）
    MyArray(const MyArray& arr) {
        // cout << "myArray拷贝构造函数调用" << endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        
        // 浅拷贝（内存重复释放的错误）
        // this->pAddress = arr.pAddress;

        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < arr.m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 析构函数
    ~MyArray() {
        // cout << "myArray析构函数调用" << endl;

        m_Capacity = 0;
        m_Size = 0;
        if (pAddress != nullptr) {
            delete[] pAddress;
            pAddress = nullptr;
        }
    }

    // 重载"="赋值运算符（防止浅拷贝）
    MyArray& operator=(const MyArray& arr) {   
        // cout << "myArray重载\"=\"函数调用" << endl;

        // 清空原来数据
        if (this->pAddress != nullptr) {
            this->m_Capacity = 0;
            this->m_Size = 0;
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
        // 拷贝arr数组数据
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < arr.m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 通过下标的方式访问数组中的元素函数
    T& operator[](int index) const {
        assert(index >= 0 && index <= this->m_Size - 1);
        return this->pAddress[index];
    }

    // 尾插法
    void Insert_tail(const T& e) {
        if (this->m_Capacity == this->m_Size) {
            // TODO : 抛出插入操作失败异常
            throw out_of_range("[Error] : array access is out of range");
            return;
        }
        this->pAddress[this->m_Size] = e;
        ++this->m_Size;
    }

    // 尾删法
    void Delete_tail(void) {
        if (this->m_Size == 0) {
            throw out_of_range("[Error] : array access is out of range");
            return;
        }
        --this->m_Size;
    }

    // 获取数组容量
    int GetCapacity(void) const {
        return this->m_Capacity;
    }

    // 获取数组大小
    int GetSize(void) const {
        return this->m_Size;
    }
};


#endif