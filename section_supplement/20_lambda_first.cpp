/**
 * @file 20_lambda_first.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief lambda expression first exploration
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Lambda expression is essentially an anonymous functor

#include <iostream>

class AddNum {
public:
    AddNum(int num) : num_(num) {}
    
    int addNum(int x) const {
        return num_ + x;
    }

    int operator () (int x) {
        return num_ + x;
    }
private:
    int num_;
};

void test_1(void) {
    // use functor
    AddNum add_num = AddNum(10);
    // int x = add_num.addNum(5); // call const member function
    int x = add_num(5); // call functor
    std::cout << "x = " << x << std::endl;

    // use lambda
    auto add_num2 = [lambda_num = 10] (int x) {
        return lambda_num + x;
    };
    int lambda_x = add_num2(5);
    std::cout << "lambda_x = " << x << std::endl;  
}

/**
 * @brief lambda general form
 *  [capture](parameters)->return_class { body; };
 *  capture : 捕获列表
 *  parameters : 参数列表
 *  return_class : 返回值类型
 *  body : 函数体
 * 
 *  捕获列表
 *  [] : 不捕获任何变量
 *  [=] : 按值捕获变量
 *  [&] : 按应用捕获变量
 */
#include <functional>
void test_2(void) {
    // record lambda expression
    // sts::function<int(int)> can replace with auto key word
    std::function<int(int)> func = [] (int x) -> int {
        return ++x;
    };
    for (int i = 0; i < 10; ++i) {
        std::cout << func(i) << std::endl;
    }
}

#include <vector>
#include <algorithm>

// use function
void print_arr_function(int x) {
    std::cout << "x = " << x << std::endl;
}

// use functor
struct printArr {
    void operator () (int x) {
    std::cout << "x = " << x << std::endl;
    }
}print_arr_functor;

void test_3(void) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::for_each(arr.begin(), arr.end(), print_arr_function);  // use function
    std::for_each(arr.begin(), arr.end(), print_arr_functor);   // use functor
    int multiplier = 2; 
    std::for_each(arr.begin(), arr.end(), [=](int x)->void {   // use lambda
        std::cout << "x = " << x * multiplier << std::endl;
    });    
}

int main(void) {
    // test_1();
    // test_2();
    test_3();
    return EXIT_SUCCESS;
}