#include <SFML/Graphics.hpp>
#include <stdio.h>
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
