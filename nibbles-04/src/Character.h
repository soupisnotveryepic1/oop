#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Character { // Abstract class
protected:
    bool alive;
    float speed;
    int health;
    int damage;
public:
    // Pure virtual function that will draw the character to the window
    virtual void draw(RenderWindow* window) = 0;
    // Function that makes the character take damage
    void take_damage(int damage_received) {health = health - damage_received;}
    // Function that returns the character's health
    int get_health() {return health;}
    // Function that returns the character's damage stat
    int get_damage() {return damage;}
    // Function that returns true if character is alive, and false otherwise.
    bool is_alive() {return alive;}
    // Function that returns the character's speed
    float get_speed() {return speed;}
    // Function that kills the character by setting alive to false
    void die() {alive = false;}
};