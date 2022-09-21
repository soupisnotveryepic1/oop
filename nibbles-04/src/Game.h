#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "Enemy.h"
#include "Sword.h"
#include "Boss.h"
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
    int sword_index;
    int level;
    int score;
    double level_time;
    Text gold_text;
    Text instructions_text;
    Text speed_text;
    Text damage_text;
    Text health_text;
    Font font;
    Sprite goldSprite;
    Texture goldTexture;
    Sprite heartSprite;
    Texture heartTexture;
public:
    Game(int height, int width, string name) {
        window = new RenderWindow(VideoMode(height,width), name);
        window->setFramerateLimit(144);
        // creates the characters that will be used in this game
        player = new Player(100,400, 10);
        boss = new Boss;
        enemies = new Enemy[50];

        if (!font.loadFromFile("C:/textures/font.ttf")){
            cout << "font not found" << endl;
        }
        // initialises the fonts that will be used to display stats
        gold_text.setFont(font);
        gold_text.setFillColor(sf::Color::Yellow);
        gold_text.setCharacterSize(20);

        health_text.setFont(font);
        health_text.setFillColor(sf::Color::Red);
        health_text.setCharacterSize(20);

        speed_text.setFont(font);
        speed_text.setFillColor(sf::Color::Cyan);
        speed_text.setCharacterSize(20);

        damage_text.setFont(font);
        damage_text.setFillColor(sf::Color::Magenta);
        damage_text.setCharacterSize(20);

        instructions_text.setFont(font);
        instructions_text.setFillColor(sf::Color::White);
        instructions_text.setCharacterSize(50);
        // initialising textures that the used by the game
        goldTexture.loadFromFile("C:/textures/gold.png");
        goldSprite.setTexture(goldTexture);
        goldSprite.scale(0.12f,0.12f);
        goldSprite.setPosition(20,770);

        heartTexture.loadFromFile("C:/textures/heart.png");
        heartSprite.setTexture(heartTexture);
        heartSprite.scale(0.1f,0.1f);
        heartSprite.setPosition(20,745);
        // initialises variables in constructor
        enemy_index = 0;
        score = 0;
        enemy_number = 0;
        sword_index = 0;
        level = 0;
    }

    void run() {
        // initialising background graphics
        backgroundTexture.loadFromFile("C:/textures/background.gif");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0,0);
        backgroundSprite.scale(1.44,1.44);

        string instruction = "Instructions: \n Press Space to shoot arrows";
        auto start = std::chrono::steady_clock::now(); // starts timer once game is launched

        while (window->isOpen())
        {
            Event event;
            while (window->pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == Event::Closed) {
                    window->close();
                }
                // moves player using Up/Down/Right/Left keys, and stops the player from moving off the screen
                // if level == 0, instructions are eing shown, so player cannot move
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
                    // uses KeyReleased so that these functions are only called once per key press
                    if (event.type == Event::KeyReleased) {
                        if (event.key.code == Keyboard::Space) {
                            player->use_arrow();
                        }
                        // upgrades player's damage if gold possessed is more than 500, and subtracts 500 gold from player
                        if (event.key.code == Keyboard::Z && player->get_gold() >= 500){
                            player->upgrade_damage();
                            player->change_gold(-500);
                        }
                        // upgrades player's speed if gold possessed is more than 350, and subtracts 500 gold from player
                        if (event.key.code == Keyboard::U && player->get_gold() >= 350){
                            player->upgrade_speed();
                            player->change_gold(-350);
                        }
                    }
                    // reloads player's arrows when key R is pressed and the player has no arrows left
                    if (Keyboard::isKeyPressed(Keyboard::R) && player->no_arrows_left() == 1) {
                        player->reload();
                    }
                }
            }
            // when player presses L when the level is 0
            if (Keyboard::isKeyPressed(Keyboard::L) && level == 0) {
                level++; // increments level to 1 so that the game can start
                auto inst = std::chrono::steady_clock::now(); // reads the time when this happens
                std::chrono::duration<double> time_to_start = inst - start; // calculates how much time it took for the player to start the game from when the game was launched
                level_time = time_to_start.count(); // puts the time_to_start into variable level_time
            }
            // calculates how much time has passed since game launced
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            // if level == 0, displays instructions on the screen
            if (level == 0) {
                instructions_text.setPosition(50,100);
                instructions_text.setString(instruction);
                window->draw(instructions_text);
            }
            // if level == 1 (game being played), spawns enemies
            if (level == 1) {
                if (enemy_index < 10) { // wave 1, spawns 10 enemies, at intervals of 1 second
                    if (elapsed_seconds.count() - level_time > enemy_index && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 2, 1, 0.5f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - level_time > 25 && enemy_index < 30){ // wave 2, spawns 20 enemies, starts 25 seconds after player moves off instruction screen
                    if (elapsed_seconds.count() - level_time > enemy_index + 15 && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 5, 2, 0.75f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - level_time > 60 && enemy_index < 50){ // wave 3, spawns 20 enemies, starts 60 seconds after player moves off instruction screen
                    if (elapsed_seconds.count() - level_time > enemy_index + 30 && !enemies[enemy_index].is_alive()) {
                        enemies[enemy_index].activate_enemy(Vector2f(1000, rand() % 550 + 100), 8, 3, 0.9f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - level_time >= 80 && enemy_index == 50) {
                    if (!boss->is_alive()) {  // boss spawn 80 seconds after player moves off instruction screen
                        boss->activate_enemy(Vector2f(800, 300), 200, 3, 0.3f);
                        enemy_index++;
                    }
                }
                if (elapsed_seconds.count() - level_time <= 80 + 0.3 * (sword_index) && elapsed_seconds.count() >= 80 + 0.3 * (sword_index - 0.5)) {
                    // makes boss throw a sword
                    boss->use_sword();
                    sword_index++;
                    cout << sword_index << endl;
                }
                for (int i = 0; i < 50; i++) {
                    if (enemies[i].is_alive()) {
                        if (player->successful_hit(enemies[i].get_position())) { // checks if player's arrow hits a enemy
                            enemies[i].take_damage(player->get_damage()); // enemy takes damage equal to the player's damage stat
                            if (enemies[i].get_health() <= 0) { // if enemy's health reaches 0:
                                enemies[i].die(); // enemy dies
                                player->change_gold(100); // player gets 100 gold
                                score++; // score incremented
                                enemy_number++;
                            }
                        }
                        if (enemies[i].get_position().x <= 0) { // if enemy gets to the far left of the screen
                            enemies[i].die(); // enemy dies
                            player->take_damage(enemies[i].get_damage()); // player takes damage equivalent to enemy's damage stat
                            enemy_number++;
                        }
                        if (player->hit_by_enemy(enemies[i].get_position())) { // if enemy hits player
                            enemies[i].die(); // enemy dies
                            player->take_damage(enemies[i].get_damage()); // player takes damage equivalent to enemy's damage stat
                            player->change_gold(50); // enemy gets 50 gold
                            enemy_number++;
                        }
                        if (player->get_health() <= 0) {
                            //cout << "player die" << endl;
                        }
                    }
                    if (boss->is_alive()) {
                        if (player->successful_hit(Vector2f(boss->get_position().x, boss->get_position().y + 60))) { // if player's arrow hits the boss
                            boss->take_damage(boss->get_damage()); // boss takes damage equal to the player's damage stat
                            if (boss->get_health() <= 0) { // when boss's health gets to 0:
                                boss->die(); // boss dies
                                player->change_gold(10000); // player gets gold
                                score = score + 20; // + 20 score
                                enemy_number++;
                            }
                        }
                        if (boss->successful_hit(player->get_position())){ // if boss's sword hits player:
                            player->take_damage(boss->get_damage()); // player takes damage equal to boss's damage stat
                        }
                        if (boss->get_position().x <= 0) { // if boss gets to the end of screen:
                            boss->die(); // boss dies
                            player->take_damage(boss->get_damage()); // player takes damage
                            enemy_number++;
                        }
                        if (player->hit_by_enemy(boss->get_position())) { // if boss hits enemy:
                            boss->die(); // boss dies
                            player->take_damage(boss->get_damage()); // player takes damage
                            enemy_number++;
                        }
                        if (player->get_health() <= 0) {
                            //cout << "player die" << endl;
                        }
                    }

                }
            }
            window->clear();
            // setting strings to wanted values
            string gold_display = to_string(player->get_gold());
            string health_display = to_string(player->get_health());
            string speed_display = "Speed: " + to_string(int(player->get_speed())) + " Cost to Upgrade: 350  Upgrade:U";
            string damage_display = "Damage: " + to_string(int(player->get_damage())) + " Cost to Upgrade: 500  Upgrade:Z";
            // setting the position and contents of the text
            speed_text.setPosition(120,770);
            speed_text.setString(speed_display);
            health_text.setPosition(50, 745);
            health_text.setString(health_display);
            damage_text.setPosition(108,745);
            damage_text.setString(damage_display);
            gold_text.setPosition(50,770);
            gold_text.setString(gold_display);
            // draws the objects needed to the window
            window->draw(backgroundSprite);
            player->draw(window);
            for (int i = 0; i < 50; i++) { // draws 50 enemies, but only when alive
                if (enemies[i].is_alive()) {
                    enemies[i].draw(window);
                }
            }
            if (boss->is_alive()){ // draws boss when alive
                boss->draw(window);
            }
            window->draw(gold_text);
            window->draw(speed_text);
            window->draw(damage_text);
            window->draw(health_text);
            window->draw(goldSprite);
            window->draw(heartSprite);
            window->display();
        }
    }
    ~Game() {
        // deletes the memory stored to the heap when game goes out of scope
        delete window;
        delete player;
        delete[] enemies;
        delete boss;
    };
};
