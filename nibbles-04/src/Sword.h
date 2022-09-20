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
    bool is_hit(Vector2f player_position){
            bool hit = false;
            if (player_position.x >= sprite.getPosition().x - 25 && player_position.x <= sprite.getPosition().x + 25 && player_position.y >= sprite.getPosition().y - 75 && player_position.y <= sprite.getPosition().y){
                hit = true;
                return hit;
            }
            return hit;
    };
};
