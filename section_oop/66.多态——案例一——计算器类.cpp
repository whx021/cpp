// 66、多态——案例一——计算器类

// 案列描述：
//	分别利用普通写法和多态写法，设计实现两个操作数运算的计算器类

// 多态的优点：
//	1、代码组织结构清晰
//	2、可读性强
//	3、利用前期和后期的拓展以及维护

// 总结：C++中提倡使用多态设计程序架构


#include <iostream>
#include <string>
using namespace std;

// 普通写法
class Calculator {
public:
	int getResult(string oper) {
		if (oper ==  "+") {
			return member_num_1 + member_num_2;
		}
		else if (oper == "-") {
			return member_num_1 - member_num_2;
		}
		else if (oper == "*") {
			return member_num_1 * member_num_2;
		}
		// 如果想要扩展新的功能，需要修改源码
		// 在真正的开发中， 提倡开闭原则
		// 开闭原则：对扩展进行开放，对修改进行关闭
	}
	int member_num_1;
	int member_num_2;
};

void test_1(void) {
	Calculator c;
	c.member_num_1 = 10;
	c.member_num_2 = 10;

	cout << c.member_num_1 << " + " << c.member_num_2 << " = " << c.getResult("+") << endl;
	cout << c.member_num_1 << " - " << c.member_num_2 << " = " << c.getResult("-") << endl;
	cout << c.member_num_1 << " * " << c.member_num_2 << " = " << c.getResult("*") << endl;
}

// 利用多态实现计算器

// 实现计算器抽象类
class AbstractCalculator {
public:
	virtual int getResult(void) {
		return 0;
	}

	int member_num_1;
	int member_num_2;
};

// 实现加法计算器类
class addCalculator : public AbstractCalculator {
public:
	virtual int getResult(void) {
		return member_num_1 + member_num_2;
	}
};

// 实现减法计算器类
class subCalculator : public AbstractCalculator {
public:
	virtual int getResult(void) {
		return member_num_1 - member_num_2;
	}
};

// 实现乘法计算器类
class mulCalculator : public AbstractCalculator {
public:
	virtual int getResult(void) {
		return member_num_1 * member_num_2;
	}
};

void test_2(void) {
	AbstractCalculator* c = new addCalculator;
	c->member_num_1 = 100;
	c->member_num_2 = 100;
	cout << c->member_num_1 << " + " << c->member_num_2 << " = " << c->getResult() << endl;
	delete c;

	c = new subCalculator;
	c->member_num_1 = 100;
	c->member_num_2 = 100;
	cout << c->member_num_1 << " - " << c->member_num_2 << " = " << c->getResult() << endl;
	delete c;

	c = new mulCalculator;
	c->member_num_1 = 100;
	c->member_num_2 = 100;
	cout << c->member_num_1 << " * " << c->member_num_2 << " = " << c->getResult() << endl;
	delete c;
}

int main(void) {
	// test_1();
	test_2();
	// system("pause");
	return EXIT_SUCCESS;
}