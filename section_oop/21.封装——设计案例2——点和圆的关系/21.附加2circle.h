#pragma once	// 防止头文件重复包含
#include <iostream>
#include "21.附加1point.h"
using namespace std;

// 圆类
class Circle {
public:
	// 行为（成员函数）
	// 设置半径
	void setR(int r);
	// 获取半径
	int getR(void);
	// 设置圆心
	void setCenter(Point center);
	// 获取圆心
	Point getCenter(void);

private:
	// 属性（成员变量）
	int member_r;			// 半径
	// 在一个类中，可以让另一个类作为本类成员
	Point member_center;	// 圆心
};