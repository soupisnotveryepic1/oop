#include "Arrow.h"
using namespace std;


void Arrow::initTexture() {
    texture.loadFromFile("C:/textures/arrow.png");
}

void Arrow::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(0.1f,0.1f);
}

Arrow::Arrow() {
    initTexture();
    initSprite();
    direction.x = 1;
    direction.y = 0;
    speed = 2;
    fired = false;
}

bool Arrow::is_hit(Vector2f enemy_position) {
    bool hit = false;
    if (enemy_position.x >= sprite.getPosition().x - 25 && enemy_position.x <= sprite.getPosition().x + 25 && enemy_position.y >= sprite.getPosition().y - 75 && enemy_position.y <= sprite.getPosition().y){
        hit = true;
        return hit;
    }
    return hit;
}
