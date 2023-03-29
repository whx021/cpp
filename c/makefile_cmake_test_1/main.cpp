#include "swap.h"

int main(int argc, char **argv) {
    swap my_swap(10, 20);
    std::cout << "Before swap" << std::endl;
    my_swap.printInfo();
    my_swap.run();
    std::cout << "After  swap" << std::endl;
    my_swap.printInfo();

    return EXIT_SUCCESS;
}