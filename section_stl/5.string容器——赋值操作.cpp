//5、string容器——赋值操作

#include <iostream>
#include <string>
using namespace std;

/*
1、重载运算符   （好用）
string& operator = (const char* s);     
string& operator = (char c);
string& operator = (const string& str);

2、成员函数
string& assign(const char* s);
string& assign(const char* s, int n);   //将字符串s的前n个字符赋值给string类对象
string& assign(const string& str);
string& assign(int n, char c);      //用n个字符'c'赋值给string类对象
*/

int main(void)
{
    string str1;
    str1 = "Hello world";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("Hello c++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("Hello c++", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    //错误
    // string str7;
    // str7.assign(str5, 5);
    // cout << "str7 = " << str7 << endl;

    string str8;
    str8.assign(10, 'a');
    cout << "str8 = " << str8 << endl;

    return EXIT_SUCCESS;
}