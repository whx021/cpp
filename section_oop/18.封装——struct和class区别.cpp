// 18、封装——struct和class区别
// C++中，struct和class唯一区别：默认的访问权限不同
// 区别：
// struct默认权限为public公共
// class默认权限为private私有

#include <iostream>
using namespace std;

class C_1 {
	int member_A;	// 默认权限：public私有
};

struct C_2 {
	int member_A;	// 默认权限：private公共
};

int main(void) {
	C_1 c1;
	// c1.member_A = 100;	// class中默认权限是：私有权限类外不可访问
	C_2 c2;
	c2.member_A = 100;		// struct中默认权限是：公共权限可访问

	// system("pause");
	return 0;
}