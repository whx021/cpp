// 68、多态——案例二——制作饮品

#include <iostream>
using namespace std;

// 制作饮品抽象类
class AbstractDrinking {
public:
	// 煮水
	virtual void Boil() = 0;
	// 冲泡
	virtual void Brew() = 0;
	// 倒入杯中
	virtual void PourCup() = 0;
	// 加入辅料
	virtual void AddSomething() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourCup();
		AddSomething();
	}
};

// 制作咖啡类
class Coffee : public AbstractDrinking {
	// 煮水
	virtual void Boil() {
		cout << "coffee：煮水" << endl;
	}
	// 冲泡
	virtual void Brew() {
		cout << "coffee：冲泡" << endl;
	}
	// 倒入杯中
	virtual void PourCup() {
		cout << "coffee：倒入杯中" << endl;
	}
	// 加入辅料
	virtual void AddSomething() {
		cout << "coffee：加入辅料" << endl;
	}
};

// 制作茶类
class Tea : public AbstractDrinking {
	// 煮水
	virtual void Boil() {
		cout << "tea：煮水" << endl;
	}
	// 冲泡
	virtual void Brew() {
		cout << "tea：冲泡" << endl;
	}
	// 倒入杯中
	virtual void PourCup() {
		cout << "tea：倒入杯中" << endl;
	}
	// 加入辅料
	virtual void AddSomething() {
		cout << "tea：加入辅料" << endl;
	}
};

// AbstractDrinking* drink = new Tea
void doDrinking(AbstractDrinking* drink) {
	drink->makeDrink();
	// 防止堆区内存泄漏
	delete drink;
}

void test(void) {
	doDrinking(new Tea);

	cout << "------------------------" << endl;

	doDrinking(new Coffee);
}

int main(void) {
	test();
	// system("pause");
	return EXIT_SUCCESS;
}