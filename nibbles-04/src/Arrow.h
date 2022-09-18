#include <SFML/Graphics.hpp>
#include <stdio.h>
#pragma once
using namespace std;
using namespace sf;
#include "Projectile.h"

class Arrow : public Projectile{
private:
    void initTexture();
    void initSprite();
public:
    Arrow();
    bool is_hit(Vector2f enemy_position) {
        bool hit = false;
        if (enemy_position.x >= sprite.getPosition().x - 25 && enemy_position.x <= sprite.getPosition().x + 25 && enemy_position.y >= sprite.getPosition().y - 75 && enemy_position.y <= sprite.getPosition().y){
            hit = true;
            return hit;
        }
        return hit;
    }
};
