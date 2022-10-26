#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(){

}

Employee::Employee(int payRate){
    this->payRate = payRate;
    energyLevel = 100;
}

void Employee::takeABreak(int mins){
    if (energyLevel <= 98){
        energyLevel = energyLevel + 2*mins;
    }
}
