// 重载 new operator && delete operator
#include <iostream>
// member operator new() & member delete() is static member function
// function default have static keyword 
// don't have default argument : this pointer

// operator new[] && operator delete[]

// 重载全局operator new()函数
// Parameter : size_t (unsigned long long), 
// Return : void*
static void* operator new(std::size_t size) {
    std::cout << "overloaded global operator new allocate : " << size << " Byte" << std::endl;
    void* ptr = malloc(size);
    std::cout << "the allocate memory address is : " << ptr << std::endl;
    return ptr;
}

// 重载全局operator delete()函数
// Parameter : void*
// Return : void
static void operator delete(void* ptr) {
    std::cout << "overloaded global operator delete call" << std::endl;
    if (ptr == nullptr) {   // 对空指针delete是安全的
        return;
    } 
    free(ptr);
}

class Person {
public:
    Person(int age, int num) : m_age(age), m_num(num) {
        std::cout << "Person object constructor call" << std::endl;
    }  
    ~Person() {
        std::cout << "Person object destructor call" << std::endl;
    }
    // note : 
    // member operator new() & member delete() is static member function
    // don't have default argument : this pointer

    // 重载member operator new()函数
    // Parameter : size_t (unsigned long long), 
    // Return : void*
    void* operator new(std::size_t size) {
        std::cout << "overloaded member operator new allocate : " << size << " Byte" << std::endl;
        void* ptr = malloc(size);
        std::cout << "the allocate memory address is : " << ptr << std::endl;
        return ptr;
    }

    // 重载member operator delete()函数
    // Parameter : void*
    // Return : void
    void operator delete(void* ptr) {
        std::cout << "overloaded member operator delete call" << std::endl;
        if (ptr == nullptr) {   // 对空指针delete是安全的
            return;
        } 
        free(ptr);
    }
    int m_age;
    int m_num;
};

void test_1(void) {
    int* p1 = new int(3);
    std::cout << "p1 = " << (void*)p1 << ", *p1 = " << *p1 << std::endl;
    delete p1;
}

void test_2(void) {
    Person* p = new Person(18, 1);
    std::cout << "num : " << p->m_num << "\tage : " << p->m_age << std::endl;
    delete p;
}

int main(void) {
    test_1();
    test_2();
    return EXIT_SUCCESS;
}