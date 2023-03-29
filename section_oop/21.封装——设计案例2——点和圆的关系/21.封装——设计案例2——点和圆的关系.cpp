// 21、封装——设计案例2——点和圆的关系

// 1、在一个类中，可以让另一个类作为本类成员（类间的复合关系）
// 2、把一个类的声明放入.h文件中，类的行为定义放入.cpp文件中
// 3、成员函数定义放入.cpp文件中，默认全局作用域，成员函数作用域仅在类内，
// 所以需要指明成员函数的作用域，使用"类名::"指明该函数的作用域
// 4、#pragma once	// 防止头文件重复包含

#include <iostream>
#include "21.附加1point.h"
#include "21.附加2circle.h"
using namespace std;

// // 点类
// class Point {	
// public:
// 	// 行为（成员函数）
	
// 	// 设置x坐标
// 	void setX(int x) {
// 		member_x = x;
// 	}
// 	// 获取x坐标
// 	int getX(void) {
// 		return member_x;
// 	}
// 	// 设置y坐标
// 	void setY(int y) {
// 		member_y = y;
// 	}
// 	// 获取y坐标
// 	int getY(void) {
// 		return member_y;
// 	}
// private:
// 	// 属性（成员变量）
// 	int member_x;	// x坐标
// 	int member_y;	// y坐标
// };

// // 圆类
// class Circle {
// public:
// 	// 行为（成员函数）
// 	// 设置半径
// 	void setR(int r) {
// 		member_r = r;
// 	}
// 	// 获取半径
// 	int getR(void) {
// 		return member_r;
// 	}
// 	// 设置圆心
// 	void setCenter(Point center) {
// 		member_center = center;
// 	}
// 	// 获取圆心
// 	Point getCenter(void) {
// 		return member_center;
// 	}
// private:
// 	// 属性（成员变量）
// 	int member_r;			// 半径
// 	// 在一个类中，可以让另一个类作为本类成员（复合关系）
// 	Point member_center;	// 圆心
// };


// 判断点和圆的关系
void isInCircle(Circle& c,Point& p) {
	// 计算点到圆心的距离的平方
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	// 计算圆半径的平方
	int rDistance = c.getR() * c.getR();

	// 判断点与圆的位置关系
	if (distance == rDistance) {
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}


int main(void) {
	// 创建圆
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	// 创建点
	Point p;
	p.setX(10);
	p.setY(9);

	// 判断关系
	isInCircle(c, p);

	// system("pause");
	return 0;
}