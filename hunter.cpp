#include "hunter.h"
#include <string>
using namespace std;

hunter::hunter(std::string n, int v) : animal(n, v){
    kills = 0;
    set_name(n);
    set_volume(v);
    animalID = nextID;
    nextID++;
}

string hunter::get_name(){
    return "Hunter: "+name;
}

int hunter::nextID = 1000;
