//4、string容器——构造函数
/*
string类构造函数：
string();       //无参构造
string(const char* s);      //有参构造
string(const string& str);  //拷贝构造
string(int n, char c);      //使用n个c初始化字符串
*/

#include <iostream>
#include <string>
using namespace std;

void test_1(void)
{
    //默认构造
    string str1;

    //有参构造
    const char* s = "Hello world";
    string str2(s);
    cout << str2 << endl;

    //拷贝构造
    string str3(str2);
    cout << str3 << endl;

    //初始化构造
    string str4(5, 'a');
    cout << str4 << endl;

}

int main(void)
{
    test_1();

    return EXIT_SUCCESS;
}