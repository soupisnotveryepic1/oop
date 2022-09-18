#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Fireball.h"
using namespace std;
using namespace sf;

void Fireball::initTexture() {
    fireTexture.loadFromFile("C:/textures/fireball.png");
}

void Fireball::initSprite() {
    fireSprite.setTexture(fireTexture);
    fireSprite.scale(-0.05f,0.05f);
}

Fireball::Fireball() {
    this->initTexture();
    this->initSprite();
    this->fire_direction.x = -1;
    this->fire_direction.y = 0;
    this->fireSpeed = 2;
    fired = false;
}
