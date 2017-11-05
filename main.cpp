/*********************************************
********* Serwicki Jakub, Siwoń Paweł ********
***** PROJEKT Z PODSTAW PROGRAMOWANIA C2 *****
*************** SPACE INVADERS ***************
******* POLITECHNIKA ŚWIĘTOKRZYSKA 2017 ******
*********************************************/

#include "Engine.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    Engine engine(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders by Serwicki & Siwon BETA");
    engine.loop();
}

//        for(auto& enemy : enemies) if(collisionTest(enemy)) break;
//
//        auto iterator = remove_if(begin(enemies), end(enemies), [](Enemy& enemy){ return enemy.isDestroyed(); });
//        enemies.erase(iterator, end(enemies));
