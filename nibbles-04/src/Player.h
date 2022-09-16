#include <SFML/Graphics.hpp>
#pragma once
#include "Entity.h"
#include "Arrow.h"
using namespace std;
using namespace sf;

class Player{
private:
    Sprite playerSprite;
    Texture playerTexture;
    int health;
    int maxHealth;
    int speed;
    int damage;
    Arrow* arrows;
    int arrows_left;
    int arrow_index;
    bool arrow_fired;
    bool reload_arrows;
    void initTexture();
    void initSprite();
public:
    Player(int x_pos, int y_pos, int health);
    ~Player();
    void draw(RenderWindow* window){
        window->draw(playerSprite);
        for (int i = 0; i < 50; i++) {
            if (arrows_left > 0 && arrows[i].isFired()) {
                arrows[i].move_arrow();
                arrows[i].draw(window);
            }
            if (reload_arrows && i == 49){
                i = 0;
                reload_arrows = false;
            }
        }

    }
    void move_right(){
        playerSprite.move(speed,0);
    }
    void move_left(){
        playerSprite.move(-speed,0);
    }
    void move_up(){
        playerSprite.move(0,-speed);
    }
    void move_down(){
        playerSprite.move(0,speed);
    }
    void upgrade_speed(){
        speed++;
        cout << "speed increased to " << speed << endl;
    }
    void upgrade_damage(){
        damage++;
        cout << "damage increased to " << speed << endl;
    }
    int get_speed(){
        return speed;
    }
    void reload(){
        arrows_left = 50;
        arrow_index = 0;
        delete[] arrows;
        arrows = new Arrow[50];
        reload_arrows = true;
        printf("Reloaded");
    }

    void use_arrow(){
        if (!arrows[arrow_index].isFired() && arrows_left > 1) {
            arrows_left--;
            arrow_fired = true;
            arrows[arrow_index].use(playerSprite.getPosition());
            arrow_index++;
        }
    }

    int no_arrows_left(){
        return arrows_left;
    }

    bool arrow_hits_enemy(Vector2f enemy_position){
        bool arrow_hit = false;
        for (int i = 0; i < 50; i++){
            if (arrows[i].is_hit(enemy_position) && arrows[i].isFired()){
                arrows[i].hit_enemy();
                return true;
            }
        }
        return arrow_hit;
    }
    bool hit_by_enemy(Vector2f enemy_position){
        bool hit_enemy = false;
        if (enemy_position.x >= playerSprite.getPosition().x - 25 && enemy_position.x <= playerSprite.getPosition().x + 25 && enemy_position.y >= playerSprite.getPosition().y - 25 && enemy_position.y <= playerSprite.getPosition().y + 25){
            hit_enemy = true;
            return hit_enemy;
        }
        return hit_enemy;

    }

    Vector2f get_position(){
        return playerSprite.getPosition();
    }

    int get_damage(){
        return damage;
    }

    void take_damage(int enemy_damage){
        health = health - enemy_damage;
    }

    int get_health(){
        return health;
    }

};
