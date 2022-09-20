#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Arrow.h"
using namespace std;
using namespace sf;

class Player : public Character{
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
    ~Player(){delete[] arrows;};
    void draw(RenderWindow* window);
    void move_right() {playerSprite.move(speed,0);}
    void move_left() {playerSprite.move(-speed,0);}
    void move_up() {playerSprite.move(0,-speed);}
    void move_down() {playerSprite.move(0,speed);}
    void upgrade_speed() {
        speed++;
        cout << "speed increased to " << speed << endl;
    }
    void upgrade_damage() {
        damage++;
        cout << "damage increased to " << damage << endl;
    }
    void reload();
    void use_arrow();
    int no_arrows_left() {return arrows_left;}
    bool successful_hit(Vector2f enemy_position);
    bool hit_by_enemy(Vector2f enemy_position);
    int get_gold() {return gold;}
    void change_gold(int amount) {gold += amount;}
    Vector2f get_position() {return playerSprite.getPosition();}
};
