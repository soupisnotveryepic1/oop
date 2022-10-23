#pragma once
#include <string>
using namespace std;

class animal{
protected:
    // animals are allocated a unique ID on creation
    string name ;              // the animal's name
    int animalID ;             // the animal's unique ID
    int volume ;               // the volume of the animal's body
public:
    animal();
    animal(string n, int v);
    void set_name(string s_name){name = s_name;}
    void set_volume(int s_volume){volume = s_volume;}
    virtual string get_name() = 0;
    int get_volume(){return volume;}
    int get_id(){return animalID;}
};
