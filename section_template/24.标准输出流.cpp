// 24、标准输出流

#include <iostream>
#include <cstring>
#include <iomanip>  // 只用 输出流控制符 头文件
using namespace std;

/*
cout.flush()    //刷新缓冲区

cout.put()      //向输出流缓冲区插入字符

cout.write()    //从buffer中写num个字节到当前输出流中
*/

void test_1(void) {
    cout.put('h').put('e').put('l');

    char buffer[1024] = "hello world";
    cout.write(buffer, strlen(buffer));

    cout << "hello world" << endl;
}

// 格式化输出

// 1、通过流对象成员函数
void test_2(void) {
    int num = 99;
    cout.width(20);             // 设置输出宽度
    cout.fill('*');             // 设置空白填充
    cout.setf(ios::left);       // 设置左对齐
    cout.unsetf(ios::dec);      // 取消设置十进制
    cout.setf(ios::hex);        // 设置十六进制
    cout.setf(ios::showbase);   // 设置显示进制基数
    cout.unsetf(ios::hex);      // 取消设置十六进制
    cout.setf(ios::oct);        // 设置八进制
    cout << num << endl;
}

// 2、通过控制符（包含 <iomanip> 头文件）
void test_3(void) {
    int num = 00;
    cout << setw(20)                    // 设置输出宽度
         << setfill('~')                // 设置空白填充
         << setiosflags(ios::showbase)  // 设置显示进制基数
         << setiosflags(ios::left)      // 设置左对齐
         << hex                         // 设置十六进制
         << num                         //
         << endl;                       //
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}