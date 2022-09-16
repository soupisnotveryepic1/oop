#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Player.h"

void Player::initTexture() {
    playerTexture.loadFromFile("C:/textures/sprite.png");
}

void Player::initSprite(){
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(-1.0f,1.0f);
}

Player::Player(int x_pos, int y_pos, int health){
    playerSprite.setPosition(x_pos,y_pos);
    initTexture();
    initSprite();
    speed = 7;
    arrows_left = 50;
    arrows = new Arrow[50];
    arrow_fired = false;
    arrow_index = 0;
    reload_arrows = false;
    damage = 1;
    gold = 0;
    this->maxHealth = health;
    this->health = health;
}

Player::~Player(){

}

