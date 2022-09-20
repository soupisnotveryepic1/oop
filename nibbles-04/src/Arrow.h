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
    Arrow();
    bool is_hit(Vector2f enemy_position);
};
