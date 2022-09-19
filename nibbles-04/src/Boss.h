#include <SFML/Graphics.hpp>
#pragma once
#include "Fireball.h"
#include "Enemy.h"
using namespace sf;

class Boss : public Enemy{
private:
    int fire_index;
    Projectile* fireballs;
    void resize();
public:
    Boss();
    void draw(RenderWindow* window);
    void use_fireball(){
        if (!fireballs[fire_index].is_fired()) {
            fireballs[fire_index].use(sprite.getPosition());
            fire_index++;
        }
    }
    bool successful_hit(Vector2f player_position){
        bool arrow_hit = false;
        for (int i = 0; i < 50; i++) {
            if (fireballs[i].is_hit(player_position) && fireballs[i].is_fired()) {
                fireballs[i].hit_target();
                return true;
            }
        }
        return arrow_hit;
    }
};
