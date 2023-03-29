// 63、继承——菱形继承问题以及解决方法
//
// 菱形继承：
//	两个派生类继承同一个基类
//	又有某一个类继承两个派生类
//	这种继承被称为菱形继承，或者钻石继承
// 
// 菱形继承问题：
//	子类继承了两份数据，导致资源浪费以及毫无意义
// 解决：
//	利用虚继承的技术 virtual关键字
//	在继承之前 加上关键字：virtual关键字	变为虚继承
// 
// 虚继承的底层原理
//	vbptr——虚基类指针
//	v——virtual
//	b——base
//	ptr——pointer
//	vbptr指向vbtable（虚基类表）
//	vbtable表中记录为虚基类的地址偏移量：可以找到类中唯一一份数据

#include <iostream>
using namespace std;

// 动物类
class Animal {
public:
	int member_age;
};

// 利用虚继承的：解决菱形继承的问题
//	在继承之前 加上关键字：virtual关键字	变为虚继承
//	Animal类成为其子类的	虚基类

// 羊类
class Sheep : virtual public Animal{};

// 驼类
class Tuo : virtual public Animal{};

// 羊驼类
class SheepTuo : public Sheep, public Tuo{};

void test_1(void) {
	SheepTuo st;

	st.Sheep::member_age = 18;
	st.Tuo::member_age = 28; 
	// 当菱形继承时，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::member_age = " << st.Sheep::member_age << endl;
	cout << "st.Tuo::member_age = " << st.Tuo::member_age << endl;
	// 这份数据只需要有一份，菱形继承导致数据有两份，资源浪费

	// 使用虚基类后的多家的一种访问方式
	cout << "st.member_age = " << st.member_age << endl; 
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}