// 35、友元——全局函数做友元
//
// 在程序内：有一些私有属性，也想类外的特殊的函数或者类进行访问，就需要用到友元的技术
//
// 友元目的：让一个函数或者一个类访问另一个类中的私有成员
//
// 友元关键字：friend
//
// 友元的三种实现：
// 	1、全局函数做友元
// 	2、类做友元
// 	3、成员函数做友元

#include <iostream>
#include <string>
using namespace std;

// 建筑物类
class Building {
	// 声明全局函数goodGay为当前类Building的友元，可以访问Building中的私有成员
	friend void goodGay(Building* building);
public:
	Building() {
		member_sittingRoom = "客厅";
		member_bedRoom = "卧室";
	}
public:
	string member_sittingRoom;	// 客厅
private:
	string member_bedRoom;		// 卧室
};

// 全局函数做友元
void goodGay(Building* building) {
	// member_sittingRoom为类Building的公有属性，类外可以直接访问
	cout << "好基友全局函数正在访问：" << building->member_sittingRoom << endl;

	// member_bedRoom为类Building的私有属性，类外不可以直接访问，
	// 需将该函数设为类Building的友元，才可以访问
	cout << "好基友全局函数正在访问：" << building->member_bedRoom << endl;
}

void test_1(void) {
	Building building;
	goodGay(&building);
}

int main(void) {
	test_1();
	// system("pause");
	return 0;
}