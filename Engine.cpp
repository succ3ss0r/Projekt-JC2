#include "cstdlib"
#include "vector"
#include "Engine.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define NUMBER_OF_STARS 50

void Engine::initializeWindow() {
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invaders by Serwicki & Siwon (BETA)" );
    window.setFramerateLimit(60);
}
void Engine::initializeBackground() {
    std::vector<Star> star;
    for(int i = 0; i < NUMBER_OF_STARS; i++)
    {
        star.push_back(Star(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT));
    }
}
void Engine::initializeBattleShip() {
    SpaceShip battleShip(SCREEN_WIDTH/2-SHIP_WIDTH/2, SCREEN_HEIGHT-60);
}
void Engine::initializeEnemies() {
    int enemyX{ 10 }, enemyY{ 4 }, enemyWidth{ 40 }, enemyHeight{ 40 };
    std::vector<Enemy> enemies;
    for(int i = 0; i < enemyY; i++)
    {
        for(int j = 0; j < enemyX; j++)
        {
            enemies.emplace_back((j + 3.5) * (enemyWidth + 10), (i + 1) * (enemyHeight + 10), enemyWidth, enemyHeight);
        }
    }
}
void Engine::catchEvent(sf::RenderWindow window, sf::Event event) {
    window.pollEvent(event);
}
void Engine::starUpdate(sf::RenderWindow window, std::vector<Star> star) {
    for(int i = 0; i < NUMBER_OF_STARS; ++i)
        {
            star[i].update();

            if(star[i].getPosition().y > SCREEN_HEIGHT)
                star[i].setPosition(rand()%SCREEN_WIDTH, 0);

            window.draw(star[i]);
        }
}
void Engine::battleShipUpdate(sf::RenderWindow window, SpaceShip battleShip) {
    battleShip.update();
    window.draw(battleShip);
}
void Engine::enemiesUpdate(sf::RenderWindow window, std::vector<Enemy> enemies) {
    for(auto& enemy : enemies)
            window.draw(enemy);
}
void Engine::windowUpdate(sf::RenderWindow window) {
    window.display();
}
bool Engine::cancelWindow(sf::RenderWindow window, sf::Event event) {
    if(event.type == sf::Event::Closed){
        window.close();
        return true;
    } else return false;
}
