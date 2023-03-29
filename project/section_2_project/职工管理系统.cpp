#include <iostream>
#include <string>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test_1(void) {
	Worker* w = new Employee(1, "张三", 1);
	w->showInfo();
	delete w;

	w = new Manager(2, "李四", 2);
	w->showInfo();
	delete w;

	w = new Boss(3, "王五", 3);
	w->showInfo();
	delete w;
	w = nullptr;
}

int main(void) {
	// test_1();

	WorkerManager wm;

	int choice = 0;

	while (true) {
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
			
		switch (choice) {
		case 0:		// 0、退出管理系统
			wm.exitSystem();
			break;
		case 1:		// 1、增加职工信息
			wm.addWorker();
			break;
		case 2:		// 2、显示职工信息
			wm.showEmployee();
			break;
		case 3:		// 3、删除离职职工
			wm.deleteEmployee();
			break;
		// //test
		// {
		// 	int result = wm.employeeIsExit(5);
		// 	if (result != -1) {
		// 		wm.member_worker_list[result]->showInfo();
		// 	}
		// 	else {
		// 		cout << "职工不存在" << endl;
		// 	}
		// 	break;
		// }
		case 4:		// 4、修改职工信息
			wm.modifyEmployee();
			break;
		case 5:		// 5、查找职工信息
			wm.findEmployee();
			break;
		case 6:		// 6、按照编号排序
			wm.sortWorker();
			break;
		case 7:		// 7、清空所有文档
			wm.cleanFile();
			break;
		default:
			// system("cls");
			break;
		}
	}
	// system("pause");
	return EXIT_SUCCESS;
}