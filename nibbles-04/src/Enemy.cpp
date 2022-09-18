#include <SFML/Graphics.hpp>
#include "Enemy.h"
using namespace std;
using namespace sf;

void Enemy::initTexture() {
    this->enemyTexture.loadFromFile("C:/textures/enemySprite.gif");
}

void Enemy::initSprite() {
    this->enemySprite.setTexture(this->enemyTexture);
    this->enemySprite.scale(1.5f,1.5f);
}

Enemy::Enemy() {
    this->initTexture();
    this->initSprite();
    alive = false;
}


void Enemy::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    this->maxHealth = max_hp;
    this->health = max_hp;
    this->attackDamage = damage;
    this->speed = speed;
    alive = true;
    enemySprite.setPosition(spawn_point);
}

void Enemy::draw(RenderWindow* window) {
    if (alive) {
        enemySprite.move(-speed, 0);
        window->draw(enemySprite);
    }
}

