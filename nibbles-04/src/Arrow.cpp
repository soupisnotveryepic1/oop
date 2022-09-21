#include "Arrow.h"
using namespace std;


void Arrow::initTexture() {
    // initialises the texture of the arrow using a file
    texture.loadFromFile("C:/textures/arrow.png");
}

void Arrow::initSprite() {
    // initialises the sprite of the arrow and re-sizes it to an appropriate size
    sprite.setTexture(texture);
    sprite.scale(0.1f,0.1f);
}

Arrow::Arrow() {
    initTexture();
    initSprite();
    // sets x-direction to 1 (right to left), and y-direction to 0 (only moves horizontally)
    direction.x = 1;
    direction.y = 0;
    // sets speed to 2
    speed = 2;
    // when first constructed, it is not fired yet, so sets fired to false
    fired = false;
}

bool Arrow::is_hit(Vector2f enemy_position) {
    // checks if the arrow has hit the enemy or not
    if (enemy_position.x >= sprite.getPosition().x - 25 && enemy_position.x <= sprite.getPosition().x + 25 && enemy_position.y >= sprite.getPosition().y - 75 && enemy_position.y <= sprite.getPosition().y){
        // if the arrow hits the enemy (in the hitbox), returns boolean true if so
        return true;
    }
    // if not, returns false
    return false;
}
