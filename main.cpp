#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "cstdlib"
#include "vector"

#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Star.hpp"

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 600
#endif

#define NUMBER_OF_STARS 50

int main()
{
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invaders by Serwicki & Siwon (BETA)" );
    window.setFramerateLimit(60);
    sf::Event event;
    int enemyX{ 10 }, enemyY{ 4 }, enemyWidth{ 40 }, enemyHeight{ 40 };

    SpaceShip battleShip(SCREEN_WIDTH/2-SHIP_WIDTH/2, SCREEN_HEIGHT-60);

    std::vector<Enemy> enemies;
    for(int i = 0; i < enemyY; i++)
    {
        for(int j = 0; j < enemyX; j++)
        {
            enemies.emplace_back((j + 3.5) * (enemyWidth + 10), (i + 1) * (enemyHeight + 10), enemyWidth, enemyHeight);
        }
    }

    std::vector<Star> star;   //  Tworzenie obiektów gwiazd
    for(int i = 0; i < NUMBER_OF_STARS; i++)
    {
        star.push_back(Star(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT));
    }

    while(true)
    {
        window.pollEvent(event);
        window.clear(sf::Color::Black);

        if(event.type == sf::Event::Closed){
            window.close();
            break;
        }

        battleShip.update();

        for(int i = 0; i < NUMBER_OF_STARS; ++i)
        {
            star[i].update();

            if(star[i].getPosition().y > SCREEN_HEIGHT)
                star[i].setPosition(rand()%SCREEN_WIDTH, 0);

            window.draw(star[i]);
        }

//        for(auto& enemy : enemies) if(collisionTest(enemy)) break;
//
//        auto iterator = remove_if(begin(enemies), end(enemies), [](Enemy& enemy){ return enemy.isDestroyed(); });
//        enemies.erase(iterator, end(enemies));

        window.draw(battleShip);

        for(auto& enemy : enemies)
            window.draw(enemy);

        window.display();
    }
}
