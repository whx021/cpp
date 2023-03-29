// 23、标准输入流案例

#include <iostream>
using namespace std;

// 案例1：判断用户输入的信息是字符串还是数字
void test_1(void) {
    cout << "请输入字符串或数字:" << endl;
    
    // 偷窥
    char ch;
    ch = cin.peek();
    
    if (ch >= '0' && ch <= '9') {
        int num;
        cin >> num;
        cout << "你输入的数字为：" << num << endl;
    }
    else {
        char str[1024] = { 0 };
        cin >> str;
        cout << "你输入的字符串为：" << str << endl;
    }
}

// 案例2：提示用户输入一个'1'~'10'间的数字，如果输入有误，重新输入
void test_2(void) {
    cout << "请输入一个'1'~'10'间的数字" << endl;
    while (true) {
        // 用户输入数字时，int型的num变量可以抽取缓冲区的数字，
        // 用户输入字符串时，int型的num变量无法抽取缓冲区的字符串，字符串仍然存放在缓冲区，导致死循环
        int num;
        cin >> num;
        if (num >= 1 && num <= 10) {
            cout << "你的输入正确，输入的值为：" << num << endl;
            break;
        }
        cout << "您的输入错误，请重新输入：" << endl;

        // 缓冲区标志位：cin.fail()判断流操作是否失败.如果输入失败就会返回true.
        // cout << "标志位：" << cin.fail() << endl;
        // 1、重置标志位
        cin.clear();
        // 2、刷新缓冲区
        // cin.sync(); // 高版本已无效
        char buffer[1024] = {0};
        cin.getline(buffer, 1024);
    }
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}