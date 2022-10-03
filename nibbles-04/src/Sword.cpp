#include "Sword.h"
using namespace std;
using namespace sf;

void Sword::initTexture() {
    // initialises the texture of the sword using a file
    texture.loadFromFile("C:/textures/sword.png");
}

void Sword::initSprite() {
    // initialises the sprite of the sword and re-sizes it to an appropriate size
    sprite.setTexture(texture);
    sprite.scale(-0.08f,0.08f);
}

Sword::Sword() {
    initTexture();
    initSprite();
    // setting direction to x = -1 (left to right), and y between -0.5 and 0.5 (boss throws sword in random direction)
    direction.x = -1;
    direction.y = -0.5 + (double)rand()/RAND_MAX;
    // sets speed if sword to 2
    speed = 2;
    // when first constructed, it is not fired yet, so sets fired to false
    fired = false;
}

bool Sword::is_hit(Vector2f player_position) {
    // checks if the sword has hit the player or not
    if (player_position.x >= sprite.getPosition().x - 25 && player_position.x <= sprite.getPosition().x + 50 && player_position.y >= sprite.getPosition().y - 100 && player_position.y <= sprite.getPosition().y){
        // if the sword hits the player (in the hitbox), returns true if so
        return true;
    }
    // if not, returns false;
    return false;
}
