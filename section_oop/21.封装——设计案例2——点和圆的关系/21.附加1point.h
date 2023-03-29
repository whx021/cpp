#pragma once	// 防止头文件重复包含
#include <iostream>
using namespace std;

// 点类
class Point {
public:
	// 行为（成员函数）
	// 设置x坐标
	void setX(int x);
	// 获取x坐标
	int getX(void);
	// 设置y坐标
	void setY(int y);
	// 获取y坐标
	int getY(void);

private:
	// 属性（成员变量）
	int member_x;	// x坐标
	int member_y;	// y坐标
};