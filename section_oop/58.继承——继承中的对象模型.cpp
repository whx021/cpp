// 58、继承——继承中的对象模型
//
// 问题：从父类继承过来的成员，那些属于子类对象中？
// 结论：父类中private的成员属性，被编译器隐藏，因此访问不到，但是确实被继承下去了
//		计算到子类的内存大小 
//
//
// 利用开发人员命令提示工具（Developer Command Prompt for VS 2022）查看对象模型
// 	1、跳转盘符
// 	2、跳转文件路径
// 	3、查看命名
// 
// 报告单个类的布局
// 	cl /d1 reportSingleClassLayout查看的类名 所属文件名
//

#include <iostream>
using namespace std;

class Base {
public:
	int member_A;
protected:
	int member_B;
private:
	// 父类中private的成员属性，被编译器隐藏，因此访问不到，但是确实被继承下去了
	// 计算到子类的内存大小
	int member_C;
};

class Son : public Base {
public: 
	int member_D; 
};

void test_1(void) {
	// 16byte
	// 父类中所有的非静态的成员变量都会被子类继承下去
	// 父类中private的成员属性，被编译器隐藏，因此访问不到，但是确实被继承下去了
	// 计算到子类的内存大小
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}