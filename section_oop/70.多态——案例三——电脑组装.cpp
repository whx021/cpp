// 70、多态——案例三——电脑组装

#include <iostream>
using namespace std;

// 抽象类
class CPU {
public:
	virtual void calculate(void) = 0;
};

class VideoCard {
public:
	virtual void display(void) = 0;
};

class Memory {
public:
	virtual void storage(void) = 0;
};

// 厂家类
class IntelCPU : public CPU {
public:
	virtual void calculate(void) {
		cout << "IntelCPU is working." << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:
	virtual void display(void) {
		cout << "IntelVideoCard is working." << endl;
	}
};

class IntelMemory : public Memory {
public:
	virtual void storage(void) {
		cout << "IntelMemory is working." << endl;
	}
};

class LenovoCPU : public CPU {
public:
	virtual void calculate(void) {
		cout << "LenovoCPU is working." << endl;
	}
};

class LenovoVideoCard : public VideoCard {
public:
	virtual void display(void) {
		cout << "LenovoVideoCard is working." << endl;
	}
};

class LenovoMemory : public Memory {
public:
	virtual void storage(void) {
		cout << "LenovoMemory is working." << endl;
	}
};

// 电脑类
class Computer {
public:
	// 有参构造函数参数：基类指针
	Computer(CPU* cpu, VideoCard* vc, Memory* m) : member_cpu(cpu), member_vc(vc), member_m(m) {
		// member_cpu = cpu;
		// member_vc = vc;
		// member_m = m;
	}

	~Computer() {
		if (member_cpu != nullptr) {
			delete member_cpu;
			member_cpu = nullptr;
		}
		if (member_vc != nullptr) {
			delete member_vc;
			member_vc = nullptr;
		}
		if (member_m != nullptr) {
			delete member_m;
			member_m = nullptr;
		}
	}
	
	// 多态调用继承类重写的基类纯虚函数
	void Working(void) {
		member_cpu->calculate();
		member_vc->display();
		member_m->storage();
	}
private:
	CPU* member_cpu;
	VideoCard* member_vc;
	Memory* member_m;
};

void test_1(void) {
	// 实例化对象时参数：继承类指针
	CPU* icpu = new IntelCPU;
	VideoCard* ivc = new IntelVideoCard;
	Memory* im = new IntelMemory;
	// 在堆区创建Computer，并用computer1指针维护
	Computer* computer1 = new Computer(icpu, ivc, im);
	computer1->Working();
	delete computer1;
	cout << "----------------------------------" << endl;
	
	CPU* lcpu = new LenovoCPU;
	VideoCard* lvc = new LenovoVideoCard;
	Memory* lm = new LenovoMemory;
	// 在堆区创建Computer，并用computer2指针维护
	Computer* computer2 = new Computer(lcpu, lvc, lm);
	computer2->Working();
	delete computer2;
	cout << "----------------------------------" << endl;
	
	// 在堆区创建Computer，并用computer3指针维护
	Computer* computer3 = new Computer(new IntelCPU, new IntelVideoCard, new LenovoMemory);
	computer3->Working();
	delete computer3;
}

int main(void) {
	test_1();
	// system("pause");
	return EXIT_SUCCESS;
}