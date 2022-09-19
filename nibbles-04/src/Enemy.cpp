#include <SFML/Graphics.hpp>
#include "Enemy.h"
using namespace std;
using namespace sf;

void Enemy::initTexture() {
    this->texture.loadFromFile("C:/textures/enemySprite.gif");
}

void Enemy::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.scale(1.5f,1.5f);
}

Enemy::Enemy() {
    this->initTexture();
    this->initSprite();
    alive = false;
}


void Enemy::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    this->health = max_hp;
    this->damage = damage;
    this->speed = speed;
    alive = true;
    sprite.setPosition(spawn_point);
}

void Enemy::draw(RenderWindow* window) {
    if (alive) {
        sprite.move(-speed, 0);
        window->draw(sprite);
    }
}

