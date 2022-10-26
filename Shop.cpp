#include <iostream>
#include "Shop.h"
using namespace std;

Shop::Shop(){
    employees = new Employee*[5];
}

void Shop::addEmployee(Employee *employee) {
    if (count < 5){
        employees[count] = employee;
    }
}