// 19.位运算

// ~ : 按位取反
// & : 按位与(同真为真, 其余为假), 用途 : & 0000 0001 判断数的奇偶性
// | : 按位或(同假为假, 其余为真), 用途 : 让指定的位变为1

// ^ : 按位异或(相同为假, 不同为真)
// A ^ B = C
// B ^ C = A
// C ^ A = B
// 用途 : 实现两个数字交换

//  << : 左移运算
// x << n : 代表数字 x * 2^n

// >> : 右移运算, 并使用0填充高位(有些系统使用1填充)
// x >> n : 代表数字 x / 2^n

#include <iostream>
using namespace std;

// ~
void test_1(void) {
    int num = 2;
    cout << "~num = " << ~num << endl;
    // 原码 : 0000 0000 0000 0010 (0x0002)
    // 补码 : 0000 0000 0000 0010 (0x0002)
    // 取反 : 1111 1111 1111 1101 (0xFFFD)
    // 原码 : 1000 0000 0000 0011 (0x8003)

    int num2 = -2;
    cout << "~num2 = " << ~num2 << endl;
    // 原码 : 1000 0000 0000 0010 (0x8002)
    // 补码 : 1111 1111 1111 1110 (0xFFFE)
    // 取反 : 0000 0000 0000 0001 (0x0001)
    // 原码 : 0000 0000 0000 0001 (0x0001)
}

// & 
void test_2(void) {
    int num = 667;
    if (((num) & 1) == 0 ) {
        cout << "偶数" << endl;
    }
    else {
        cout << "奇数" << endl;
    }
}

// |
void test_3(void) {
    int num1 = 5;
    int num2 = 3;
    cout << num1 << " | " << num2 << " = " << (num1 | num2) << endl;
    // num1原码 : 0000 0000 0000 0101
    // num1补码 : 0000 0000 0000 0101
    // num2原码 : 0000 0000 0000 0011
    // num2补码 : 0000 0000 0000 0011
    // num1 | num2补码: 0000 0000 0000 0111
    // num1 | num2原码: 0000 0000 0000 0111
}

// ^ 
void test_4(void) {
    int num1 = 5;
    int num2 = 10;
    
    // 交换两个数字
    // 方法一 :
    int temp = num1;
    num1 = num2;
    num2 = temp;

    // 方法二 :
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    // 方法三 : 
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}

// << 
void test_5(void) {
    int num = 10;
    cout << "num << 2 = " << (num << 2) << endl;
    cout << "num = " << num << endl;
    cout << "num <<= 2 = " << (num <<= 2) << endl;
    cout << "num = " << num << endl;
}

// >> 
void test_6(void) {
    int num = 80;
    cout << "num >> 3 = " << (num >> 3) << endl;
    cout << "num = " << num << endl;
    cout << "num >>= 3 = " << (num >>= 3) << endl;
    cout << "num = " << num << endl;
}

int main(void) {
    test_6();

    return EXIT_SUCCESS;
}