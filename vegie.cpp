#include "vegie.h"
#include <string>
#include <iostream>
using namespace std;

vegie::vegie(string n, int v) : animal(n, v){
    favourite_food = "grass";
    set_name(n);
    set_volume(v);
    animalID = nextID;
    nextID++;
}

int vegie::nextID = 100;