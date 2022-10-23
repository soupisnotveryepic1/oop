#include <string>
using namespace std;
#include "zoo.h"
#include <iostream>

zoo::zoo(std::string n, int cows, int lions) {
    name = n;
    animals = new animal*[cows+lions];
    for (int i = 0; i < cows; i++){
        animals[i] = new vegie("Daisy", 100);
    }
    for (int i = 0; i < lions; i++){
        animals[i + cows] = new hunter("Clarence", 50);
    }
}
