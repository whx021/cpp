// 34、五只小猪称体重
#include <iostream>
using namespace std;

int main(void) {
	int array[5] = { 300, 350, 500, 400, 250 };
	int max = 0;

	for (int i = 0; i < 5; ++i) {
		// cout << array[i] << endl;
		if (max < array[i]) {
			max = array[i];
		}
	}
	cout << "max = " << max << endl;
	
	// system("pause");
	return 0;
}