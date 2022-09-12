#include <SFML/Graphics.hpp>
#pragma once
#include "Arrow.h"
#include "Player.h"
using namespace std;
using namespace sf;

class Enemy{
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
    void draw_enemy(RenderWindow* window);
};
