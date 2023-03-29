// initializer list
#include <iostream>
#include <vector>
#include <initializer_list>

double sum(std::initializer_list<double> il) {
    double total = 0;
    for (const auto& i : il) {
        total += i;
    }
    return total;
}

int main(void) {
    double total = sum({3.14, 3.15, 5.20});
    std::cout << "total = " << total << std::endl;
}