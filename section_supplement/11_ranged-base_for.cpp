// ranged-base for (since C++11) 语法糖
/* grammar : 
for ( declare : collection ) {
    statement;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test_1(void) {
    for (int i : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }) {
        cout << i << endl;
    }
}

void test_2(void) {
    vector<double> vec;
    // pass by value
    for (const auto& elem : vec) {
        cout << elem << endl;
    } 

    // pass by reference
    for (auto& elem : vec) {
        elem *= 3;
    }
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}