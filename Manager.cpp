#include <iostream>
#include "Manager.h"
using namespace std;

Manager::Manager(int payRate){
    hoursWorked = 0;
    daysWorked = 0;
}

void Manager::work(int mins){
    for (int i = 0; i < mins; i++){
        if (energyLevel >= 0.25 && time_count < 480) {
            energyLevel = energyLevel - 0.25;
            time_count++;
            hoursWorked = hoursWorked + 1/60;
        }
    }
    if (time_count >= 480){
        daysWorked++;
        hoursWorked = 0;
        energyLevel = 100;
        time_count = 0;
    }
}

float Manager::pay(){
    daysWorked = 0;
    hoursWorked = 0;
    return daysWorked * 8 * payRate;
}
