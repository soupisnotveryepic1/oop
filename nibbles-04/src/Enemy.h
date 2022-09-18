#include <SFML/Graphics.hpp>
#pragma once
#include "Arrow.h"
#include "Player.h"
#include "Character.h"
using namespace std;
using namespace sf;

class Enemy : public Character{
private:
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
    void die() {
        alive = false;
    }

};
