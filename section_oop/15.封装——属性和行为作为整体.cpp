// 15、类和对象——封装——属性和行为作为整体
// 封装意义1：
// 设计类的时候，属性和行为写在一起，表现事物
// 语法：class 类名{访问权限: 属性 / 行为};

#include <iostream>
using namespace std;

// 圆周率
const double PI = 3.14;

// 设计一个圆类，求圆的周长
// 圆的周长的公式： 2 * PI * 半径（圆的属性）

// class 代表设计一个类
class Circle {
// 访问权限
// 公共权限
public:
	// 属性
	// 半径
	int m_r;

	// 行为
	// 获取圆的周长
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

int main(void) {
	// 通过圆类 创建具体的圆（对象）
	// 实例化：通过一个类，创建一个对象的过程
	Circle c1;

	// 给圆对象的属性进行赋值
	c1.m_r = 10;

	// 使用圆对象的calculateZC()行为
	cout << "圆c1的周长为：" << c1.calculateZC() << endl;

	// system("pause");
	return 0;
}