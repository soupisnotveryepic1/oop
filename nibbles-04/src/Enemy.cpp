#include <SFML/Graphics.hpp>
#include "Enemy.h"
using namespace std;
using namespace sf;

void Enemy::initTexture() {
    // initialises the texture of the enemy using a file
    texture.loadFromFile("C:/textures/enemySprite.gif");
}

void Enemy::initSprite() {
    // initialises the sprite of the enemy and re-sizes it to an appropriate size
    sprite.setTexture(this->texture);
    sprite.scale(1.5f,1.5f);
}

Enemy::Enemy() {
    // initialise texture and sprite when constructed
    initTexture();
    initSprite();
    // when first constructed, it is not alive yet, so sets alive to false
    alive = false;
}


void Enemy::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    // when enemy is activated, enemy receives its stats (health, damage, speed)
    health = max_hp;
    this->damage = damage;
    this->speed = speed;
    // sets alive to true when enemy is activated
    alive = true;
    // sets the position of the sprite to a specified spawn point
    sprite.setPosition(spawn_point);
}

void Enemy::draw(RenderWindow* window) {
    if (alive) { // if enemy is alive:
        sprite.move(-speed, 0); // enemy moves according to its speed stat
        window->draw(sprite); // draws enemy
    }
}

