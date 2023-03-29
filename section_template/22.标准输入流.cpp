// 22、标准输入流
//
// I：int 输入： 输入文件 数据 程序
// O：out 输出： 程序 数据 输出文件
//
// 标准I/O：I（键盘）O（显示器），键盘、显示器，C++中均为文件
//
// 文件I/O：I（写文件）O（读文件）
//
// 串I/O：I（对字符串写入）O（对字符串输出）
//
// 标准输入输出类：
//  ios类：抽象基类
//  istream类，ostream类
//  ifstream类，iostream类，ofstream类
//  fstream类
//
// 缓冲区：输入缓冲区、输出缓冲区

// 标准输入流istream对象 cin 的成员函数
/*
cin.get();          // 一次只读取一个字符（从缓冲区中）

cin.get(一个参数);   // 读一个字符

cin.get(两个参数);   // 可以读字符串    // 且换行符遗留在缓存区中

cin.getline();      // 可以读字符串    // 且换行符未遗留在缓存区中

cin.ignore();       // 忽略，默认忽略缓冲区的一个字符，抽取缓冲区的一个字符

cin.peek();         // 偷窥，获取缓冲区的字符，但是不抽取

cin.putback();      // 放回，插入，将字符放回起始的位置
*/

#include <iostream>
using namespace std;

void test_1(void) {
    char ch;
    ch = cin.get();
    cout << "ch = " << ch << endl;

    ch = cin.get();
    cout << "ch = " << ch << endl;

    ch = cin.get();
    cout << "ch = " << ch << endl;

    ch = cin.get();
    cout << "ch = " << ch << endl;
}

void test_2(void) {
    // char ch;
    // // 通过函数返回值，给字符赋值
    // ch = cin.get();

    // // 通过参数赋值，给字符赋值
    // cin.get(ch);

    // cin.get(两个参数)   // 可以读字符串

    // 使用cin >> buffer，遇到 空格符' ' || 换行符'\n' 会刷新缓存区，空格符后面的内容无法读取 
    // 使用cin.get(buffer, 1024) 遇到 换行符'\n'停止读取 
    
    // 且换行符遗留在缓存区中
    char buffer[1024] = { 0 };
    cin.get(buffer, 1024);  // 参数1：输入的字符串存放的字符串数组 参数2：输入字符串字符最大个数

    char ch;
    ch = cin.get();
    if (ch == '\n') {
        cout << "ch == \'\\n\'，换行符遗留在缓存区中" << endl;
    }
    else {
        cout << "ch != \'\\n\'，换行符未遗留在缓存区中" << endl;
    }

    cout << "buffer = " << buffer << endl;
}

void test_3(void) {
    // 且换行符未遗留在缓存区中
    char buffer[1024] = { 0 };
    cin.getline(buffer, 1024);  // 参数1：输入的字符串存放的字符串数组 参数2：输入字符串字符最大个数

    char ch;
    ch = cin.get();
    if (ch == '\n') {
        cout << "ch == \'\\n\'，换行符遗留在缓存区中" << endl;
    }
    else {
        cout << "ch != \'\\n\'，换行符未遗留在缓存区中" << endl;
    }

    cout << "buffer = " << buffer << endl;
}

void test_4(void) {
    cin.ignore();       // 忽略，默认忽略缓冲区的一个字符，抽取缓冲区的一个字符
    // cin.ignore(n);   // 重载版本，指定忽略缓冲区的n个字符，抽取缓冲区的n个字符
    char ch = cin.get();
    cout << "ch = " << ch << endl;
}

void test_5(void) {
    // cin.peek();      // 偷窥，获取缓冲区的字符，但是不抽取
    char ch = cin.peek();
    cout << "ch = " << ch << endl;
    ch = cin.get();
    cout << "ch = " << ch << endl;
}

void test_6(void) {
    // cin.putback();   // 放回，插入
    char ch = cin.get();
    cin.putback(ch);    // 将字符放回起始的位置

    char buffer[1024] = { 0 };
    cin.getline(buffer, 1024);
    cout << "buffer = " << buffer << endl;
}

int main(void) {
    test_5();
    return EXIT_SUCCESS;
}