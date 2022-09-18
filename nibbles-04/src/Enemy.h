#include <SFML/Graphics.hpp>
#pragma once
#include "Arrow.h"
#include "Player.h"
using namespace std;
using namespace sf;

class Enemy {
private:
    int health;
    int maxHealth;
    int attackDamage;
    float speed;
    Sprite enemySprite;
    Texture enemyTexture;
    bool alive;
    void initSprite();
    void initTexture();
public:
    Enemy();
    void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed);
    void draw(RenderWindow* window);
    bool is_hit(Vector2f arrow_coords, Sprite enemySprite);
    bool is_alive() {
        return alive;
    }
    Vector2f get_position() {
        return enemySprite.getPosition();
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
};
