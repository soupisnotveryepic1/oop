#include "Game.h"

int main(){
    srand(time(NULL));
    Game main_game(800,800,"Project");
    main_game.run();
}
