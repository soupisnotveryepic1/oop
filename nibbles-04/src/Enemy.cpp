#include <SFML/Graphics.hpp>
#include "Enemy.h"
using namespace std;
using namespace sf;

void Enemy::initTexture(){
    this->enemyTexture.loadFromFile("C:/textures/enemy.png");
}

void Enemy::initSprite(){
    this->enemySprite.setTexture(this->enemyTexture);
    this->enemySprite.scale(-0.2f,0.2f);
}

Enemy::Enemy() {
    this->initTexture();
    this->initSprite();
    bool alive = false;
}


void Enemy::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    this->maxHealth = max_hp;
    this->health = max_hp;
    this->attackDamage = damage;
    this->speed = speed;
    alive = true;
    enemySprite.setPosition(spawn_point);
}

void Enemy::draw_enemy(RenderWindow* window){
    if (alive) {
        enemySprite.move(-speed, 0);
        window->draw(enemySprite);
    }

}