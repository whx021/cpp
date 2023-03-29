#include <iostream>
#include <string>
using namespace std;
#include "myArray.hpp"

void printArray(const MyArray<int> &arr) {
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}

// 测试内置数据类型
void test_1(void) {
    MyArray<int> array_1(5);

    for (int i = 0; i < array_1.GetCapacity(); ++i) {
        array_1.Insert_tail(i);
    }

    printArray(array_1);
    cout << "Capacity of array_1 = " << array_1.GetCapacity() << endl;
    cout << "Size of array_1 = " << array_1.GetSize() << endl;

    MyArray<int> array_2(array_1);
    cout << "Before delete" << endl;
    cout << "Capacity of array_2 = " << array_2.GetCapacity() << endl;
    cout << "Size of array_2 = " << array_2.GetSize() << endl;
    printArray(array_2);

    array_2.Delete_tail();
    cout << "After delete" << endl;
    cout << "Capacity of array_2 = " << array_2.GetCapacity() << endl;
    cout << "Size of array_2 = " << array_2.GetSize() << endl;
    printArray(array_2);

    // MyArray<int> array_3(100);
    // array_3 = array_1;
}

// 测试自定义数据类型
class Person {
public:
    Person(){};
    Person(string name, int age) : m_name(name), m_age(age) {}

    string m_name;
    int m_age;
};

void printArray(const MyArray<Person>& arr) {
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << "name: " << arr[i].m_name << '\t' << "age: " << arr[i].m_age << endl;
    }
}

void test_2(void) {   
    MyArray<Person> arr(10);

    Person p1("Tom", 19);
    Person p2("Jerry", 19);
    Person p3("Harry", 19);
    Person p4("Jack", 19);
    Person p5("Mike", 19);

    arr.Insert_tail(p1);
    arr.Insert_tail(p2);
    arr.Insert_tail(p3);
    arr.Insert_tail(p4);
    arr.Insert_tail(p5);
    
    printArray(arr);

    cout << "Capacity of arr is " << arr.GetCapacity() << endl;
    cout << "Size of arr is " << arr.GetSize() << endl;
}

int main(void) {
    // test_1();
    test_2();
    return EXIT_SUCCESS;
}