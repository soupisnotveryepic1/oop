#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace sf;
int main()
{
    RenderWindow menu(VideoMode(800,800), "Project");
    MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

    while (menu.isOpen()){
        Event event;
        while (menu.pollEvent(event)){
            if(event.type == Event::Closed){
                menu.close();
            }
            if (event.type == Event::KeyReleased){
                if (event.key.code == Keyboard::Up){
                    mainMenu.MoveUp();
                    break;
                } else if (event.key.code == Keyboard::Down){
                    mainMenu.MoveDown();
                    break;
                } else if (event.key.code == Keyboard::Return){
                    RenderWindow play(VideoMode(800,800), "Game");
                    RenderWindow instructions(VideoMode(800,800), "Instructions");
                    RenderWindow controls(VideoMode(800,800), "Controls");
                    int x = mainMenu.MainMenuPressed();
                    cout << x << endl;
                    if (x == 0){
                        while (play.isOpen()){
                            Event playEvent;
                            while (play.pollEvent(playEvent)){
                                if (playEvent.type == Event::Closed){
                                    play.close();
                                } else if (playEvent.type == Event::KeyPressed){
                                    if (playEvent.key.code == Keyboard::Escape){
                                        play.close();
                                    }
                                }
                            }
                            instructions.close();
                            controls.close();
                            play.clear();
                            play.display();
                        }
                    }
                    if (x == 1){
                        while (instructions.isOpen()){
                            Event instEvent;
                            while (instructions.pollEvent(instEvent)){
                                if (instEvent.type == Event::Closed){
                                    instructions.close();
                                } else if (instEvent.type == Event::KeyPressed){
                                    if (instEvent.key.code == Keyboard::Escape){
                                        instructions.close();
                                    }
                                }
                            }
                            play.close();
                            controls.close();
                            instructions.clear();
                            instructions.display();
                        }
                    }
                    if (x == 2){
                        while (controls.isOpen()){
                            Event controlEvent;
                            while (instructions.pollEvent(controlEvent)){
                                if (controlEvent.type == Event::Closed){
                                    controls.close();
                                } else if (controlEvent.type == Event::KeyPressed){
                                    if (controlEvent.key.code == Keyboard::Escape){
                                        controls.close();
                                    }
                                }
                            }
                            play.close();
                            instructions.close();
                            controls.clear();
                            controls.display();
                        }
                    }
                    if (x == 3) {
                        cout << "Close menu" << endl;
                        menu.close();
                        break;
                    }
                }
            }
            menu.clear();
            mainMenu.draw(menu);
            menu.display();
        }
    }


    return 0;
}
