#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Arrow.h"

void Arrow::initTexture() {
    this->texture.loadFromFile("C:/textures/arrow.png");
}

void Arrow::initSprite() {
    this->sprite.setTexture(texture);
    this->sprite.scale(0.1f,0.1f);
}

Arrow::Arrow() {
    initTexture();
    initSprite();
    direction.x = 1;
    direction.y = 0;
    speed = 2;
    fired = false;
}
