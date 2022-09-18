#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Fireball.h"
using namespace std;
using namespace sf;


void Fireball::initTexture() {
    texture.loadFromFile("C:/textures/fireball.png");
}

void Fireball::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(-0.05f,0.05f);
}

Fireball::Fireball() {
    initTexture();
    initSprite();
    direction.x = -1;
    direction.y = 0;
    speed = 2;
    fired = false;
}
