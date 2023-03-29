// conversion function 转换函数
// non-explicit-one-argument-ctor
#include <iostream>
using namespace std;

// explicit 可修饰 constructor & conversion function

class Fraction {
public:
    explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    // conversion function
    operator double() const {
        return (double)(m_numerator / m_denominator);
    }
    Fraction operator + (const Fraction& f) {
        // return Fraction();
    }
private:
    int m_numerator;
    int m_denominator;
};

void test_1(void) {
    // have conversion function
    // no overload operator + ()
    Fraction f(3, 5);
    double d = 4 + f;   // 调用operator double()将 f 转为 0.6
    cout << "d = " << d << endl;
}

void test_2(void) {
    // no conversion function
    // have non-explicit-one-argument-ctor
    // have overload operator + ()
    Fraction f1(3, 5);
    // Fraction f2 = f1 + 4;   // 调用non-explicit-ctor将4转为Fraction, 并调用operator +
}

void test_3(void) {
    // have conversion function & non-explicit-one-argument-ctor
    // have overload operator + ()
    Fraction f1(3, 5);
    // Fraction f2 = f1 + 4;   // [Error] ambiguous 
}

void test_4(void) {
    // conversion function & explicit-one-argument-ctor
    // & operator + 
    Fraction f1(3, 5);
    // Fraction f2 = f1 + 4;   // [Error] conversion from 'double' to 'Fraction' requested
}

int main(void) {
    test_1();
    return EXIT_SUCCESS; 
} 