#include "Clinic.h"
#include <iostream>

Clinic::Clinic(){
    clinic_name = "";
    max_size = 0;
    index = 0;
}

Clinic::Clinic(std::string name, int max_size) {
    clinic_name = name;
    max_size = max_size;
    index = 0;
    cages = new Cage[max_size];
}

int Clinic::get_number_of_cages() {
    return index;
}

string Clinic::get_name() {
    return clinic_name;
}

Cage* Clinic::get_cages(){
    return cages;
}

bool Clinic::add_cage(Cage new_cage) {
    if (index >= max_size){
        return false;
    } else {
        cages[index] = new_cage;
        index++;
        return true;
    }
    return true;
}

Clinic::~Clinic(){

}