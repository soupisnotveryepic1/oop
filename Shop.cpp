#include <iostream>
#include "Shop.h"
using namespace std;

Shop::Shop(){
    employees = new Employee*[5];
}

void Shop::addEmployee(Employee *employee) {
    employees[0] = new Manager(40);
    employees[1] = new Manager(20);
    employees[2] = new Manager(20);
}