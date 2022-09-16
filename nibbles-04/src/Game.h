#include <iostream>
#pragma once
#include "Player.h"
#include "Arrow.h"
#include "Enemy.h"
#include <chrono>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Game{
private:
    RenderWindow* window;
    Player* player;
    Enemy* enemies;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    int enemy_index;
    int level;
    int score;
public:
    Game(int height, int width, string name){
        window = new RenderWindow(VideoMode(height,width), name);
        this->window->setFramerateLimit(144);
        player = new Player(100,400, 5);
        enemies = new Enemy[50];
    }
    void run(){
        enemy_index = 0;
        score = 0;
        auto start = std::chrono::steady_clock::now();
        backgroundTexture.loadFromFile("C:/textures/background.gif");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0,0);
        backgroundSprite.scale(1.5,1.5);
        while (window->isOpen())
        {
            Event event;
            while (window->pollEvent(event)){
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
                if (Keyboard::isKeyPressed(Keyboard::Z)){
                    player->upgrade_damage();
                }
                if (Keyboard::isKeyPressed(Keyboard::L)){
                    level++;
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
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            //cout << elapsed_seconds.count() << endl;

            // level 1
            if (enemy_index < 10) {
                if (elapsed_seconds.count() > enemy_index) {
                    enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 700 + 50), 2, 1, 0.5f);
                    enemy_index++;
                }
            }
            for (int i = 0; i < 10; i++){
                if(enemies[i].is_alive()){
                    if (player->arrow_hits_enemy(enemies[i].get_position())){
                        enemies[i].take_damage(player->get_damage());
                        if (enemies[i].get_health() == 0) {
                            enemies[i].die();
                            score++;
                        }
                    }
                    if (enemies[i].get_position().x <= 0){
                        enemies[i].die();
                        player->take_damage(enemies[i].get_damage());
                    }
                    if (player->hit_by_enemy(enemies[i].get_position())){
                        enemies[i].die();
                        player->take_damage(enemies[i].get_damage());
                    }
                }
                if (player->get_health() == 0){
                    cout << "player die" << endl;
                }
            }
            cout << score << endl;
            window->clear();
            window->draw(backgroundSprite);
            player->draw(window);
            for (int i = 0; i < 50; i++){
                if (enemies[i].is_alive()) {
                    enemies[i].draw(window);
                }
            }
            window->display();
        }
    }
    ~Game(){
        delete this->window;
    };
};
