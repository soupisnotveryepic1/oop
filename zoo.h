#pragma once
#include "animal.h"
#include "vegie.h"
#include "hunter.h"
#include <string>
using namespace std;

class zoo{
private:
    string name;                          // the zoo's name
    int number_of_animals;                // the number of animals in the zoo
    animal** animals;                      // the zoo's animals
public:
    zoo(string n,int cows,int lions);      // create a zoo with the given number of cows and lions
    int get_number_of_animals(){return number_of_animals;}
    animal** get_animals(){return animals;}
    string get_name(){return name;}
};
