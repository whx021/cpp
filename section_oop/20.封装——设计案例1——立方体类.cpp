// 封装——设计案例1——立方体类

#include <iostream>
using namespace std;

// 立方体设计
// 1、创建立方体类
// 2、设计属性
// 3、设计行为：获取立方体面积和体积
// 4、分别利用全局函数和成员函数判断两个立方体是否相等

class Cube {
public:
	// 行为：提供接口

	// 设置获取长宽高
	// 设置长
	void setLength(int length) {
		member_length = length;
	}
	// 获取长
	int getLength() {
		return member_length;
	}
	// 设置宽
	void setWidth(int width) {
		member_width = width;
	}
	// 获取宽
	int getWidth() {
		return member_width;
	}
	// 设置高
	void setHeight(int height) {
		member_height = height;
	}
	// 获取高
	int getHeight() {
		return member_height;
	}
	// 获取立方体面积
	int calculateS() {
		return (member_length * member_width + member_length * member_height + member_width * member_height) * 2;
	}
	// 获取立方体体积
	int calculateV() {
		return member_length * member_width * member_height;
	}
	// 利用成员函数判断两个立方体是否相等
	bool isSameByClass(Cube& c) {
		if (member_length == c.getLength() && member_width == c.getWidth() && member_height == c.getHeight()) {
			return true;
		}
		return false;
	}

private:
	// 属性
	int member_length;	// 长
	int member_width;	// 宽
	int member_height;	// 高
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2) {
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight()) {
		return true;
	}
	return false; 
}

int main(void) {
	// 实例化立方体对象c1
	Cube c1;
	c1.setLength(10);
	c1.setWidth(10);
	c1.setHeight(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;

	// 实例化立方体对象c2
	Cube c2;
	c2.setLength(10);
	c2.setWidth(10);
	c2.setHeight(10);

	// 利用全局函数判断
	bool result = isSame(c1, c2);
	if (result) {
		cout << "全局函数判断：c1和c2相等" << endl;
	}
	else {
		cout << "全局函数判断：c1和c2不相等" << endl;
	}

	// 利用成员函数判断
	result = c1.isSameByClass(c2);
	if (result) {
		cout << "成员函数判断：c1和c2相等" << endl;
	}
	else {
		cout << "成员函数判断：c1和c2不相等" << endl;
	}

	// 三目运算符
	cout << (result ? "c1和c2相等" : "c1和c2不相等") << endl;

	// system("pause");
	return 0;
}