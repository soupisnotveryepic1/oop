#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class MainMenu{

private:
    int MainMenuSelected;
    Font font;
    Text Menu[4];
public:
    MainMenu(int height, int width);
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MainMenuPressed(){
        cout << "returned: " << MainMenuSelected << endl;
        return MainMenuSelected;
    }
    ~MainMenu();
};




