#pragma once 
#include <iostream>
#include <string>
using namespace std;


class Worker {
public:
	virtual void showInfo(void) = 0;

	virtual string department(void) = 0;

	int member_id;
	string member_name;
	int member_department_id;
};