#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Arrow.h"
using namespace std;
using namespace sf;

class Player : public Character {
private:
    Sprite playerSprite;
    Texture playerTexture;
    int gold;
    Projectile* arrows;
    int arrows_left;
    int arrow_index;
    bool reload_arrows;
    void initTexture();
    void initSprite();
public:
    Player(int x_pos, int y_pos, int health);
    ~Player(){delete[] arrows;}; // when player goes out of scope, deletes the arrows pointer
    void draw(RenderWindow* window);
    void move_right() {playerSprite.move(speed,0);}
    void move_left() {playerSprite.move(-speed,0);}
    void move_up() {playerSprite.move(0,-speed);}
    void move_down() {playerSprite.move(0,speed);}
    void upgrade_speed() { // upgrades player's speed;
        speed++;
        cout << "speed increased to " << speed << endl;
    }
    void upgrade_damage() { // upgrades player's damage
        damage++;
        cout << "damage increased to " << damage << endl;
    }
    void reload();
    void use_arrow();
    int no_arrows_left() {return arrows_left;} // returns how many arrows the player has left
    bool successful_hit(Vector2f enemy_position);
    bool hit_by_enemy(Vector2f enemy_position);
    int get_gold() {return gold;} // returns amount of gold player has
    void change_gold(int amount) {gold += amount;} // changes the amount of gold the player has
    Vector2f get_position() {return playerSprite.getPosition();} // returns player's position
};
