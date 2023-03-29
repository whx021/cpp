// 封装函数显示界面void showMenu(void);
// 在main函数中调用

#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 1000

// 设计联系人的结构体
struct Person {
	string m_Name;
	int m_Sex;	// 1：男 2：女
	int m_Age;
	string m_PhoneNumber;
	string m_Address;
};

// 设计通讯录的结构体
struct AddressBooks {
	struct Person personArray[MAXSIZE];
	int m_Size;
};

// 菜单界面
void showMenu(void) {
	cout << "***********************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "***********************" << endl;
}

// 1、添加联系人
void addPerson(AddressBooks* abs) {
	// 通讯录已满无法添加联系人
	if (abs->m_Size == MAXSIZE) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	// 添加联系人
	else {
		// 添加联系人姓名
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		// 添加联系人性别
		cout << "请输入联系人性别：" << endl;
		cout << "1——男，2——女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "您的输入有误，请重新输入：" << endl;
		}

		// 添加联系人年龄
		cout << "请输入联系人年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 0 && age <= 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "您的输入有误，请重新输入：" << endl;
		}

		// 添加联系人电话号码
		cout << "请输入联系人电话号码：" << endl;
		string phone_number;
		cin >> phone_number;
		abs->personArray[abs->m_Size].m_PhoneNumber = phone_number;

		// 添加联系人家庭住址
		cout << "请输入联系人家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		// 更新通讯录中的人数
		++abs->m_Size;
		cout << "添加成功" << endl;
		// system("pause");	// 请按任意键继续
		// system("cls");	// 清屏
	}
}

// 2、显示联系人
void showPerson(const AddressBooks* abs) {
	// 判断通讯录中人数是否为0，
	// 人数为0时，提示记录为空
	// 人数不为0时，显示记录中的联系人
	if (abs->m_Size == 0) {
		cout << "通讯录中没有联系人！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; ++i) {
			cout << "姓名：" << abs->personArray[i].m_Name << '\t';
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << '\t';
			cout << "年龄：" << abs->personArray[i].m_Age << '\t';
			cout << "电话号码：" << abs->personArray[i].m_PhoneNumber << '\t';
			cout << "家庭住址：" << abs->personArray[i].m_Address << endl;
		}
	}

	// system("pause");	
	// system("cls");
}

// 检测联系人是否存在，
// 如果存在，返回该联系人在通讯录数组中的索引
// 如果不存在，返回-1
// 参数1：通讯录	参数2：对比姓名
int isExist(const AddressBooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; ++i) {
		// 找到了该联系人的姓名
		if (abs->personArray[i].m_Name == name) {
			return i;	// 找到了，返回该联系人在通讯录数组中的索引
		}
	}
	return -1;	// 没有找到，返回-1
}

// 3、删除联系人
void deletePerson(AddressBooks* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	// ret == -1	未查到
	// ret != -1	查到了
	int ret = isExist(abs, name);
	if (ret != -1) {
		// 找到此人，要进行删除操作
		for (int i = ret; i < abs->m_Size; ++i) {
			// 数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// 更新通讯录中的人员数
		--abs->m_Size;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	// system("pause");
	// system("cls");
}

// 4、查找联系人
void findPerson(AddressBooks* abs) {
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	
	// 找到联系人
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << '\t';
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" << abs->personArray[ret].m_Age << '\t';
		cout << "电话号码：" << abs->personArray[ret].m_PhoneNumber << '\t';
		cout << "家庭住址：" << abs->personArray[ret].m_Address << endl;
	}
	// 未找到联系人
	else {
		cout << "查无此人" << endl;
	}

	// system("pause");
	// system("cls");
}

// 5、修改联系人
void modifyPerson(AddressBooks* abs) {
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	// 找到联系人
	if (ret != -1) {
		// 进行修改

		// 修改姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// 修改性别
		cout << "请输入性别" << endl;
		cout << "1——男，2——女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "您的输入有误，请重新输入：" << endl;
		}

		// 修改年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 0 && age <= 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "您的输入有误，请重新输入：" << endl;
		}

		// 修改电话号码
		cout << "请输入电话号码：" << endl;
		string phone_number;
		cin >> phone_number;
		abs->personArray[ret].m_PhoneNumber = phone_number;
		
		// 修改家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;
	}
	// 未找到联系人
	else {
		cout << "查无此人" << endl;
	}

	// system("pause");
	// system("cls");
}

// 6、清空联系人
void clearPerson(AddressBooks* abs) {
	// 将当前的通讯录人数置为0，做逻辑清空操作
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	// system("pause");
	// system("cls");
}


int main(void) {
	AddressBooks abs;	// 创建一个通讯录的结构体变量
	abs.m_Size = 0;		// 初始化通讯录中当前人员个数
	int select = 0;		// 创建用户选择输入的变量

	while (true) {
		// 调用菜单界面
		showMenu();
		cin >> select;
		switch (select) {
		case 1:	// 1、添加联系人
			addPerson(&abs);	// 利用地址传递，可以修改实参
			break;
		case 2:	// 2、显示联系人
			showPerson(&abs);
			break;
		case 3:	// 3、删除联系人
		// {
		// 	cout << "请输入删除联系人姓名：" << endl;
		// 	string name;
		// 	cin >> name;
		// 	if (isExist(&abs, name) == -1) {
		// 		cout << "查无此人" << endl;
		// 	}
		// 	else {
		// 		cout << "找到此人" << endl;
		// 	}
		// }
			deletePerson(&abs);
			break;
		case 4:	// 4、查找联系人
			findPerson(&abs);
			break;
		case 5:	// 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:	// 6、清空联系人
			clearPerson(&abs);
			break;
		case 0:	// 0、推出通讯录
			cout << "欢迎下次使用" << endl;
			// system("pause");
			return EXIT_SUCCESS;
		default:
			break;
		}
	}
}