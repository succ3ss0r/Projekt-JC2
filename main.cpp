/*********************************************
********* Serwicki Jakub, Siwoñ Pawe³ ********
***** PROJEKT Z PODSTAW PROGRAMOWANIA C2 *****
*************** SPACE INVADERS ***************
******* POLITECHNIKA ŒWIÊTOKRZYSKA 2017 ******
*********************************************/

#include "Engine.hpp"

int main()
{
    Engine engine(800, 600, "Space Invaders by Serwicki & Siwon BETA"); // utworzenie obiektu silnika gry

    while(true) {
        if(engine.option == -3)
            engine.leaderBoard();
        if(engine.option == -2)
            engine.lose();
        if(engine.option == -1)
            engine.gameMenu(); // wywolanie metody silnika w ktorej jest petla menu gry
        // option to zmienna w klasie Engine odpowiedzialna za wskazanie wyboru usera w menu
        if(engine.option == 0)
            engine.game();
        if(engine.option == 1)
            engine.leaderBoard();
        if(engine.option == 2)
            return 0;
    }
}
