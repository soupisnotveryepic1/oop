#include <SFML/Graphics.hpp>
#pragma once
#include "Sword.h"
#include "Enemy.h"
using namespace sf;

class Boss : public Enemy{
private:
    int sword_index;
    Projectile* swords;
    void resize();
public:
    Boss();
    void draw(RenderWindow* window);
    void use_fireball(){
        if (!swords[sword_index].is_fired()) {
            swords[sword_index].use(Vector2f(sprite.getPosition().x + 55, sprite.getPosition().y + 20));
            sword_index++;
        }
    }
    bool successful_hit(Vector2f player_position){
        bool sword_hit = false;
        for (int i = 0; i < 50; i++) {
            if (swords[i].is_hit(player_position) && swords[i].is_fired()) {
                swords[i].hit_target();
                return true;
            }
        }
        return sword_hit;
    }
};
