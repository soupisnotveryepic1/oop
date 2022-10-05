#pragma once
#include <SFML/Graphics.hpp>
#include "Sword.h"
#include "Enemy.h"
using namespace sf;

class Boss : public Enemy { // inherits class Enemy, which inherits class Character
private:
    int sword_index;
    Projectile* swords;
    // Function that re-sizes the Boss's sprite
    void resize();
public:
    // Initial Boss constructor
    Boss();
    // Function that draws the boss and the swords onto the window if the boss is alive.
    void draw(RenderWindow* window);
    // Function that allows the boss to use the swords.
    void use_sword();
    // Function that returns true if a sword has hit the player's hitbox, and returns false otherwise.
    bool successful_hit(Vector2f player_position);
    // Destructor for Boss, deletes swords pointer
    ~Boss(){delete[] swords;}
};
