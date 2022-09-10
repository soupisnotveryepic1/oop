#include <iostream>
#pragma once
#include "Player.h"
#include "Arrow.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Game{
private:
    RenderWindow* window;
    Player* player;
public:
    Game(int height, int width, string name){
        window = new RenderWindow(VideoMode(height,width), name);
        this->window->setFramerateLimit(144);
        player = new Player(400,400);
    }
    void run(){
        while (window->isOpen())
        {
            Event event;
            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == Event::Closed) {
                    window->close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Up)){
                    player->move_up();
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)){
                    player->move_down();
                }
                if (Keyboard::isKeyPressed(Keyboard::Right)){
                    player->move_right();
                }
                if (Keyboard::isKeyPressed(Keyboard::Left)){
                    player->move_left();
                }
                if (Keyboard::isKeyPressed(Keyboard::U)){
                    player->upgrade_speed();
                }
                if (event.type == Event::KeyReleased){
                    if (event.key.code == Keyboard::Space) {
                        player->use_arrow();
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::R) && player->no_arrows_left() == 1){
                    player->reload();
                }

            }
            window->clear();
            player->draw(window);
            window->display();
        }
    }
    ~Game(){
        delete this->window;
    };
};
