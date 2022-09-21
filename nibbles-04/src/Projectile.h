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
    void move_projectile() {sprite.move(speed * direction);} // moves projectile according to its speed and direction
    void use(Vector2f firing_position) { // sets the projectile to be fired at the position of the entity that is firing it
        sprite.setPosition(firing_position);
        fired = true; // sets boolean variable fired to true, so that the code knows that this projectile is fired
    }
    bool is_fired() {return fired;} // checks if projectile is fired of now
    bool hit_target() {fired = false;}
    void draw(RenderWindow* window) {window->draw(sprite);} // draws projectile to window
    virtual bool is_hit(Vector2f target_position) = 0;
    virtual ~Projectile(){}
};
