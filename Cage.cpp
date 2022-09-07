#pragma once
#include <iostream>
#include "Cage.h"

Cage::Cage(){
    name = "";
    id = 0;
}

Cage::Cage(string newName, int newNumber){
    name = newName;
    id = newNumber;
}

string Cage::get_name(){
    return name;
}

int Cage::get_IDnum(){
    return id;
}

Cage::~Cage(){

}
