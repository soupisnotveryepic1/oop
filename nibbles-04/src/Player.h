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
    int speed;
    Arrow* arrows;
    int arrows_left;
    void initTexture();
    void initSprite();
public:
    Player(int x_pos, int y_pos);
    ~Player();
    void update();
    void render(RenderTarget& Target);
    void draw(RenderWindow* window){
        window->draw(playerSprite);
        if (arrows->fire_arrow()){
            arrows->move_arrow();
            arrows->draw(window);
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
    int get_speed(){
        return speed;
    }
    void use_arrow(){
        if (arrows_left > 0){
            arrows_left--;
            arrows->shoot_arrow(playerSprite.getPosition());
        } else {
            printf("Out of arrows!\n");
        }
        printf("Fired 2");
    }
};
