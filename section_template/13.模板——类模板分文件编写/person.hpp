#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person {
public:
    T1 member_name;
    T2 member_age;

    Person(T1 name, T2 age);

    void showPerson(void) const;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) : member_name(name), member_age(age) {}

template<class T1, class T2>
void Person<T1, T2>::showPerson(void) const {
    cout << "name:" << this->member_name << endl;
    cout << "age:" << this->member_age << endl; 
}

#endif