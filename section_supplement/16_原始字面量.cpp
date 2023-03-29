// C++11 : 原始字面量
// 不使用转移字符, 便于换行书写
// gammer 
// R"identifier(string)identifier"
#include <iostream>
using namespace std;
void test_1(void) {
    string s1 = "C:\\Program Files\\Microsoft OneDrive\\tail\\nation";
    string s2 = R"(C:\Program Files\Microsoft OneDrive\tail\nation)";
    cout << "path1 : " << s1 << endl;
    cout << "path2 : " << s2 << endl;

    string s3 = "\
        <name>Harry<name>\
        <age>22<age>\
    ";
    string s4 = R"(
        <name>Harry<name>
        <age>22<age>
    )";
} 

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}