// 28、对象特性——类对象作为类成员（类间的复合关系）
//
// C++类中的成员可以是另一个类的对象，我们称该成员为：对象成员
//
// 注意1：当其他类对象作为本类成员，构造时先构造类对象，在构造自身
// 注意2：析构的顺序与构造相反，栈区的内存释放顺序（LIFO）

#include <iostream>
using namespace std;
#include <string>

// 手机类
class Phone {
public:
	Phone(string Phone_name) {
		cout << "Phone构造函数调用" << endl;
		member_Phone_name = Phone_name;
	}
	~Phone() {
		cout << "Phone析构函数调用" << endl;
	}

	string member_Phone_name;	// 手机名 	
};


// 人类
class Person {
public:
	// 类Person中属性定义类Phone，
	// Phone member_phone;
	// 调用Person有参构造函数时，string类型Phone_name传入Person的构造函数后
	// 又通过Person的构造函数传入Phone的构造函数
	// 
	// member_Phone(Phone_name)语句	调用member_Phone对象的有参构造函数
	//
	// 等价于	Phone member_Phone = Phone_name		隐式转化法（有参构造）
	// 等价于	Phone member_Phone = Phone member_Phone(Phone_name)
	// 初始化列表构造函数
	Person(string name, string Phone_name): member_name(name), member_Phone(Phone_name) {
		cout << "Person构造函数调用" << endl;
	}
	~Person() {
		cout << "Person析构函数调用" << endl;
	}

	string member_name;		// 姓名
	Phone member_Phone;		// 手机
};

void test_1(void) {
	Person p("张三", "苹果");
	cout << p.member_name << "拿着" << p.member_Phone.member_Phone_name << "手机" << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}