#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Menu.h"

MainMenu::MainMenu(int height, int width){
    if(!font.loadFromFile("C:/Users/Michael Lee/Downloads/gameplay/Gameplay.ttf")){
        cout << "No font is here" << endl;
    }
    Menu[0].setFont(font);
    Menu[0].setFillColor(Color::White);
    Menu[0].setString("Play");
    Menu[0].setCharacterSize(50);
    Menu[0].setPosition(Vector2f(200,200));

    Menu[1].setFont(font);
    Menu[1].setFillColor(Color::White);
    Menu[1].setString("Instructions");
    Menu[1].setCharacterSize(50);
    Menu[1].setPosition(Vector2f(200,300));

    Menu[2].setFont(font);
    Menu[2].setFillColor(Color::White);
    Menu[2].setString("Controls");
    Menu[2].setCharacterSize(50);
    Menu[2].setPosition(Vector2f(200,400));

    Menu[3].setFont(font);
    Menu[3].setFillColor(Color::White);
    Menu[3].setString("Exit");
    Menu[3].setCharacterSize(50);
    Menu[3].setPosition(Vector2f(200,500));

    MainMenuSelected = -1;

}

void MainMenu::draw(RenderWindow& window){
    for (int i = 0; i < 4; ++i){
        window.draw(Menu[i]);
    }
}

void MainMenu::MoveUp(){
    cout << "Up: " << MainMenuSelected << endl;
    if (MainMenuSelected >= 0){
        Menu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;
        if (MainMenuSelected == -1){
            MainMenuSelected = 2;
        }
        Menu[MainMenuSelected].setFillColor(Color::Blue);
    } else {
        MainMenuSelected++;
    }
}

void MainMenu::MoveDown(){
    cout << "Down" << MainMenuSelected << endl;
    if (MainMenuSelected <= 3 && MainMenuSelected >= -1){
        Menu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected++;
        if (MainMenuSelected == 4){
            MainMenuSelected = 0;
        }
        Menu[MainMenuSelected].setFillColor(Color::Blue);
    } else {
        MainMenuSelected = 0;
    }

}

MainMenu::~MainMenu(){

}
