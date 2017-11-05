#include "cstdlib"
#include "vector"
#include "Engine.hpp"

Engine::Engine(unsigned int t_X, unsigned int t_Y, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(t_X, t_Y), title);
    window->setFramerateLimit(60);
    this->t_X = t_X;
    this->t_Y = t_Y;

    battleShip = new SpaceShip(t_X, t_Y, 30, 50);

    for(int i = 0; i < t_X * 0.1; i++)
    {
        star.push_back(Star(rand()%t_X, rand()%t_Y));
    }

    int enemyX{ 10 }, enemyY{ 4 }, enemyWidth{ 40 }, enemyHeight{ 40 };
    for(int i = 0; i < enemyY; i++)
    {
        for(int j = 0; j < enemyX; j++)
        {
            enemies.emplace_back((j + 3.5) * (enemyWidth + 10), (i + 1) * (enemyHeight + 10), enemyWidth, enemyHeight);
        }
    }
}
Engine::~Engine() {
    delete window;
}
void Engine::loop() {
    while(true) {
        window->clear(sf::Color::Black);
        window->pollEvent(event);

        if(event.type == sf::Event::Closed)
            window->close();

        for(unsigned int i = 0; i < star.size(); ++i) {
            star[i].update();
            if(star[i].getPosition().y > t_Y)
                star[i].setPosition(rand()%t_X, 0);

            window->draw(star[i]);
        }

        battleShip->update();
        window->draw(*battleShip);

        for(auto& enemy : enemies)
            window->draw(enemy);

        window->display();
    }
}
