/*********************************************
********* Serwicki Jakub, Siwoń Paweł ********
***** PROJEKT Z PODSTAW PROGRAMOWANIA C2 *****
*************** SPACE INVADERS ***************
******* POLITECHNIKA ŚWIĘTOKRZYSKA 2017 ******
*********************************************/

#include "Engine.hpp"

int main()
{
    Engine engine;
    engine.initializeWindow();
    sf::Event event;
    engine.initializeBackground();
    engine.initializeBattleShip();
    engine.initializeEnemies();

    while(true) {
        engine.catchEvent(window, event);
        if(engine.cancelWindow(window, event)) break;
        window.clear(sf::Color::Black);

        engine.starUpdate(window, star);
        engine.battleShipUpdate(window, battleShip);
        engine.enemiesUpdate(window, enemies);
        engine.windowUpdate(window);
    }
}

//        for(auto& enemy : enemies) if(collisionTest(enemy)) break;
//
//        auto iterator = remove_if(begin(enemies), end(enemies), [](Enemy& enemy){ return enemy.isDestroyed(); });
//        enemies.erase(iterator, end(enemies));
