#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
using namespace std;
using namespace sf;

class Sword : public Projectile{ // inherits Projectile class
private:
    // Function that initialises the texture of the sword
    void initTexture();
    // Function that initialises the sprite of the sword
    void initSprite();
public:
    // Initial constructor for Sword
    Sword();
    // Function that returns true if sword has hit player's hit box, returns false otherwise.
    bool is_hit(Vector2f player_position);
};
