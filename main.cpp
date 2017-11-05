/*********************************************
********* Serwicki Jakub, Siwoń Paweł ********
***** PROJEKT Z PODSTAW PROGRAMOWANIA C2 *****
*************** SPACE INVADERS ***************
******* POLITECHNIKA ŚWIĘTOKRZYSKA 2017 ******
*********************************************/

#include "Engine.hpp"

int main()
{
    Engine engine(800, 600, "Space Invaders by Serwicki & Siwon BETA");

    engine.loop();
}
