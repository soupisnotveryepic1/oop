#pragma once
#include <SFML/Graphics.hpp>
#include "Sword.h"
#include "Enemy.h"
using namespace sf;

class Boss : public Enemy { // inherits class Enemy, which inherits class Character
private:
    int sword_index;
    Projectile* swords;
    void resize();
public:
    Boss();
    void draw(RenderWindow* window);
    void use_sword();
    bool successful_hit(Vector2f player_position);
    ~Boss(){delete[] swords;} // when boss goes out of scope, deletes the swords pointer
};
