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
    int arrow_index;
    bool arrow_fired;
    bool reload_arrows;
    void initTexture();
    void initSprite();
public:
    Player(int x_pos, int y_pos);
    ~Player();
    void draw(RenderWindow* window){
        window->draw(playerSprite);
        for (int i = 0; i < 50; i++) {
            if (arrows_left > 0 && arrow_fired) {
                arrows[i].move_arrow();
                arrows[i].draw(window);
            }
            //printf("%d",reload_arrows);
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
    int get_speed(){
        return speed;
    }
    void reload(){
        arrows_left = 50;
        arrow_index = 0;
        printf("Reloaded");
        delete[] arrows;
        arrows = new Arrow[50];
        reload_arrows = true;
    }
    void use_arrow(){
        //for (int i = 0; i < 50; i++)
            if (!arrows[arrow_index].isFired() && arrows_left > 1) {
                arrows_left--;
                arrow_fired = true;
                arrows[arrow_index].use(playerSprite.getPosition());
                arrow_index++;
                //break;
            }
    }
    int no_arrows_left(){
        return arrows_left;
    }
};
