// 17、异常基本语法&栈解旋&异常接口说明
//
// 异常处理就是处理程序中的错误
// 所谓错误，就是在程序运行的过程中发生的一些异常事件
// （例如：除0溢出，数组下标越界，所要读取的文件不存在，空指针，内存不足等等）
//
// C处理异常的方法：
//  1、使用整形的返回值标识错误
//  2、使用errno宏（可以简单的理解为一个全局整形变量）记录错误
//
// C++处理异常的方法：调用跳级
// 如果程序中出现异常，必须有地方处理，
// 如果没有地方处理捕获异常，程序就会中断（C++内置中断函数terminate()）
//
// 栈解旋：
// 异常被抛出后，从进入 try 块起，到异常被抛掷前，
// 这期间在栈上的构造的所有对象，都会被自动析构。
// 析构的顺序与构造的顺序相反（栈区特点：LIFO）。
// 这一过程称为栈的解旋(unwinding)。
//
// 意义：对于未执行结束但出现异常的函数，释放其在栈区的空间（函数局部变量、等栈帧）
//
// 存在问题：这个区间在堆区创建的数据没有被释放
// 解决方法：使用智能指针指向这个区间内在堆区创建的数据

#include <iostream>
#include <string>
#include <memory>   // 智能指针类头文件
using namespace std;

// 异常也可以是自定义的类
class myException {
public:
    void printException(void) const {
        cout << "自定义异常" << endl;
    }
};

class Person {
public:
    Person() {
        cout << "Person构造函数调用" << endl;
    }
    ~Person() {
        cout << "Person析构函数调用" << endl;
    }
};

// 处理异常
int myDivision(const int& a,const int& b) {
    if (b == 0) {
        // C：返回值只有一个，无法区分，可能出现二义性
        // 且没有同一标志异常的标准
        // return -1;

        // C++处理异常
        // 如果抛出的异常没有被捕获，则程序中断
        // 例如下：抛出一个double型的异常，catch使用int型捕获，则无法捕获
        // throw -1;   // 抛出一个int型异常
        // throw 3.14; // 抛出一个double型异常
        // throw 'a';  // 抛出一个char型异常

        // 栈解旋：
        // 异常被抛出后，从进入 try 块起，到异常被抛掷前，
        // 这期间在栈上的构造的所有对象，都会被自动析构。
        // 析构的顺序与构造的顺序相反（栈区特点：LIFO）。
        // 这一过程称为栈的解旋(unwinding)。
        //
        // 意义：对于未执行结束但出现异常的函数，释放其在栈区的空间（函数局部变量）
        //
        // 存在问题：这个区间在堆区创建的数据没有被释放

        Person p1;
        Person p2;
        
        // 对于在堆区创建的数据，类对象中维护有堆区数据，没有调用析构函数，没有被释放，
        // new Person;
        // 解决方法：使用智能指针类模板auto_ptr维护堆区数据，
        // 当auto_ptr在栈区被释放时，同时调用维护对象的析构函数
        // 使用智能指针，需要包含头文件<memory>
        // auto_ptr（C++98标准）已被C++11弃用
        // 可以使用shared_ptr、unique_ptr智能指针类模板
        unique_ptr<Person> p3(new Person);

        throw myException(); // 抛出一个自定义异常（自定义异常类的匿名对象）
    }
    return (a / b);
}

void test_1(void) {
    int a = 10;
    int b = 0;

    // C++处理异常：在可能出现异常的地方，写入try代码块中
    try {
        int result = myDivision(a, b);
    }
    // 捕获int型异常
    catch (int) {
        cout << "int型异常捕获" << endl;
    }
    // 捕获double型异常
    catch (double) {
        // 最近的调用函数优先捕获异常
        // 如果捕获到的异常，在本级函数不想处理，
        // 可以使用throw关键字，继续向上级调用函数抛出异常
        throw;
        cout << "double型异常捕获" << endl;
    }
    catch (myException e) {
        e.printException();
    }
    // 其他类型的异常捕获
    catch (...) {
        cout << "其他类型异常捕获" << endl;
    }

    // // C处理异常
    // if (result == -1) {
    //     cout << "程序出现异常" << endl;
    // }
}


// 异常的接口声明：警告：动态异常规范在 C++11 中已弃用 [-已弃用]
// 函数返回值 函数名(参数列表) throw(允许抛出异常的类型名)
//                         throw()   // 不允许抛出任何异常
void func(void) throw(int, double) { // 只允许抛出int，double型异常   
    // 在抛出"double"实例后终止调用
    throw 3.14;
    // throw 10;
}

void test_2(void) {
    try {
        func();
    }
    catch (int) {
        cout << "int类型异常捕获" << endl;
    }
    catch (double) {
        cout << "double类型异常捕获" << endl;
    }
    catch (...) {
        cout << "other类型异常捕获" << endl;
    }
}


int main(void) {
    // 最近的调用函数优先捕获异常
    try {
        test_2();
    }
    catch(double) {
        cout << "在main函数中，double型异常捕获" << endl;
    }

    // 如果程序中没有任何地方去处理异常，
    // 系统会调用terminate()函数，使程序中段 

    return EXIT_SUCCESS;
}