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
    Sword();
    bool is_hit(Vector2f player_position);
};
