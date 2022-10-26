#include <iostream>
#include "Casual.h"
using namespace std;

Casual::Casual(){

}

Casual::Casual(int payRate) {
    this->payRate = payRate;
    for (int i = 0; i < 7; i++){
        hoursWorked[i] = 0;
    }
    dayCount = 0;
}

void Casual::endWorkDay() {
    energyLevel = 100;
    if (dayCount == 7){
        dayCount = 0;
    } else {
        dayCount++;
    }
}

void Casual::work(int mins){
    for (int i = 0; i < mins; i++){
        energyLevel = energyLevel - 0.5;
    }
    if (dayCount <= 5){
        hoursWorked[dayCount] = mins/60;
    } else {
        hoursWorked[dayCount] = mins/30;
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
