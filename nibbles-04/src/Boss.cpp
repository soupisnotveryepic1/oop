#include <SFML/Graphics.hpp>
#include "Boss.h"
using namespace sf;
using namespace std;

void Boss::resize() {
    // resizes the enemy's sprite so it is bigger
    sprite.scale(2.2f,2.2f);
}
Boss::Boss() {
    resize();
    // when first constructed, it is not alive yet, so sets alive to false
    alive = false;
    // gives the boss 200 swords to throw
    swords = new Sword[200];
    // sets sword_index (index to the array of swords) to 0
    sword_index = 0;
}

void Boss::draw(RenderWindow* window) { // draws the boss and its swords onto the window
    if (alive) { // if boss is alive:
        sprite.move(-speed, 0); // moves right to left according to speed stat
        window->draw(sprite); // draws to window
    }
    for (int i = 0; i < 200; i++) { // for all 200 swords
        if (swords[i].is_fired()) { // if the specified sword is fired:
            swords[i].move_projectile(); // moves sword
            swords[i].draw(window); // draws sword to window
        }
    }
}

void Boss::use_sword() { // allows boss to throw sword
    if (!swords[sword_index].is_fired()) { // if this sword has not been fired yet
        swords[sword_index].use(Vector2f(sprite.getPosition().x + 55, sprite.getPosition().y + 20)); // sets sword's position to boss's position at the time
        sword_index++; // increments sword_index so that the next time this function is called, the next sword is used
    }
}

bool Boss::successful_hit(Vector2f player_position) { // checks if sword hits player
    for (int i = 0; i < 200; i++) { // checks for all 200 swords
        if (swords[i].is_hit(player_position) && swords[i].is_fired()) { // if sword hits player and that sword is fired:
            swords[i].hit_target(); // specified sword hits target (which will make fired = false)
            return true; // returns true;
        }
    }
    return false; // else returns false
}
