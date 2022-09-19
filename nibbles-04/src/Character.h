#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
using namespace std;
using namespace sf;
#include "Object.h"

class Character{
protected:
    bool alive;
    float speed;
    int health;
    int damage;
public:
    virtual void draw(RenderWindow* window) = 0;
    void take_damage(int damage_received){
        health = health - damage_received;
    }

    int get_health(){
        return health;
    }

    int get_damage(){
        return damage;
    }

    bool is_alive() {
        return alive;
    }

    void die() {
        alive = false;
    }
};