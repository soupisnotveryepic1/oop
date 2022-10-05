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
    // Function that initialises the texture of the player
    void initTexture();
    // Function that initialises the sprite of the player
    void initSprite();
public:
    // Initial constructor for Player
    Player(int x_pos, int y_pos, int health);
    // Destructor for Player, which deletes the arrows pointer
    ~Player(){delete[] arrows;};
    // Function that draws the player and arrows to the window.
    void draw(RenderWindow* window);

    // Functions that moves the player right/left/up/down
    void move_right() {playerSprite.move(speed,0);}
    void move_left() {playerSprite.move(-speed,0);}
    void move_up() {playerSprite.move(0,-speed);}
    void move_down() {playerSprite.move(0,speed);}
    // Function that upgrades player's speed;
    void upgrade_speed() {
        speed++;
        cout << "speed increased to " << speed << endl;
    }
    // Function that upgrades player's damage
    void upgrade_damage() {
        damage++;
        cout << "damage increased to " << damage << endl;
    }
    // Function that reloads the player's arrows if needed
    void reload();
    // Function that allows the player to use an arrow
    void use_arrow();
    // Function that returns how many arrows the player has left
    int no_arrows_left() {return arrows_left;}
    // Function that returns true if an arrow has hit an enemy, and returns false otherwise.
    bool successful_hit(Vector2f enemy_position);
    // Function that returns true if player has been hit by an enemy, and returns false otherwise.
    bool hit_by_enemy(Vector2f enemy_position);
    // Function that returns amount of gold player has
    int get_gold() {return gold;}
    // Function that changes the amount of gold the player has
    void change_gold(int amount) {gold += amount;}
    // Function that returns player's position
    Vector2f get_position() {return playerSprite.getPosition();}
};
