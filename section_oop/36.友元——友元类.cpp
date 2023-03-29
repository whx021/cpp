// 36、友元——友元类
// 类做友元
#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodGay {
public:
	GoodGay();

	void visit();	// 参观函数，访问Building中的属性

	Building* building;
};

class Building {
	// 声明类GoodGay为当前类Building的友元，
	// 类GoodGay中的成员函数可以访问Building中的私有成员
	friend class GoodGay;
public:
	Building();
public:
	string member_settingRoom;	// 客厅
private:
	string member_bedRoom;		// 卧室
};

// 类外写成员函数（构造函数）
Building::Building() {
	member_settingRoom = "客厅";
	member_bedRoom = "卧室";
} 

// 类GoodGay的构造函数
GoodGay::GoodGay() {
	// 在堆区创建一个Building的对象，调用了Building构造函数
	building = new Building;
}

// 参观函数，访问Building中的属性
void GoodGay::visit() {
	cout << "好基友的类正在访问：" << building->member_settingRoom << endl;
	cout << "好基友的类正在访问：" << building->member_bedRoom << endl;
}

void test_1(void) {
	// 实列化GoodGay时，调用GoodGay的无参构造函数，在堆区创建了Building类的对象
	GoodGay goodGay;
	goodGay.visit();
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}