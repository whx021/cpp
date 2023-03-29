#include "swap.h"

void swap::run() {
    int temp;
    temp = m_a;
    m_a = m_b;
    m_b = temp;
}

void swap::printInfo() {
    std::cout << "m_a = " << m_a << std::endl;
    std::cout << "m_b = " << m_b << std::endl;
}