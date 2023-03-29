#include "workerManager.h"


WorkerManager::WorkerManager() {
	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	// 1、文件不存在，打开失败
	if (!ifs.is_open()) {
		// cout << "文件不存在" << endl;
		this->member_worker_num = 0;
		this->member_worker_list = nullptr;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// 2、文件存在，文件为空
	// 使用ch抽取ifs关联文件的字符为EOF（空文件中唯一字符）
	char ch;
	ifs >> ch;	
	if (ifs.eof()) {
		// cout << "文件为空" << endl;
		this->member_worker_num = 0;
		this->member_worker_list = nullptr;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// 3、文件存在，且不为空，使用文件中的数据初始化当前类维护的数据
	if (this->getEmployeeNum() != 0) {
		// cout << "当前员工数量为：" << this->getEmployeeNum() << endl;
		this->member_worker_num = this->getEmployeeNum();
		this->member_worker_list = new Worker * [member_worker_num];
		this->initWorkerList(); 
		this->fileEmpty = false;
		// //test
		// for (int i = 0; i < this->member_worker_num; ++i) {
		// 	cout << "职工编号：" << this->member_worker_list[i]->member_id << " "
		// 		<< "职工姓名：" << this->member_worker_list[i]->member_name << " "
		// 		<< "部门编号：" << this->member_worker_list[i]->member_department_id << endl;
		// }
	}
}

WorkerManager::~WorkerManager() {
	// 清空当前对象维护的数据
	if (this->member_worker_list != nullptr) {
		// 清空堆区创建的当前对象维护的数据的每一个指针维护的员工类的对象
		for (int i = 0; i < this->member_worker_num; ++i) {
			if (this->member_worker_list[i] != nullptr) {
				delete this->member_worker_list[i];
				this->member_worker_list[i] = nullptr;
			}
		}
		// 清空堆区创建的当前对象维护的数据的指针数组
		delete[] this->member_worker_list;
		this->member_worker_num = NULL;
		this->member_worker_num = 0;
		this->fileEmpty = true;
	}
}

void WorkerManager::showMenu(void) {
	cout << "*************************************" << endl;
	cout << "*********** 0、退出管理系统 ***********" << endl;
	cout << "*********** 1、增加职工信息 ***********" << endl;
	cout << "*********** 2、显示职工信息 ***********" << endl;
	cout << "*********** 3、删除离职职工 ***********" << endl;
	cout << "*********** 4、修改职工信息 ***********" << endl;
	cout << "*********** 5、查找职工信息 ***********" << endl;
	cout << "*********** 6、按照编号排序 ***********" << endl;
	cout << "*********** 7、清空所有文档 ***********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem(void) {
	cout << "欢迎下次使用" << endl;
	// system("pause");
	exit(EXIT_SUCCESS);
}

void WorkerManager::addWorker(void) {
	// 用户输入添加新员工数量
	cout << "请输入添加新员工的数量：" << endl;
	int add_num = 0;
	cin >> add_num;
	
	// 如果添加的数量合理，进行添加
	if (add_num > 0) {
		// 计算新空间的大小，并创建新空间
		int newSize = this->member_worker_num + add_num;
		Worker** newSpace = new Worker * [newSize];

		// 将原空间的数据复制到新空间中
		if (this->member_worker_list != nullptr) {
			for (int i = 0; i < this->member_worker_num; ++i) {
				newSpace[i] = this->member_worker_list[i];
			}
		}

		// 依次向新空间中添加新数据
		for (int i = 0; i < add_num; ++i) {
			int id;
			string name;
			int did;
			cout << "请输入添加的第 " << i + 1 << " 位新员工的职工编号" << endl;
			cin >> id;
			cout << "请输入添加的第 " << i + 1 << " 位新员工的职工姓名" << endl;
			cin >> name;
			cout << "请输入添加的第 " << i + 1 << " 位新员工的部门编号" << endl;
			cout << "1、职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			
			// 根据用户输入创建具体新员工对象
			Worker* worker = nullptr;
			switch (did) {
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				cout << "您的输入有误" << endl;
				break;
			}
			
			// 将创建的新员工对象添加到新空间中
			newSpace[this->member_worker_num + i] = worker;
		}
		
		// 改变当前类维护的数据
		delete[] this->member_worker_list;
		this->member_worker_list = newSpace;
		this->member_worker_num = newSize;

		// 保存数据到文件中
		this->saveFile();
		this->fileEmpty = false;
		cout << "成功添加 " << add_num << " 位新职工" << endl;
	}
	// 如果添加的数量不合理
	else {
		cout << "您的输入有误" << endl;
	}
	// system("pause");
	// system("cls");
}	

void WorkerManager::saveFile(void) {
	ofstream ofs;

	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->member_worker_num; ++i) {
		ofs << this->member_worker_list[i]->member_id << " "
			<< this->member_worker_list[i]->member_name << " "
			<< this->member_worker_list[i]->member_department_id << endl;
	}

	ofs.close();
}

int WorkerManager::getEmployeeNum(void) {
	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	// 记录文件中的员工数量
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did) {
		++num;
	}

	return num;
}

void WorkerManager::initWorkerList(void) {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 将文件中的数据逐个添加到当前类维护的数据中
	int id;
	string name;
	int did;
	int index = 0;
	
	// 读到EOF，结束循环
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = nullptr;

		if (did == 1) {
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else if (did == 3) {
			worker = new Boss(id, name, did);
		}

		// 将当前读取的数据存放到类维护的数据中
		this->member_worker_list[index++] = worker;
	}
	ifs.close();
}

