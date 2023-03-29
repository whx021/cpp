#include <iostream>
using namespace std;
#include "myString.h"

void test_1(void) {
    MyString str_1 = "abcde";
    MyString str_2 = str_1;
    cout << "str_1 = " << str_1 << endl;
    cout << "str_2 = " << str_2 << endl;

    // char buffer_1[64] = {0};
    // char buffer_2[64] = {0};
    // cin >> buffer_1 >> buffer_2;
    // cout << "buffer_1 = " << buffer_1 << endl;
    // cout << "buffer_2 = " << buffer_2 << endl;

    cout << "请重新给str_1赋值" << endl;
    cin >> str_1;
    cout << "str_1 = " << str_1 << endl;
}

void test_2(void) {
    MyString str_1 = "abc";
    MyString str_2 = "def";
    cout << "str_1 = " << str_1 << endl;
    str_1 = str_2;
    cout << "str_1 = " << str_1 << endl;
    str_1 = "ghi";
    cout << "str_1 = " << str_1 << endl;
}

void test_3(void) {
    MyString str_1 = "abc";
    cout << "str_1[0] = " << str_1[0] << endl;
    str_1[0] = 'z';
    cout << "str_1 = " << str_1 << endl;
}

void test_4(void) {
    MyString str_1 = "abc";
    MyString str_2 = "def";
    MyString str_3 = str_1 + str_2;
    MyString str_4 = str_1 + "def";
    cout << "str_3 = " << str_3 << endl;
    cout << "str_4 = " << str_4 << endl;
}

void test_5(void) {
    MyString str_1 = "abc";
    MyString str_2 = "def";

    if (str_1 == str_2) {
        cout << "str_1 == str_2" << endl;
    }
    else {
        cout << "str_1 != str_2" << endl;
    }

    if (str_1 == "abc") {
        cout << "str_1 == \"abc\"" << endl;
    }
    else {
        cout << "str_1 != \"abc\"" << endl;
    }
}

int main(void) {
    // test_1();
    // test_2();
    // test_3();
    // test_4();
    test_5();
    return EXIT_SUCCESS;
}