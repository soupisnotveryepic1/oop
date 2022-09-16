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
        arrowSprite.move(arrowSpeed * arrow_direction);
    }
    void use(Vector2f player_position){
        arrowSprite.setPosition(player_position);
        fired = true;
    }
    bool isFired(){
        return fired;
    }
    Vector2f get_position(){
        return arrowSprite.getPosition();
    }
    bool is_hit(Vector2f enemy_position){
        bool hit = false;
        if (enemy_position.x >= arrowSprite.getPosition().x - 25 && enemy_position.x <= arrowSprite.getPosition().x + 25 && enemy_position.y >= arrowSprite.getPosition().y - 75 && enemy_position.y <= arrowSprite.getPosition().y){
            hit = true;
            return hit;
        }
        return hit;
    }
    void hit_enemy(){
        fired = false;
    }

};
