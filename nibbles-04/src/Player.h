#include <SFML/Graphics.hpp>
#pragma once
#include "Character.h"
#include "Arrow.h"
#include "Object.h"
#include "Character.h"
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
    bool arrow_fired;
    bool reload_arrows;
    void initTexture();
    void initSprite();
public:
    Player(int x_pos, int y_pos, int health);
    ~Player();
    void draw(RenderWindow* window) {
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
    void move_right() {
        playerSprite.move(speed,0);
    }
    void move_left() {
        playerSprite.move(-speed,0);
    }
    void move_up() {
        playerSprite.move(0,-speed);
    }
    void move_down() {
        playerSprite.move(0,speed);
    }
    void upgrade_speed() {
        speed++;
        cout << "speed increased to " << speed << endl;
    }
    void upgrade_damage() {
        damage++;
        cout << "damage increased to " << damage << endl;
    }
    void reload() {
        arrows_left = 50;
        arrow_index = 0;
        delete[] arrows;
        arrows = new Arrow[50];
        reload_arrows = true;
        printf("Reloaded");
    }

    void use_arrow() {
        if (!arrows[arrow_index].is_fired() && arrows_left > 1) {
            arrows_left--;
            arrow_fired = true;
            arrows[arrow_index].use(playerSprite.getPosition());
            arrow_index++;
        }
    }

    int no_arrows_left() {
        return arrows_left;
    }

    bool successful_hit(Vector2f enemy_position) {
        bool arrow_hit = false;
        for (int i = 0; i < 50; i++) {
            if (arrows[i].is_hit(enemy_position) && arrows[i].is_fired()) {
                arrows[i].hit_target();
                return true;
            }
        }
        return arrow_hit;
    }
    bool hit_by_enemy(Vector2f enemy_position) {
        bool hit_enemy = false;
        if (enemy_position.x >= playerSprite.getPosition().x - 75 && enemy_position.x <= playerSprite.getPosition().x && enemy_position.y >= playerSprite.getPosition().y - 50 && enemy_position.y <= playerSprite.getPosition().y + 25) {
            hit_enemy = true;
            return hit_enemy;
        }
        return hit_enemy;

    }

    int get_gold() {
        return gold;
    }

    void change_gold(int amount) {
        gold = gold + amount;
    }

    Vector2f get_position(){
        return playerSprite.getPosition();
    }


};
