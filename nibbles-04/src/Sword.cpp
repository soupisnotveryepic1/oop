#include "Sword.h"
using namespace std;
using namespace sf;

void Sword::initTexture() {
    texture.loadFromFile("C:/textures/sword.png");
}

void Sword::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(-0.08f,0.08f);
}

Sword::Sword() {
    initTexture();
    initSprite();
    direction.x = -1;
    direction.y = 0;
    speed = 2;
    fired = false;
}

bool Sword::is_hit(Vector2f player_position) {
    bool hit = false;
    if (player_position.x >= sprite.getPosition().x - 25 && player_position.x <= sprite.getPosition().x + 25 && player_position.y >= sprite.getPosition().y - 75 && player_position.y <= sprite.getPosition().y){
        hit = true;
        return hit;
    }
    return hit;
}
