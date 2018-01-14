#include "Engine.hpp"
// option to zmienna w klasie Engine odpowiedzialna za wskazanie wyboru usera w menu

int main()
{
    Engine engine(800, 600, "Space Invaders by Serwicki & Siwon BETA"); // utworzenie obiektu silnika gry

    while(engine.window->isOpen()) {
        if(engine.option == -3)
            engine.leaderBoard();
        if(engine.option == -2)
            engine.lose();
        if(engine.option == -1)
            engine.gameMenu();
        if(engine.option == 0)
            engine.game();
        if(engine.option == 1)
            engine.getNickname();
        if(engine.option == 2)
            return 0;
        if(engine.option == -10)
            return -1;
    }

    return 0;
}
