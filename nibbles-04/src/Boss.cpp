#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace sf;
using namespace std;
#include "Boss.h"

void Boss::initTexture() {
    this->bossTexture.loadFromFile("C:/textures/boss.png");
}

void Boss::initSprite() {
    this->bossSprite.setTexture(this->bossTexture);
    this->bossSprite.scale(-0.05f,0.05f);
}
Boss::Boss(){
    initTexture();
    initSprite();
    alive = false;
    fireballs = new Fireball[100];
    fire_index = 0;
    fired = false;
    attackDamage = 3;
}

void Boss::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    this->maxHealth = max_hp;
    this->health = max_hp;
    this->attackDamage = damage;
    this->speed = speed;
    alive = true;
    bossSprite.setPosition(spawn_point);
}

void Boss::draw(RenderWindow* window) {
    if (alive) {
        bossSprite.move(-speed, 0);
        window->draw(bossSprite);
    }
    for (int i = 0; i < 100; i++) {
        if (fireballs[i].isFired()) {
            fireballs[i].move_fireball();
            fireballs[i].draw(window);
        }
    }
}
