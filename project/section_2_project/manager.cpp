#include "manager.h"

Manager::Manager(int id, string name, int did) {
	this->member_id = id;
	this->member_name = name;
	this->member_department_id = did;
}

void Manager::showInfo(void) {
	cout << "职工编号：" << this->member_id << " ";
	cout << "职工姓名：" << this->member_name << "\t";
	cout << "职工部门：" << this->department() << " ";
	cout << "职工职责：完成老板交给的任务" << endl;
}

string Manager::department(void) {
	return string("经理");
}