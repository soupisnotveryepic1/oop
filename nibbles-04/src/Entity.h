#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
using namespace std;
using namespace sf;

class Entity{
protected:
    int x_pos;
    int y_pos;
    Shape* shape;
    int health;
    int damage;
    int speed;
public:


};