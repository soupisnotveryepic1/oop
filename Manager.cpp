#include <iostream>
#include "Manager.h"
using namespace std;

Manager::Manager(int payRate){
    hoursWorked = 0;
    daysWorked = 0;
}

void Manager::work(int mins){
    for (int i = 0; i < mins; i++){
        if (energyLevel >= 0.25) {
            energyLevel = energyLevel - 0.25;
        }
    }
}
