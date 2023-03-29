// 56、继承——基本语法
//
// 继承的好处：减少重复的代码
// 语法：class 子类 : 继承方式 父类
// 
// 子类：也称为	派生类
// 父类：也成为	基类
// 
// 子类中的成员包含两大部分：
// 	1、继承父类的成员：表现其共性
// 	2、自己添加的成员：表现其个性

#include <iostream>
using namespace std;

// // 普通页面

// // Java页面
// class Java {
// public:
// 	void header(void) {
// 		cout << "公共头部" << endl;
// 	}
// 	void footer(void) {
// 		cout << "公共底部" << endl;
// 	}
// 	void left(void) {
// 		cout << "公共分类列表" << endl;
// 	}
// 	void content(void) {
// 		cout << "java学科视频" << endl;
// 	}
// };
// // Python页面
// class Python {
// public:
// 	void header(void) {
// 		cout << "公共头部" << endl;
// 	}
// 	void footer(void) {
// 		cout << "公共底部" << endl;
// 	}
// 	void left(void) {
// 		cout << "公共分类列表" << endl;
// 	}
// 	void content(void) {
// 		cout << "python学科视频" << endl;
// 	}
// };
// // C++页面
// class CPP {
// public:
// 	void header(void) {
// 		cout << "公共头部" << endl;
// 	}
// 	void footer(void) {
// 		cout << "公共底部" << endl;
// 	}
// 	void left(void) {
// 		cout << "公共分类列表" << endl;
// 	}
// 	void content(void) {
// 		cout << "C++学科视频" << endl;
// 	}
// };

// 继承实现页面

// 公共页面
class BasePage {
public:
	void header(void) {
		cout << "公共头部" << endl;
	}
	void footer(void) {
		cout << "公共底部" << endl;
	}
	void left(void) {
		cout << "公共分类列表" << endl;
	}
};

// Java页面
class Java : public BasePage {
public:
	void content(void) {
		cout << "Java学科视频" << endl;
	}
};

// Python页面
class Python : public BasePage {
public:
	void content(void) {
		cout << "Python学科视频" << endl;
	}
};

// C++页面
class CPP : public BasePage {
public:
	void content(void) {
		cout << "C++学科视频" << endl;
	}
};

void test_1(void) {
	cout << "java页面如下：" << endl;
	Java java;
	java.header();
	java.footer();
	java.left();
	java.content();
	cout << "-----------------" << endl;

	cout << "python页面如下：" << endl;
	Python python;
	python.header();
	python.footer();
	python.left();
	python.content();
	cout << "-----------------" << endl;

	cout << "C++页面如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "-----------------" << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}