void WorkerManager::showEmployee(void) {
	if (this->fileEmpty) {
		cout << "文件夹不存在或记录为空" << endl;
	}
	else {
		// 利用多态调用每一名员工的showInfo()接口
		for (int i = 0; i < this->member_worker_num; ++i) {
			this->member_worker_list[i]->showInfo();
		}
	}
	// system("pause");
	// system("cls");
}

int WorkerManager::employeeIsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->member_worker_num; ++i) {
		if (id == this->member_worker_list[i]->member_id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteEmployee(void) {
	if (this->fileEmpty) {
		cout << "文件夹不存在或记录为空" << endl;
	}
	else {
		cout << "请输入需要删除员工的职工编号：" << endl;
		int id;
		cin >> id;

		int index = this->employeeIsExist(id);

		// 职工存在，删除索引为index的员工
		if (index != -1) {
			for (int i = index; i < this->member_worker_num; ++i) {
				this->member_worker_list[i] = this->member_worker_list[i + 1];
			}
			--this->member_worker_num;

			this->saveFile();
		}
		else {
			cout << "未找到该员工，删除失败" << endl;
		}
	}
	// system("pause");
	// system("cls");
}

void WorkerManager::modifyEmployee(void) {
	if (this->fileEmpty) {
		cout << "文件夹不存在或记录为空" << endl;
	}
	else {
		cout << "请输入要修改的员工编号：" << endl;
		int id;
		cin >> id;

		int index = this->employeeIsExist(id);
		if (index != -1) {
			delete this->member_worker_list[index];
			
			cout << "查找到" << id << "号员工" << endl;

			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "请输入该员工新的职工编号" << endl;
			cin >> new_id; 
			cout << "请输入该员工新的职工姓名" << endl;
			cin >> new_name;
			cout << "请输入该员工新的部门编号" << endl;
			cout << "1、职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> new_did;

			// 根据用户输入创建具体新员工对象
			Worker* worker = nullptr;
			switch (new_did) {
			case 1:
				worker = new Employee(new_id, new_name, new_did);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_did);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_did);
				break;
			default:
				cout << "您的输入有误" << endl;
				break;
			}

			// 将的新员工对象添加到新空间中
			this->member_worker_list[index] = worker;

			this->saveFile();

			cout << "修改成功" << endl;
		}
		else {
			cout << "未找到该员工，修改失败" << endl;
		}
	}
	// system("pause");
	// system("cls");
}

void WorkerManager::findEmployee(void) {
	if (this->fileEmpty) {
		cout << "文件夹不存在或记录为空" << endl;
	}
	else {
		cout << "请选择查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select = 0;
		cin >> select;

		// 按编号查找
		if (select == 1) {
			cout << "请输入需要查找的职工编号：" << endl;
			int id;
			cin >> id;
			
			int index = this->employeeIsExist(id);
			if (index != -1) {
				cout << "职工编号为 " << id << " 的员工信息为：" << endl;
				this->member_worker_list[index]->showInfo();
			}
			else {
				cout << "未找到职工编号为 " << id << " 的员工" << endl;
			}
		}
		// 按姓名查找
		else if (select == 2) {
			cout << "请输入需要查找的职工姓名：" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->member_worker_num; ++i) {
				if (name == this->member_worker_list[i]->member_name) {
					cout << "职工姓名为 " << this->member_worker_list[i]->member_name << " 的员工信息为：" << endl;
					this->member_worker_list[i]->showInfo();
					flag = true;
				}
			}

			if (flag = false) {
				cout << "未找到职工姓名为 " << name << " 的员工" << endl;
			}
		}
		// 选择错误
		else {
			cout << "您的输入有误" << endl;
		}
	}
	// system("pause");
	// system("cls");
}

void WorkerManager::sortWorker(void) {
	if (this->fileEmpty) {
		cout << "文件夹不存在或记录为空" << endl;
		// system("pause");
		// system("cls");
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号升序" << endl;
		cout << "2、按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		
		for (int i = 0; i < this->member_worker_num; ++i) {
			int minOrMax = i;
			for (int j = i + 1; j < this->member_worker_num; ++j) {
				if (select == 1) {
					if (this->member_worker_list[minOrMax]->member_id > this->member_worker_list[j]->member_id) {
						minOrMax = j;
					}
				}
				else {
					if (this->member_worker_list[minOrMax]->member_id < this->member_worker_list[j]->member_id) {
						minOrMax = j;
					}
				}
			}

			if (minOrMax != i) {
				Worker* temp = this->member_worker_list[i];
				this->member_worker_list[i] = this->member_worker_list[minOrMax];
				this->member_worker_list[minOrMax] = temp;
			}
		}
		this->saveFile();
		cout << "排序成功，排序后结果为：" << endl;
		this->showEmployee();
	}
}


void WorkerManager::cleanFile(void) {
	cout << "确定清空吗？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select;
	cin >> select;

	// 清空文件及当前对象维护的数据
	if (select == 1) {
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		// 清空当前对象维护的数据
		if (this->member_worker_list != nullptr) {
			// 清空堆区创建的当前对象维护的数据的每一个指针维护的员工类的对象
			for (int i = 0; i < this->member_worker_num; ++i) {
				if (this->member_worker_list[i] != nullptr) {
					delete this->member_worker_list[i];
					this->member_worker_list[i] = nullptr;
				}
			}

			// 清空堆区创建的当前对象维护的数据的指针数组
			delete[] this->member_worker_list;
			this->member_worker_num = NULL;
			this->member_worker_num = 0;
			this->fileEmpty = true;
		}
		cout << "清空成功" << endl;
	}	
	// system("pause");
	// system("cls");
}