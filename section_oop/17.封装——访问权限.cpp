// 17、封装——访问权限

// 访问权限
// 三种
// 公共权限	public		成员：类内可以访问	类外可以访问
// 保护权限	protected	成员：类内可以访问	类外不可以访问	
//						继承中：儿子可以访问父亲中的保护内容
// 私有权限	private		成员：类内可以访问	类外不可以访问				
//						继承中：儿子不可以访问父亲的私有内容
#include <iostream>
using namespace std;

class Person {
public:
	// 公共权限
	string member_name;	// 姓名

protected:
	// 保护权限
	string member_car;	// 汽车

private:
	// 私有权限
	int member_password;// 银行卡密码

public:
	void function() {
		member_name = "张三";
		member_car = "拖拉机";
		member_password = 123456;
	}
};

int main(void) {
	// 实例化具体对象
	Person p1;

	p1.member_name = "李四";
	// p1.member_car = "奔驰";		// 保护权限的内容，在类外访问不到
	// p1.member_password = 123;	// 私有权限的内容，在类外访问不到

	p1.function();

	// system("pause");
	return 0;
}