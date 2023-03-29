// 2.calloc && realloc

#include <iostream>
using namespace std;
#include <cstdlib>
/*
 * FunctionName : calloc()
 * Description : request a heap space
 * Parameter 1 : the num of object
 * Parameter 2 : the size of object(unit : Byte)
 * return : a pointer point allocated space
 * 
 * Different with malloc : 使用0初始化分配的空间
 * 
 * object* = (object*)calloc(num, sizeof(object))
 * 
 * object* = (object*)malloc(sizeof(object) * num);
 * memset(object, 0, sizeof(*object))
 */

/*
 * FunctionName : realloc()
 * Description : reapply a heap space
 * Parameter 1 : a pointer of original pile space 
 * Parameter 2 : new size of heap space  
 * return : a pointer point allocated space
 */

void test_1(void) {
    // int* p = (int*)malloc(sizeof(int) * 10);
    int* p = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << endl;
    }
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
    }
}

void test_2(void) {
    int* p = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 100;
    }
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << endl;
    }
    cout << p << endl;
    p = (int*)realloc(p, sizeof(int) * 200);
    cout << p << endl; 
    // 原堆区空间后续空间够用，p指向不变
    // 原堆区空间后续空间不够用，p指向变化（realloc重新返回一块堆区空间）
    cout << "------------------------" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << p[i] << endl;
    }
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
    }
}

int main(void) {
    test_2();

    return EXIT_SUCCESS;
}