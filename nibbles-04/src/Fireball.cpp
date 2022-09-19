#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Fireball.h"
using namespace std;
using namespace sf;


void Fireball::initTexture() {
    texture.loadFromFile("C:/textures/sword.png");
}

void Fireball::initSprite() {
    sprite.setTexture(texture);
    sprite.scale(-0.08f,0.08f);
}

Fireball::Fireball() {
    initTexture();
    initSprite();
    direction.x = -1;
    direction.y = 0;
    speed = 2;
    fired = false;
}
