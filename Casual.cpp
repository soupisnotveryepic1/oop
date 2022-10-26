#include <iostream>
#include "Casual.h"
using namespace std;

Casual::Casual(){

}

Casual::Casual(int payRate) : Employee(payRate){
    for (int i = 0; i < 7; i++){
        hoursWorked[i] = 0;
    }
    dayCount = 0;
    time_count = 0;
}

void Casual::endWorkDay() {
    energyLevel = 100;
    time_count = 0;
    if (dayCount == 7){
        dayCount = 0;
    } else {
        dayCount++;
    }
}

void Casual::work(int mins){
    for (int i = 0; i < mins; i++){
        if (energyLevel >= 0.5) {
            energyLevel = energyLevel - 0.5;
            time_count++;
        }
        if (dayCount <= 5){
            hoursWorked[dayCount] = time_count/60;
        } else {
            hoursWorked[dayCount] = time_count/20;
        }
    }
}

float Casual::pay(){
    float totalWorked = 0;
    for (int i = 0; i < 7; i++){
        totalWorked = totalWorked + hoursWorked[i];
        hoursWorked[i] = 0;
    }
    dayCount = 0;
    return totalWorked * payRate;
}
