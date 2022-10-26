#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

class Manager : public Employee{
private:
    float hoursWorked;
    int daysWorked;
public:
    Manager();
    Manager(int payRate);
};
