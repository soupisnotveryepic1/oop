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
    // Constructor for enemy
    Enemy();
    // Function that activates the enemy by setting alive to true, and gives it stats such as spawn point, health, damage and speed
    void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed);
    // Virtual function that draws enemy to the window
    virtual void draw(RenderWindow* window);
    // Function that returns the enemy's position
    Vector2f get_position() {return sprite.getPosition();}
    virtual void use_sword() {}
    virtual bool successful_hit(Vector2f position) {}
};
