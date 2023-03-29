//6、string容器——字符串拼接

/*
1、重载运算符
string& operator += (const char* s);
string& operator += (const char c);
string& operator += (const string& str);

2、成员函数
string& append(const char* s);
string& append(const char *s, int n);   //将字符串s的前n个字符拼接到当前string类对象
string& append(const string& str);      
//将string类对象str的从pos开始的前n个字符拼接到当前string类对象  
string& append(const string& str, int pos, int n);  
*/

#include <iostream>
#include <string>
using namespace std;

void test(void)
{
    string temp;

    string str1 = "广末";
    str1 += "凉子";
    cout << "str1 = " << str1 << endl;

    string str2 = "广末";   
    str2 += 'a'; 
    cout << "str2 = " << str2 << endl;

    string str3 = "广末";   temp = "凉子";
    str3 += temp;
    cout << "str3 = " << str3 << endl;

    string str4 = "广末";
    str4.append("凉子");
    cout << "str4 = " << str4 << endl;

    string str5 = "love ";
    str5.append("Ryoko凉子", 5);
    cout << "str5 = " << str5 << endl;

    string str6 = "广末";   temp = "凉子";
    str6.append(temp);
    cout << "str6 = " << str6 << endl;

    string str7 = "广末";   temp = "love Ryoko";
    str7.append(temp, 5, 5);
    cout << "str7 = " << str7 << endl;

}

int main(void)
{
    test();

    return EXIT_SUCCESS;
}