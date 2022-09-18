#include <SFML/Graphics.hpp>
#pragma once
#include "Fireball.h"
#include "Character.h"
using namespace sf;

class Boss : public Character{
private:
    int fire_index;
    bool fired;
    Projectile* fireballs;
    Sprite bossSprite;
    Texture bossTexture;
    bool alive;
    void initSprite();
    void initTexture();
public:
    Boss();
    void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed);
    void draw(RenderWindow* window);
    bool is_hit(Vector2f arrow_coords, Sprite enemySprite);
    bool is_alive() {
        return alive;
    }
    Vector2f get_position() {
        return bossSprite.getPosition();
    }
    void take_damage(int player_damage) {
        health = health - player_damage;
    }

    void die() {
        alive = false;
    }

    void use_fireball(){
        if (!fireballs[fire_index].is_fired()) {
            fired = true;
            fireballs[fire_index].use(bossSprite.getPosition());
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
