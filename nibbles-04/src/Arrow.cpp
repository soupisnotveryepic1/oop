#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Arrow.h"

void Arrow::initTexture() {
    this->arrowTexture.loadFromFile("C:/textures/arrow.png");
}

void Arrow::initSprite() {
    this->arrowSprite.setTexture(arrowTexture);
    this->arrowSprite.scale(0.1f,0.1f);
}

Arrow::Arrow() {
    this->initTexture();
    this->initSprite();
    this->arrow_direction.x = 1;
    this->arrow_direction.y = 0;
    this->arrowSpeed = 2;
    fired = false;
}
