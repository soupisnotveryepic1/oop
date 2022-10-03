#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Projectile {
protected:
    Sprite sprite;
    Texture texture;
    float speed;
    Vector2f direction;
    bool fired;
    virtual void initTexture() = 0;
    virtual void initSprite() = 0;
public:
    // Function that moves projectile according to its speed and direction
    void move_projectile() {sprite.move(speed * direction);}
    // Function that sets the projectile to be fired at the position of the entity that is firing it
    void use(Vector2f firing_position) {
        sprite.setPosition(firing_position);
        fired = true; // sets boolean variable fired to true, so that the code knows that this projectile is fired
    }
    // Function that checks if projectile is fired or not, returns true if it is, false otherwise
    bool is_fired() {return fired;}
    // Function that sets fired to false when the projectile hits the target
    // Function that sets fired to false when the projectile hits the target
    bool hit_target() {fired = false;}
    // Function that draws projectile to window
    void draw(RenderWindow* window) {window->draw(sprite);}
    // Virtual function for collision detection between projectile and characters
    virtual bool is_hit(Vector2f target_position) = 0;
    // Virtual destructor
    virtual ~Projectile(){}
};
