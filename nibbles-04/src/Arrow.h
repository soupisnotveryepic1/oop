#include <SFML/Graphics.hpp>
#include <stdio.h>
#pragma once
using namespace std;
using namespace sf;

class Arrow{
private:
    Sprite arrowSprite;
    Texture arrowTexture;
    float arrowSpeed;
    bool fired;
    Vector2f arrow_direction;
    void initTexture();
    void initSprite();
public:
    Arrow();
    void draw(RenderWindow* window){
        window->draw(arrowSprite);
    }
    void move_arrow(){
        this->arrowSprite.move(this->arrowSpeed * arrow_direction);
    }
    void shoot_arrow(Vector2f player_position){
        printf("Fired 3");
        arrowSprite.setPosition(player_position);
        printf("Fired 3");
        fired = true;
    }
    bool fire_arrow(){
        return fired;
    }
};
