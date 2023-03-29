#pragma once 
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class Employee : public Worker {
public:
	Employee(int id, string name, int did);

	virtual void showInfo(void);

	virtual string department(void);
};