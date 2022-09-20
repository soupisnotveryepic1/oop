#pragma once
#include <SFML/Graphics.hpp>
#include "Sword.h"
#include "Enemy.h"
using namespace sf;

class Boss : public Enemy {
private:
    int sword_index;
    Projectile* swords;
    void resize();
public:
    Boss();
    void draw(RenderWindow* window);
    void use_fireball();
    bool successful_hit(Vector2f player_position);
    ~Boss(){delete[] swords;}
};
