#include <SFML/Graphics.hpp>
#pragma once
#include "Fireball.h"
using namespace sf;

class Boss {
private:
    int health;
    int maxHealth;
    int attackDamage;
    int fire_index;
    float speed;
    bool fired;
    Fireball* fireballs;
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
    int get_health() {
        return health;
    }
    void die() {
        alive = false;
    }

    int get_damage() {
        return attackDamage;
    }

    void use_fireball(){
        if (!fireballs[fire_index].isFired()) {
            fired = true;
            fireballs[fire_index].use(bossSprite.getPosition());
            fire_index++;
        }
    }
    bool arrow_hits_player(Vector2f player_position){
        bool arrow_hit = false;
        for (int i = 0; i < 50; i++) {
            if (fireballs[i].is_hit(player_position) && fireballs[i].isFired()) {
                fireballs[i].hit_target();
                return true;
            }
        }
        return arrow_hit;
    }
};
