#include <SFML/Graphics.hpp>
#include "Boss.h"
using namespace sf;
using namespace std;

void Boss::resize() {
    sprite.scale(2.2f,2.2f);
}
Boss::Boss() {
    resize();
    alive = false;
    swords = new Sword[500];
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

void Boss::use_sword() {
    if (!swords[sword_index].is_fired()) {
        swords[sword_index].use(Vector2f(sprite.getPosition().x + 55, sprite.getPosition().y + 20));
        sword_index++;
    }
    cout << sword_index << endl;
}

bool Boss::successful_hit(Vector2f player_position) {
    bool sword_hit = false;
    for (int i = 0; i < 50; i++) {
        if (swords[i].is_hit(player_position) && swords[i].is_fired()) {
            swords[i].hit_target();
            return true;
        }
    }
    return sword_hit;
}
