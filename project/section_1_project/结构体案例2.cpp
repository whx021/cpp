// 59、结构体案例2

#include <iostream>
#include <cstring>
using namespace std;

struct Hero {
	string name;
	int age;
	string sex;
};

void bubbling_sort(Hero heroArray[], int length) {
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void print_hero(Hero heroArray[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << "姓名：" << heroArray[i].name << "\t年龄：" << heroArray[i].age
			<< "\t性别：" << heroArray[i].sex << endl;
	}
}

int main(void) {
	// 1、设计英雄的结构体
	// 2、创建数组存放5名英雄
	// 3、对数组按照年龄进行升序排序
	// 4、将排序后的结果打印输出
	Hero heroArray[5] = {
		{"刘备", 23, "男"},
		{"关羽", 21, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"}
	};

	int length = sizeof(heroArray) / sizeof(heroArray[0]);
	
	cout << "排序前的打印结果" << endl;
	print_hero(heroArray, length);

	bubbling_sort(heroArray, length);

	cout << "排序后的打印结果" << endl;
	print_hero(heroArray, length);

	// system("pause");
	return 0;
}