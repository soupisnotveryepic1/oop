#pragma once
#include <iostream>
#include "Cage.h"
using namespace std;
class Clinic{
private:
    string clinic_name;
    int max_size;
    int index;
    Cage* cages;
public:
    Clinic();                                      // default constructor
    Clinic(std::string name, int max_size);        // constructor with given Clinic size and
    // Clinic name

    int get_number_of_cages();                     // returns the number of cages currently in the the clinic

    std::string get_name();                        // returns the clinics's name
    Cage * get_cages();                            // returns the array of cages currently in the clinic


    bool add_cage(Cage new_cage);                  // returns true and adds new cage to the clinic if the clinic is not full
    // otherwise returns false

    ~Clinic();

};
