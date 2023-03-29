// 37、友元——成员函数做友元
#include <iostream>
#include <string>
using namespace std;

// 声明Building类
class Building;

class GoodGay {
public:
	GoodGay();

	void visit1();	// 让visit函数可以访问Building中的私有内容
	void visit2();	// 让visit函数不可以访问Building中的私有内容

	Building* building;
};

class Building {
	// 声明类goodGay中的visit1成员函数为当前类Building的友元，
	// 可以访问Building中的私有成员
	friend void GoodGay::visit1();
public:
	Building();
public:
	string member_settingRoom;	// 客厅
private:
	string member_bedRoom;		// 卧室
};

// 内外实现定义成员函数
Building::Building() {
	member_settingRoom = "客厅";
	member_bedRoom = "卧室";
}

GoodGay::GoodGay() {
	// 在堆区创建了一个Building类的对象，调用了Building类的构造函数
	building = new Building;
}

// 类GoodGay的visit1()成员函数是类Building的友元成员函数
// 可以直接访问类Building的私有属性member_bedRoom
void GoodGay::visit1() {
	cout << "函数visit1正在访问：" << building->member_settingRoom << endl;
	cout << "函数visit1正在访问：" << building->member_bedRoom << endl;
}

// 类GoodGay的visit2()成员函数不是类Building的友元成员函数
// 不可以直接访问类Building的私有属性member_bedRoom
void GoodGay::visit2() {
	cout << "函数visit2正在访问：" << building->member_settingRoom << endl;
	// cout << "函数visit2 正在访问：" << building->member_bedRoom << endl;
}

void test_1(void) {
	GoodGay goodGay;
	goodGay.visit1();
	goodGay.visit2();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}