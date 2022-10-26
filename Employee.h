#pragma once
#include <iostream>
using namespace std;

class Employee{
private:
    int payRate; // hourly payRate
public:
    float energyLevel;   // Initially 100%
    Employee();
    Employee(int payRate);   // creates a Employee with payRate
    void takeABreak(int mins);
    virtual void work(int mins) = 0;
    virtual float pay() = 0;
    int get_payRate(){return payRate;}
    float get_energyLevel(){return energyLevel;}
    void set_payRate(int n_rate){payRate = n_rate;}
    void set_energyLevel(float n_energy){energyLevel = n_energy;}
};
