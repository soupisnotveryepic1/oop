#include <iostream>
#include "Player.h"
using namespace std;

void Player::initTexture() {
    playerTexture.loadFromFile("C:/textures/sprite.png");
}

void Player::initSprite() {
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(-1.0f,1.0f);
}

Player::Player(int x_pos, int y_pos, int health) {
    playerSprite.setPosition(x_pos,y_pos);
    initTexture();
    initSprite();
    speed = 5;
    arrows_left = 50;
    arrows = new Arrow[50];
    arrow_index = 0;
    reload_arrows = false;
    damage = 1;
    gold = 0;
    this->health = health;
}

void Player::draw(RenderWindow* window) {
    window->draw(playerSprite);
    for (int i = 0; i < 50; i++) {
        if (arrows_left > 0 && arrows[i].is_fired()) {
            arrows[i].move_projectile();
            arrows[i].draw(window);
        }
        if (reload_arrows && i == 49) {
            i = 0;
            reload_arrows = false;
        }
    }
}

void Player::reload() {
    arrows_left = 50;
    arrow_index = 0;
    delete[] arrows;
    arrows = new Arrow[50];
    reload_arrows = true;
    printf("Reloaded");
}

void Player::use_arrow() {
    if (!arrows[arrow_index].is_fired() && arrows_left > 1) {
        arrows_left--;
        arrows[arrow_index].use(playerSprite.getPosition());
        arrow_index++;
    }
}

bool Player::successful_hit(Vector2f enemy_position) {
    bool arrow_hit = false;
    for (int i = 0; i < 50; i++) {
        if (arrows[i].is_hit(enemy_position) && arrows[i].is_fired()) {
            arrows[i].hit_target();
            return true;
        }
    }
    return arrow_hit;
}

bool Player::hit_by_enemy(Vector2f enemy_position) {
    bool hit_enemy = false;
    if (enemy_position.x >= playerSprite.getPosition().x - 75 && enemy_position.x <= playerSprite.getPosition().x && enemy_position.y >= playerSprite.getPosition().y - 50 && enemy_position.y <= playerSprite.getPosition().y + 25) {
        hit_enemy = true;
        return hit_enemy;
    }
    return hit_enemy;
}

