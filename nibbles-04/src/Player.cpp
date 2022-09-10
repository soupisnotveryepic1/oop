#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Player.h"

void Player::initTexture() {
    this->playerTexture.loadFromFile("C:/Users/Michael Lee/Downloads/sprite.png");
}

void Player::initSprite(){
    this->playerSprite.setTexture(this->playerTexture);
    this->playerSprite.scale(-1.0f,1.0f);
}

Player::Player(int x_pos, int y_pos){
    playerSprite.setPosition(x_pos,y_pos);
    this->initTexture();
    this->initSprite();
    speed = 2;
    arrows = new Arrow[5];
    arrows_left = 50;
    printf("Render 1");
}

Player::~Player(){

}

void Player::render(sf::RenderTarget &target) {
    target.draw(this->playerSprite);
}

void Player::update(){

}