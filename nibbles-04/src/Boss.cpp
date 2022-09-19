#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace sf;
using namespace std;
#include "Boss.h"

void Boss::resize() {
    sprite.scale(2.2f,2.2f);
}
Boss::Boss(){
    resize();
    alive = false;
    swords = new Sword[100];
    sword_index = 0;
    damage = 3;
}

void Boss::draw(RenderWindow* window) {
    if (alive) {
        sprite.move(-speed, 0);
        window->draw(sprite);
    }
    for (int i = 0; i < 100; i++) {
        if (swords[i].is_fired()) {
            swords[i].move_projectile();
            swords[i].draw(window);
        }
    }
}
