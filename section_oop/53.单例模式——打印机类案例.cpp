// 53、单例模式——打印机类案例
#include <iostream>
#include <string>
using namespace std;

// 打印机类
class Printer {
public:
	// 提供访问单例对象的接口
	static Printer* getInstance(void) {
		return singlePrinter;
	}

	// 提供使用单例对象的接口
	void printTXT(string text) {
		cout << text << endl;
		++member_count;
	}

	int member_count = 0;	// 打印机打印次数

private:
	// 私有权限的默认构造函数
	Printer() {}

	// 私有权限的拷贝构造函数
	Printer(const Printer&) {}

	// 静态成员变量类内声明
	static Printer* singlePrinter;
};

// 静态成员变量内外初始化
Printer* Printer::singlePrinter = new Printer;

void test_1(void) {
	Printer* p1 = Printer::getInstance();
	p1->printTXT("入职证明");
	p1->printTXT("离职证明");
	p1->printTXT("调薪申请");
	p1->printTXT("调休申请");
	cout << "打印机使用的次数为：" << p1->member_count << endl;

	Printer* p2 = Printer::getInstance();
	p2->printTXT("旅游申请");
	cout << "打印机使用的次数为：" << p2->member_count << endl;
}

int main(void) {
	test_1();
	return EXIT_SUCCESS;
}