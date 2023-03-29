// 18、异常变量（对象）的生命周期
//
// 总结：
//  抛出自定义异常时，建议
//  抛出 匿名对象，同时catch使用 引用类型 接受
//  抛出方式：throw myException();
//  接受方式：catch (const myException& e)


#include <iostream>
using namespace std;

// 自定义异常类
class myException {
public:
    myException() {
        cout << "myException的构造函数" << endl;
    }
    myException(const myException& e) {
        cout << "myException的拷贝构造函数" << endl;
    }
    ~myException() {
        cout << "myException的析构函数" << endl;
    }
};

// 抛出异常的函数
void func(void) {
    // 抛出自定义异常类的匿名对象
    throw myException();
}

void test_1(void) {
    try {
        func();
    }
    // 抛出方式1：throw myException() 抛出一个myException类的匿名对象
    // 接受方式1： const myException e  // 以值的类型进行接受（调用拷贝构造函数）,内存资源浪费
    // 接受方式2： const myException& e // 以引用的类型进行接受（推荐）
    //
    // 抛出方式2：throw &myException()  // 抛出一个myException类的匿名对象的地址
    // 接受方式3：myException* e        // 接受myException类的指针
    // 存在问题：会提前释放异常对象
    // 匿名对象生命周期只在当前行，抛出myException类的匿名对象的地址的过程
    // 匿名对象构造函数->抛出匿名对象地址->匿名对象析构函数
    // 在catch中操作匿名对象的地址属于非法操作
    // （当前catch中匿名对象的生命周期结束，内存空间不属于程序维护）
    //
    // 抛出myException类的匿名对象在堆区创建空间的地址
    // 抛出方式3：throw new myException()    
    // 接受方式4：myException* e        // 接受myException类的指针
    // 存在问题：析构函数不会被调用，
    // 解决方法：在catch中手动释放 delete e
    // 和引用的效果一样，但需要手动释放抛出myException类的匿名对象在堆区创建空间
    catch(const myException& e) {
        cout << "自定义异常捕获" << endl;
    }
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}