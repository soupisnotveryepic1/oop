#include <iostream>
#pragma once
#include "Player.h"
#include "Arrow.h"
#include "Enemy.h"
#include "Fireball.h"
#include "Boss.h"
#include "Object.h"
#include <chrono>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Game {
private:
    RenderWindow* window;
    Player* player;
    Enemy* enemies;
    Enemy* boss;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    int enemy_index;
    int enemy_number;
    int fireball_index;
    int level;
    int score;
    double a;
    Text gold_text;
    Text instructions_text;
    Text speed_text;
    Text damage_text;
    Font font;
    Sprite goldSprite;
    Texture goldTexture;
public:
    Game(int height, int width, string name) {
        window = new RenderWindow(VideoMode(height,width), name);
        this->window->setFramerateLimit(144);
        player = new Player(100,400, 5);
        boss = new Boss;
        enemies = new Enemy[50];
        if (!font.loadFromFile("C:/textures/font.ttf")){
            cout << "font not found" << endl;
        }
        gold_text.setFont(font);
        gold_text.setColor(sf::Color::Yellow);
        gold_text.setCharacterSize(20);
        speed_text.setFont(font);
        speed_text.setColor(sf::Color::Cyan);
        speed_text.setCharacterSize(20);
        damage_text.setFont(font);
        damage_text.setColor(sf::Color::Magenta);
        damage_text.setCharacterSize(20);
        instructions_text.setFont(font);
        instructions_text.setColor(sf::Color::White);
        instructions_text.setCharacterSize(100);
        goldTexture.loadFromFile("C:/textures/gold.png");
        goldSprite.setTexture(goldTexture);
        goldSprite.scale(0.12f,0.12f);
        goldSprite.setPosition(20,770);
    }
    void run() {
        enemy_index = 0;
        score = 0;
        enemy_number = 0;
        fireball_index = 0;
        level = 0;
        backgroundTexture.loadFromFile("C:/textures/background.gif");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0,0);
        backgroundSprite.scale(1.44,1.44);
        string instruction;
        instruction = "Instructions: \n Press Space to shoot arrows";
        auto start = std::chrono::steady_clock::now();
        while (window->isOpen())
        {
            Event event;
            while (window->pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == Event::Closed) {
                    window->close();
                }
                if (level != 0) {
                    if (Keyboard::isKeyPressed(Keyboard::Up) && player->get_position().y > 0) {
                        player->move_up();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Down) && player->get_position().y < 650) {
                        player->move_down();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Right) && player->get_position().x < 800) {
                        player->move_right();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Left) && player->get_position().x > 70) {
                        player->move_left();
                    }
                    if (event.type == Event::KeyReleased) {
                        if (event.key.code == Keyboard::Space) {
                            player->use_arrow();
                        }
                        if (event.key.code == Keyboard::Z && player->get_gold() >= 500){
                            player->upgrade_damage();
                            player->change_gold(-500);
                        }
                        if (event.key.code == Keyboard::U && player->get_gold() >= 350){
                            player->upgrade_speed();
                            player->change_gold(-350);
                        }
                    }
                    if (Keyboard::isKeyPressed(Keyboard::R) && player->no_arrows_left() == 1) {
                        player->reload();
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::L) && level == 0 || Keyboard::isKeyPressed(Keyboard::L) && enemy_number == 10 && level == 1 || Keyboard::isKeyPressed(Keyboard::L) && enemy_number == 30 && level == 2) {
                level++;
                auto inst = std::chrono::steady_clock::now();
                std::chrono::duration<double> i = inst - start;
                a = i.count();
            }
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;

            if (level == 0) {
                instructions_text.setPosition(50,100);
                instructions_text.setString(instruction);
                window->draw(instructions_text);
            }
            if (level == 1) {
                //cout << elapsed_seconds.count() - a << endl;
                if (enemy_index < 10) { // wave 1
                    if (elapsed_seconds.count() - a > enemy_index && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 2, 1, 0.5f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - a > 25 && enemy_index < 30){ // wave 2
                    if (elapsed_seconds.count() - a > enemy_index + 15 && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 5, 2, 0.75f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - a > 60 && enemy_index < 50){ // wave 3
                    if (elapsed_seconds.count() - a > enemy_index + 30 && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 8, 3, 0.9f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - a >= 0 && enemy_index == 1) { // boss spawn
                    if (!boss->is_alive()) {
                        boss->activate_enemy(Vector2f(800, 300), 50, 3, 0.3f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - a <= 0.3 * (fireball_index + 1) && elapsed_seconds.count() >= 0.3 * (fireball_index - 0.5)) {
                    boss->use_fireball();
                    fireball_index++;
                }
                for (int i = 0; i < 50; i++) {
                    if (enemies[i].is_alive()) {
                        if (player->successful_hit(enemies[i].get_position())) {
                            enemies[i].take_damage(player->get_damage());
                            if (enemies[i].get_health() <= 0) {
                                enemies[i].die();
                                player->change_gold(100);
                                score++;
                                enemy_number++;
                            }
                        }
                        if (enemies[i].get_position().x <= 0) {
                            enemies[i].die();
                            player->take_damage(enemies[i].get_damage());
                            enemy_number++;
                        }
                        if (player->hit_by_enemy(enemies[i].get_position())) {
                            enemies[i].die();
                            player->take_damage(enemies[i].get_damage());
                            player->change_gold(50);
                            enemy_number++;
                        }
                        if (player->get_health() == 0) {
                            cout << "player die" << endl;
                        }
                    }
                    if (boss->is_alive()) {
                        if (player->successful_hit(Vector2f(boss->get_position().x, boss->get_position().y + 60))) {
                            boss->take_damage(boss->get_damage());
                            if (boss->get_health() <= 0) {
                                boss->die();
                                player->change_gold(10000);
                                score = score + 20;
                                enemy_number++;
                            }
                        }
                        if (boss->successful_hit(player->get_position())){
                            player->take_damage(boss->get_damage());
                        }
                        if (boss->get_position().x <= 0) {
                            boss->die();
                            player->take_damage(enemies[i].get_damage());
                            enemy_number++;
                        }
                        if (player->hit_by_enemy(boss->get_position())) {
                            boss->die();
                            player->take_damage(boss->get_damage());
                            enemy_number++;
                        }
                        if (player->get_health() == 0) {
                            cout << "player die" << endl;
                        }
                    }

                }
            }
            window->clear();
            window->draw(backgroundSprite);
            player->draw(window);
            for (int i = 0; i < 50; i++) {
                if (enemies[i].is_alive()) {
                    enemies[i].draw(window);
                }
            }
            if (boss->is_alive()){
                boss->draw(window);
            }
            string gold_display;
            gold_display = to_string(player->get_gold());
            string speed_display;
            speed_display = "Speed: " + to_string(int(player->get_speed())) + " Cost to Upgrade: 350  Upgrade:U";
            string damage_display = "Damage: " + to_string(int(player->get_damage())) + " Cost to Upgrade: 500  Upgrade:Z";
            speed_text.setPosition(120,770);
            speed_text.setString(speed_display);
            damage_text.setPosition(108,745);
            damage_text.setString(damage_display);
            gold_text.setPosition(50,770);
            gold_text.setString(gold_display);
            if (level == 0) {
                window->draw(instructions_text);
            }
            window->draw(gold_text);
            window->draw(speed_text);
            window->draw(damage_text);
            window->draw(goldSprite);
            window->display();
        }
    }
    ~Game() {
        delete this->window;
    };
};
