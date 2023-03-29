// 31、goto语句

#include <iostream>
using namespace std;

int main(void) {
	cout << "1、XXXXX" << endl;
	cout << "2、XXXXX" << endl;
	goto FLAG;
	cout << "3、XXXXX" << endl;
	cout << "4、XXXXX" << endl;
	FLAG:
	cout << "5、XXXXX" << endl;
	
	system("pause");
	return 0;
}