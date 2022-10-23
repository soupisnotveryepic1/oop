#pragma once
#include <string>
using namespace std;
#include "animal.h"

class vegie : public animal{
private:
    string favourite_food;
    static int nextID;
public:
    vegie(string n,int v);      // create a vegie with name n and body volume v
    string get_favourite_food(){return favourite_food;}
    void set_favourite_food(string s_food){favourite_food = s_food;}
    string get_name(){return "Safe: "+name;}

};
