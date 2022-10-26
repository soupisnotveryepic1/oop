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
    float get_hoursWorked(){return hoursWorked;}
    void set_hoursWorked(float s_hours){hoursWorked = s_hours;}
    int get_daysWorked(){return daysWorked;}
    void set_daysWorked(int s_days){daysWorked = s_days;}
    void work(int mins);
};
