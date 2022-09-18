#include <SFML/Graphics.hpp>
#include <stdio.h>
#pragma once
using namespace std;
using namespace sf;

class Fireball {
private:
    Sprite fireSprite;
    Texture fireTexture;
    float fireSpeed;
    bool fired;
    Vector2f fire_direction;
    void initTexture();
    void initSprite();
public:
    Fireball();
    void draw(RenderWindow* window) {
        window->draw(fireSprite);
    }
    void move_fireball() {
        fireSprite.move(fireSpeed * fire_direction);
    }
    void use(Vector2f boss_position) {
        fireSprite.setPosition(boss_position);
        fired = true;
    }
    bool isFired() {
        return fired;
    }
    Vector2f get_position() {
        return fireSprite.getPosition();
    }
    bool is_hit(Vector2f player_position) {
        bool hit = false;
        if (player_position.x >= fireSprite.getPosition().x - 25 && player_position.x <= fireSprite.getPosition().x + 25 && player_position.y >= fireSprite.getPosition().y - 75 && player_position.y <= fireSprite.getPosition().y){
            hit = true;
            return hit;
        }
        return hit;
    }
    void hit_target() {
        fired = false;
    }
};
