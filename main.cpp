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

    engine.gameMenu(); // wywolanie metody silnika w ktorej jest petla menu gry
    // option to zmienna w klasie Engine odpowiedzialna za wskazanie wyboru usera w menu
    if(engine.option == 0)
        engine.game();

    engine.~Engine();
}
