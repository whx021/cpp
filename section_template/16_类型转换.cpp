// 16、类型转换——静态类型转换(static_cast)
//
// 尽量少使用类型转换
// 常见使用类型转换 string -> const char *
//
// C++风格的强制类型转化：比C更清晰
//
// 1静态类型转换（static_cast）：
// 用于类层次中 基类（父类）和 派生类（子类）之间指针或引用的转换
//  1、向上类型转换：派生类（子类）指针或引用的转换 基类（父类）安全
//  2、向下类型转换：基类（父类）指针或引用的转换 派生类（子类）不安全
//  原因：没有动态类型检测，类的范围减小（不安全），类的范围扩大（安全）
//  父类指针可指向子类对象（安全），子类指针无法指向父类对象（不安全）
// 类似内存空间小的数据类型转换为内存空间大的数据类型，安全
// 内存空间大的数据类型转换为内存空间小的数据类型，不安全，可能会溢出
//
// 2.动态类型转换（dynamic_cast）：更加严格，安全才能转换
//
// 3.常量转换（const_cast）
// 修改类型的const属性，只能对指针或引用的变量进行const_cast转换
// 只改变指针或引用的const属性，不改变指向
//
// 4.重现解释转换（reinterpret_cast）
// 最不安全的一种转换机制，最有可能出现问题
// 将一种数据类型转换为另一种数据类型

#include <iostream>
using namespace std;

// 1、静态类型转换（static_cast）
void test_1(void) {
    // 对于内置数据类型的转换（使用模板的技术）
    char a = 'a';
    // 函数模板static_cast<目标转换类型>(转换对象);
    double d = static_cast<double>(a);
    cout << "d = " << d << endl;
}

class Base {virtual void func(void);};
class Son : public Base {virtual void func(void);};
class Other {};

void test_2(void) {
    // 对于类层次数据类型的转换
    Base* base_1 = nullptr;
    Son* son = static_cast<Son*>(base_1);   //父转子 不安全

    Base* base_2 = static_cast<Base*>(son); //子转父 安全

    // 没有层次关系的对象，指针或引用转换无效
    // Other* other = static_cast<Other*>(base_2); //无效转换
}

// 2、动态类型转换（dynamic_cast）：更加严格，安全才能转换
void test_3(void) {
    char a = 'a';
    // 内置数据类型无法转换
    // double d = dynamic_cast<double>(a);
}

void test_4(void) {
    Base* base_1 = nullptr;
    // 父转子 不安全 转换不成功
    // Son* son_1 = dynamic_cast<Son*>(base_1);    // 转换失败

    Son* son_2 = nullptr;
    // 子转父 安全 转换成功
    Base* base_2 = dynamic_cast<Base*>(son_2);

    // 没有层次关系的对象，指针或引用转换无效
    // Other* other = dynamic_cast<Other*>(base_2);

    // 如果发生多态, 转换总是安全的, 证明该成员函数父类和子类都存在
    Base* base_3 = new Son;                     // 子转父
    Son* son_3 = dynamic_cast<Son*>(base_3);    // 父转子
}

// 3、常量转换（const_cast）
// 修改类型的const属性，只能对指针或引用的变量进行const_cast转换
// 只改变指针或引用的const属性，不改变指向
void test_5(void) {
    // 只能对指针或引用的变量进行const_cast转换，修改类型的const属性
    const int* p = nullptr;
    int* pp = const_cast<int*>(p);
    const int* ppp = const_cast<const int*>(pp);

    int a = 10;
    int& b = a;
    const int& b_reference = const_cast<const int&>(b);

    // 只能对指针或引用的变量进行const_cast转换
    // const变量存放在符号表中
    // 普通局部变量存放在栈上
    // const int a = 10;
    // int b = const_cast<int>(a);   // 转换无效
}

// 4、重现解释转换（reinterpret_cast）
// 最不安全的一种转换机制，最有可能出现问题
// 将一种数据类型转换为另一种数据类型
void test_6(void) {
    // 最不安全，最灵活，不退推荐
    int a = 10;
    int* p = reinterpret_cast<int*>(a);

    Base* base = nullptr;
    Other* other = reinterpret_cast<Other*>(base);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}