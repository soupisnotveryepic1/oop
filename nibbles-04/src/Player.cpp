#include <iostream>
#include "Player.h"
using namespace std;

void Player::initTexture() {
    // initialises the texture of the player using a file
    playerTexture.loadFromFile("C:/textures/sprite.png");
}

void Player::initSprite() {
    // initialises the sprite of the player and re-sizes it to an appropriate size
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(-1.0f,1.0f);
}

Player::Player(int x_pos, int y_pos, int health) {
    // sets initial position of player to the x and y coordinates requested
    playerSprite.setPosition(x_pos,y_pos);
    // initialised texture and sprite
    initTexture();
    initSprite();
    // gives the player 50 arrows
    arrows = new Arrow[50];
    arrow_index = 0;
    arrows_left = 50;
    // sets boolean reload_arrows to false (this is true when arrows are reloaded)
    reload_arrows = false;
    // sets initial damage to 1
    damage = 1;
    // sets initial speed to 5
    speed = 5;
    // sets initial amount of gold to 0
    gold = 0;
    // sets initial health to the health specified when calling
    this->health = health;
}

void Player::draw(RenderWindow* window) {
    // draws player onto the window
    window->draw(playerSprite);
    for (int i = 0; i < 50; i++) {
        if (arrows_left > 0 && arrows[i].is_fired()) { // if arrow is fired:
            arrows[i].move_projectile(); // moves arrow according to the speed and direction
            arrows[i].draw(window); // draws arrows onto the window
        }
        if (reload_arrows && i == 49) { // if arrows are reloaded:
            i = 0; // sets i back to 0 so that the arrows can be drawn again
            reload_arrows = false; // sets reload_arrows back to false
        }
    }
}

void Player::reload() {
    // sets arrow_left and arrows_index back to initial values
    arrows_left = 50;
    arrow_index = 0;
    // arrows are deleted
    delete[] arrows;
    // 50 new arrows are allocated to the heap
    arrows = new Arrow[50];
    // sets reload_arrows to true so that the arrows can be re-drawn
    reload_arrows = true;
    printf("Reloaded");
}

void Player::use_arrow() { // allows player to use arrows
    if (!arrows[arrow_index].is_fired() && arrows_left > 1) { // if this specific arrow has not been fired and player has at least 1 arrow left:
        arrows_left--; // arrows_left decreases by 1
        arrows[arrow_index].use(playerSprite.getPosition()); // arrow is used at the position of the player at the time
        arrow_index++; // arrow_index incremented
    }
}

bool Player::successful_hit(Vector2f enemy_position) { // checks if arrow hits an enemy
    for (int i = 0; i < 50; i++) { // goes through all 50 arrows
        if (arrows[i].is_hit(enemy_position) && arrows[i].is_fired()) { // if an arrow has hit the enemy and that arrow is fired:
            arrows[i].hit_target(); // sets the arrow so that it has hit the target (which makes fired = false)
            return true; // returns true
        }
    }
    return false; // if not, returns false
}

bool Player::hit_by_enemy(Vector2f enemy_position) { // checks if player is hit by the enemy
    if (enemy_position.x >= playerSprite.getPosition().x - 75 && enemy_position.x <= playerSprite.getPosition().x && enemy_position.y >= playerSprite.getPosition().y - 50 && enemy_position.y <= playerSprite.getPosition().y + 25) {
        // if enemy comes within the player's hitbox, returns true;
        return true;
    }
    return false; // else returns false
}

