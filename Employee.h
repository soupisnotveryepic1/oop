#pragma once
#include <iostream>
using namespace std;

class Employee{
private:
    int payRate; // hourly payRate
    float energyLevel;   // Initially 100%
public:
    Employee();
    Employee(int payRate);   // creates a Employee with payRate
    void takeABreak(int mins);
    virtual void work(int mins) = 0;
    virtual float pay() = 0;

};
