#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Player.h"

void Player::initTexture() {
    this->playerTexture.loadFromFile("C:/textures/sprite.png");
}

void Player::initSprite(){
    this->playerSprite.setTexture(this->playerTexture);
    this->playerSprite.scale(-1.0f,1.0f);
}

Player::Player(int x_pos, int y_pos){
    playerSprite.setPosition(x_pos,y_pos);
    this->initTexture();
    this->initSprite();
    speed = 7;
    arrows_left = 50;
    arrows = new Arrow[50];
    arrow_fired = false;
    arrow_index = 0;
    reload_arrows = false;
}

Player::~Player(){

}

