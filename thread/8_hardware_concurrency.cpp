#include <iostream>
#include <thread>

int main(void) {
    int thread_num = std::thread::hardware_concurrency();
    std::cout << "the hardware concurrency number = " << thread_num << std::endl;
    return EXIT_SUCCESS;
}