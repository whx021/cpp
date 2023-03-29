// 实现简单的内存池
// overloaded operator new && overloaded operator delete

// 1. 预先分配一大块内存空间
// 2. 提升分配归还效率(减少系统new&delete operator call)
// 3. 减小堆区内存碎片(heap area)
#include <iostream>
#include <cstring>
#include <exception>

// FIXME : segmentation fault

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

    // overloaded member operator new() function
    // Parameter : size_t (unsigned long long), 
    // Return : void*
    // allocate memory from memory pool
    static void* operator new(std::size_t size) {
        if (m_pool[0] == 0) {   // 判断第一个位置是否空闲
            std::cout << "allocate a piece of memory pool address is : " << (void*)(m_pool + 1) << std::endl;
            m_pool[0] = 1;      // 标记第一个位置为以分配
            return m_pool + 1;  // 返回第一个用于存放对象的地址
        }
        if (m_pool[9] == 0) {   // 判断第一个位置是否空闲
            std::cout << "allocate a piece of memory pool address is : " << (void*)(m_pool + 10) << std::endl;
            m_pool[9] = 1;      // 标记第一个位置为以分配
            return m_pool + 10; // 返回第一个用于存放对象的地址
        }

        // 如果memory pool以分配完, 根据业务需求, 解决方法 : 
        // 1. 直接向系统申请内存
        // 2. 扩展memory pool
        // 3. 放回空地址
        void* ptr = malloc(size);
        std::cout << "allocate system memory address is : " << ptr << std::endl;
        return ptr;
    }

    // overloaded member operator delete() function
    // Parameter : void*
    // Return : void
    
    static void operator delete(void* ptr) {
        // 如果传入指针地址为空
        if (ptr == nullptr) {
            return;
        }
        // 如果传入指针地址为memory pool第一个位置
        if (ptr == m_pool + 1) {
            std::cout << "free up first piece memory of memory pool address is : " << (void*)(m_pool + 1) << std::endl;
            m_pool[0] = 0;  // 标记第一个位置为空闲
            return;
        }
        // 如果传入指针地址为memory pool第二个位置
        if (ptr == m_pool + 10) {
            std::cout << "free up second piece memory of memory pool address is : " << (void*)(m_pool + 10) << std::endl;
            m_pool[9] = 0;  // 标记第二个位置为空闲
            return;    
        }
        // 如果传入指针地址不属于memory pool, 归还系统
        std::cout << "free up system memory address is : " << ptr << std::endl;
        free(ptr); 
    }

    // initialize memory pool function
    static bool initMemoryPool(void) {
        m_pool = (char*)malloc(18);
        if (m_pool == nullptr) {
            return false;
        }
        memset(m_pool, 0, 18);
        std::cout << "the memory pool allocate start address is " << (void*)m_pool << std::endl;
        return true;
    }

    // free up memory pool function
    static void freeUpMemoryPool(void) {
        if (m_pool == nullptr) {
            return;
        }
        free(m_pool);
        std::cout << "free up memory pool" << std::endl;
    }

    int m_age;
    int m_num;
    // operator new && operator delete is default static member function 
    static char* m_pool;   // memory pool start address
};
char* Person::m_pool = nullptr; // static member out-of-class initialization


void test_1(void) {
    // initialize class memory pool
    if (Person::initMemoryPool() == false) {
        std::cout << "Failed to initialize memory pool" << std::endl;
        throw std::bad_alloc();
    }

    Person* p = new Person(18, 1);
    std::cout << "num : " << p->m_num << "\tage : " << p->m_age << std::endl;
    delete p;
    
    // free up memory pool
    Person::freeUpMemoryPool();
}

void test_2(void) {
    // initialize class memory pool
    if (Person::initMemoryPool() == false) {
        std::cout << "Failed to initialize memory pool" << std::endl;
        throw std::bad_alloc();
    }
    Person* p1 = new Person(18, 1);
    std::cout << "num : " << p1->m_num << "\tage : " << p1->m_age << std::endl;


    Person* p2 = new Person(19, 2);
    std::cout << "num : " << p2->m_num << "\tage : " << p2->m_age << std::endl;


    Person* p3 = new Person(20, 3);
    std::cout << "num : " << p3->m_num << "\tage : " << p3->m_age << std::endl;
    delete p1;
    

    Person* p4 = new Person(21, 4);
    std::cout << "num : " << p4->m_num << "\tage : " << p4->m_age << std::endl;    
    delete p2;
    delete p3;
    delete p4;

    // free up memory pool
    Person::freeUpMemoryPool();
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}