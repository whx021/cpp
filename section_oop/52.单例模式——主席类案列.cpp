// 52、单例模式——主席类案列
// 单例模式：通过一个类只能创建唯一一个对象，使用时共享

#include <iostream>
using namespace std;

// 主席
class Chairman {
public:
	// 3、将唯一的指针私有化之后，提供公共的接口，变为只读状态
	static Chairman* getInstanceChairman(void) {
		return singleMan;
	}
private:
	// 1、将默认构造函数私有化，不能产生多个对象
	Chairman() {
		cout << "Chairman构造函数调用" << endl;
	}
	
	// 4、将拷贝构造函数私有化，防止对单例类的对象进行拷贝构造
	Chairman(const Chairman&) {}
private:
	// 将对象设为私有权限，防止被随意更改（解决：设置公共接口访问）

	// 2、只要拿到一个对象的指针即可，这个指针可以指向唯一的对象
	// 写为静态原因：可共享
	// 静态成员变量类内声明
	static Chairman* singleMan;
};

// 静态成员变量内外初始化
// 静态成员变量使用指针类型：初始化指向在堆区创建单例类的对象
// 防止在栈区创建的唯一单例类对象被释放，堆区对象仅在程序运行结束时被释放
Chairman* Chairman::singleMan = new Chairman;	
// 程序启动前：静态成员变量在编译阶段开始创建在静态区，并调用Chairman的构造函数在堆区创建对象

void test(void) {
	// 默认构造函数已经私有化，无法实例化对象
	// Chairman c1;
	// Chairman c2;
	// Chairman* c3 = new Chairman;
	
	// 不可以通过实例化的对象访问singleMan，现在已经无法实列化对象
	// 只能通过类名访问对象
	// Chairman* c1 = Chairman::singleMan;
	// Chairman* c2 = Chairman::singleMan;
	// Chairman::singleMan = nullptr;

	// 只能通过类名提供的接口访问对象
	Chairman* c1 = Chairman::getInstanceChairman();
	Chairman* c2 = Chairman::getInstanceChairman();
	// Chairman* c3 = new Chairman(*c1);	// 单例模式不允许拷贝构造,构造新对象

	if (c1 == c2) {
		cout << "c1 == c2" << endl;
	}
	else {
		cout << "c1 != c2" << endl;
	}

	// // 私有化拷贝构造函数后，无法通过拷贝构造创建新单例
	// Chairman* c3 = new Chairman(*c1);
	// if (c1 == c3) {
	// 	cout << "c1 == c3" << endl;
	// }
	// else {
	// 	cout << "c1 != c3" << endl;
	// }
}

int main(void) {
	// 静态成员变量、静态成员函数在编译阶段已经分配内存，
	// 程序运行之前，调用了Chairman的构造函数
	cout << "main函数的调用" << endl;
	test();
	// system("pause");
	return EXIT_SUCCESS;
}