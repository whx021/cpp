// 2、vector存放自定义数据类型

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age) : m_name(name), m_age(age){};

    string m_name;
    int m_age;
};

void printVector(const Person &p)
{
    cout << "name: " << p.m_name << "\tage: " << p.m_age << endl;
}

// void printVector(Person* p)
// {
//     cout << "name: " << p->m_name << "\tage: " << p->m_age << endl;
// }

// vector存放自定义类型数据
void test_1(void)
{
    vector<Person> v;

    Person p1("a", 18);
    Person p2("b", 19);
    Person p3("c", 20);
    Person p4("d", 21);
    Person p5("e", 22);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "name: " << (*it).m_name << "\tage: " << (*it).m_age << endl;
    }

    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "name: " << it->m_name << "\tage: " << it->m_age << endl;
    }

    for_each(v.begin(), v.end(), printVector);
}

// vector存放自定义数据类型数组
void test_2(void)
{
    vector<Person *> v;

    Person p1("a", 18);
    Person p2("b", 19);
    Person p3("c", 20);
    Person p4("d", 21);
    Person p5("e", 22);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "name: " << (*it)->m_name << "\tage: " << (*it)->m_age << endl;
    }
}

int main(void)
{
    test_2();

    return EXIT_SUCCESS;
}