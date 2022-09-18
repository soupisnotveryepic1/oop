#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
using namespace std;
using namespace sf;
#include "Object.h"

class Projectile{
protected:
    Sprite sprite;
    Texture texture;
    float speed;
    Vector2f direction;
    bool fired;
    virtual void initTexture() = 0;
    virtual void initSprite() = 0;
public:
    void move_projectile() {
        sprite.move(speed * direction);
    }
    void use(Vector2f firing_position){
        sprite.setPosition(firing_position);
        fired = true;
    }
    bool is_fired(){
        return fired;
    }
    bool hit_target(){
        fired = false;
    }
    void draw(RenderWindow* window) {
        window->draw(sprite);
    }
    virtual bool is_hit(Vector2f target_position) = 0;


};
