#pragma once
#include <iostream>

class swap {
public:
    swap(int a, int b) : m_a(a), m_b(b) {}
    void run();
    void printInfo();
private:
    int m_a;
    int m_b;
};
