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
    // Initial Arrow Constructor
    Arrow();
    // Function that returns true if arrow has hit the enemy's hitbox, and false otherwise.
    bool is_hit(Vector2f enemy_position);
};
