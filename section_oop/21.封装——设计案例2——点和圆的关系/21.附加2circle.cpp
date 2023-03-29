#include "21.附加2circle.h"

// circle21行为（成员函数）
// 设置半径
void Circle::setR(int r) {
	member_r = r;
}
// 获取半径
int Circle::getR(void) {
	return member_r;
}
// 设置圆心
void Circle::setCenter(Point center) {
	member_center = center;
}
//获取圆心
Point Circle::getCenter(void) {
	return member_center;
}