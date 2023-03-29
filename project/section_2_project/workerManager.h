#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "employeeFile.txt"

class WorkerManager {
public:
	WorkerManager();

	~WorkerManager();

	void showMenu(void);

	void exitSystem(void);

	void addWorker(void);

	void saveFile(void);

	// 记录文件是否为空
	bool fileEmpty;

	int getEmployeeNum(void);

	void initWorkerList(void);

	void showEmployee(void);

	int employeeIsExist(int id);

	void deleteEmployee(void);

	void modifyEmployee(void);

	void findEmployee(void);

	void sortWorker(void);

	void cleanFile(void);

	int member_worker_num;
	Worker** member_worker_list;
};