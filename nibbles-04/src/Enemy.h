#include <SFML/Graphics.hpp>
#pragma once
#include "Arrow.h"
#include "Player.h"
using namespace std;
using namespace sf;

class Enemy : public Character { // inherits class Character
protected:
    Sprite sprite;
    Texture texture;
    void initSprite();
    void initTexture();
public:
    Enemy();
    void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed);
    virtual void draw(RenderWindow* window);
    Vector2f get_position() {return sprite.getPosition();} // returns the enemy's position
    virtual void use_sword() {}
    virtual bool successful_hit(Vector2f position){}
};
