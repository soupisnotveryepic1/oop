#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
using namespace std;
using namespace sf;
#include "Object.h"

class Character{
protected:
    float speed;
    int health;
    int damage;
public:
    void take_damage(int damage_received){
        health = health - damage_received;
    }
    int get_health(){
        return health;
    }
    int get_damage(){
        return damage;
    }

};