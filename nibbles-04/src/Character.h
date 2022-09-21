#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Character {
protected:
    bool alive;
    float speed;
    int health;
    int damage;
public:
    virtual void draw(RenderWindow* window) = 0; // virtual function that will draw the character to the window
    void take_damage(int damage_received) {health = health - damage_received;} // makes the character take damage
    int get_health() {return health;} // returns character's health
    int get_damage() {return damage;} // returns character's damage
    bool is_alive() {return alive;} // returns if character is alive of not
    float get_speed() {return speed;} // returns character's speed
    void die() {alive = false;} // kills character
};