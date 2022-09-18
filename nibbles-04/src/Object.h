#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
using namespace std;
using namespace sf;

class Object{
protected:
    virtual void initSprite() = 0;
    virtual void initTexture() = 0;
public:
    virtual Vector2f get_position() = 0;
    virtual void draw() = 0;
};
