#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
using namespace std;
using namespace sf;


class Arrow : public Projectile { // inherits Projectile class
private:
    // Function that initialises the texture of the arrow
    void initTexture();
    // Function that initialises the sprite of the arrow
    void initSprite();
public:
    // Initial Arrow Constructor
    Arrow();
    // Function that returns true if arrow has hit the enemy's hit box, and false otherwise.
    bool is_hit(Vector2f enemy_position);
};
