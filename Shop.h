#pragma once
#include <iostream>
#include "Employee.h"
#include "Casual.h"
#include "Manager.h"
using namespace std;

class Shop{
private:
    Employee** employees;
    int count;
    Shop();
public:
    void addEmployee(Employee *employee);  // Adds a employee to the Shop
    Employee **get_employees(){return employees;};        // Returns the array of pointers to the five employee objects
    int get_count(){return count;}; // Returns the amount of employees added to the shop
    static Shop* createShop(int authority){
        if (authority == 10){
            Shop();
        } else {
            return NULL;
        }
    };
};
