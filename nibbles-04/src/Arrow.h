#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
using namespace std;
using namespace sf;


class Arrow : public Projectile {
private:
    void initTexture();
    void initSprite();
public:
    Arrow(); // constructor
    bool is_hit(Vector2f enemy_position); // checks if arrow has hit enemy
};
