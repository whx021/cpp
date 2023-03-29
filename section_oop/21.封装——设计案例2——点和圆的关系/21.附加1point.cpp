#include "21.附加1point.h"

// Point行为（成员函数）
// 使用"类名::"指明该函数的作用域
// 设置x坐标
void Point::setX(int x) {
	member_x = x;	
}
// 获取x坐标
int Point::getX(void) {
	return member_x;
}
// 设置y坐标
void Point::setY(int y) {
	member_y = y;
}
// 获取y坐标
int Point::getY(void) {
	return member_y;
}