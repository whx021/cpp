// 69、多态——虚析构和纯虚析构
//
// 问题：多态使用时，如果子类中有属性开辟在堆区，
// 那么父类指针在释放空间时无法调用到子类的析构函数，造成内存泄露
//
// 解决方式：将父类的析构函数改为虚析构函数或纯虚析构函数
//
// 虚析构和纯虚析构共性：
//	1、可以解决父类指针释放子类对象
//	2、都需要有具体的函数实现
//
// 虚析构和纯虚析构区别：
//	1、如果是纯虚析构，该类属于抽象类，无法实例化对象
//
// 虚析构语法：
//	virtual ~类名(){}
//
// 纯虚析构语法：
//	virtual ~类名() = 0;
// 纯虚析构函数需要代码实现
//	类名::~类名(){}
//
// 总结：
//	1、虚析构和纯虚析构就是用来解决父类指针释放子类对象
//	2、如果子类在堆区没有数据，可以不写为虚析构和纯虚析构
//	3、拥有纯虚析构函数的类也属于抽象类

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal类构造函数调用" << endl;
	}

	// 将父类的析构函数改为虚析构函数或纯虚析构函数，解决父类指针释放子类对象可能的内存泄漏
	// virtual ~Animal() {
	// 	cout << "Animal类析构函数调用" << endl;
	// }

	// 纯虚析构：也需要代码实现：父类也可能有数据开辟在堆区
	// 如果是纯虚析构，该类属于抽象类，无法实例化对象
	virtual ~Animal() = 0;

	virtual void function(void) = 0;
};

// 纯虚析构：也需要代码实现：父类也可能有数据开辟在堆区
Animal::~Animal() {
	cout << "Animal类纯析构函数调用" << endl;
}

class Cat : public Animal {
public:
	Cat(string name) {
		cout << "Cat类构造函数调用" << endl;
		member_name = new string(name);
	}

	~Cat() {
		cout << "Cat类析构函数调用" << endl;
		if (member_name != nullptr) {
			delete member_name;
			member_name = nullptr;
		}
	}

	virtual void function(void) {
		cout << *member_name << "小猫在说话" << endl;
	}

	string* member_name;
};

void test_1(void) {
	Animal* animal = new Cat("Tom");
	animal->function(); 
	// 问题：多态使用时，如果子类中有属性开辟在堆区，
	// 那么父类指针在释放空间时无法调用到子类的析构函数，造成内存泄露
	delete animal;
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}