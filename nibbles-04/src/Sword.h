#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
using namespace std;
using namespace sf;

class Sword : public Projectile{
private:
    void initTexture();
    void initSprite();
public:
    // Initial constructor for Sword
    Sword();
    // Function that returns true if sword has hit player's hitbox, returns false otherwise.
    bool is_hit(Vector2f player_position);
};
