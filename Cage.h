#pragma once
#include <iostream>
using namespace std;
class Cage{
private:
    string name;
    int id;
public:
    Cage();                                         // a default constructor ID number is zero and occupant name is an empty string ""
    Cage(string newName, int newNumber);       // a constructor that takes the ID number and occupant name
    string get_name();                         // returns the name of the cage occupant
    int get_IDnum();                                // returns the cage's ID number
    ~Cage();                                        // destructor
};