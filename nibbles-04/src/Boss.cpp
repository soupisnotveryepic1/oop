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
    damage = 3;
}

void Boss::activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed) {
    this->health = max_hp;
    this->damage = damage;
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
        if (fireballs[i].is_fired()) {
            fireballs[i].move_projectile();
            fireballs[i].draw(window);
        }
    }
}
