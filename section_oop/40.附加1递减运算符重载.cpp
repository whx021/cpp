// 40、附加1递减运算符重载

#include <iostream>
using namespace std;

class MyInteger_2 {
	friend ostream& operator<<(ostream& cout, MyInteger_2 myInt);
public:
	MyInteger_2() {
		member_num = 0;
	}

	// 重载前置'--'
	MyInteger_2& operator--(void) {
		--member_num;
		return *this;
	}

	// 重载后置'--'
	MyInteger_2 operator--(int) {
		MyInteger_2 temp = *this;
		--member_num;
		return temp;
	}
private:
	int member_num;
};

// 重载'<<'
ostream& operator<<(ostream& cout, MyInteger_2 myInt) {
	cout << myInt.member_num;
	return cout;
}

void test_3(void) {
	MyInteger_2 myInt;
	cout << --myInt << endl;
	cout << myInt << endl;
}

void test_4(void) {
	MyInteger_2 myInt;
	cout << myInt-- << endl;
	cout << myInt << endl;
}

int main(void) {
	test_3();
	test_4();
	// system("pause");
	return 0;
}