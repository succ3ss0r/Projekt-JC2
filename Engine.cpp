#include "cstdlib"
#include "vector"
#include "Engine.hpp"

Engine::Engine(unsigned int t_X, unsigned int t_Y, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(t_X, t_Y), title); //  Tworzenie okna
    window->setFramerateLimit(60);
    this->t_X = t_X;  //  Przechwytywanie rozmiaru okna do obiektu
    this->t_Y = t_Y;

    score = new Score(10.f, 30.f);

    battleShip = new SpaceShip(t_X, t_Y, 40, 50);  //  Stworzenie obiektu statku gracza

    for(int i = 0; i < t_X * 0.1; i++) { //  Tworzenie obiektów gwiazd
        star.push_back(Star(rand()%t_X, rand()%t_Y));
    }

    int enemyX{ 1 }, enemyY{ 1 }, enemyWidth{ 40 }, enemyHeight{ 40 };  //  Zmienne wykorzystywane podczas tworzenia wrogich jednostek
    for(int i = 0; i < enemyY; i++)  //  Tworzenie obiektów wrogich jednostek
    {
        for(int j = 0; j < enemyX; j++)
        {
            enemies.emplace_back(-enemyWidth, -enemyHeight, enemyWidth, enemyHeight, 2);
        }
    }
}
Engine::~Engine() {
    delete battleShip;
    delete score;
    delete window;
}
void Engine::loop() {
    while(true) {
        window->clear(sf::Color::Black);  //  czyszczenie okna kolor czarny
        window->pollEvent(event);  //  przechwytywanie zdarzen

        if(event.type == sf::Event::Closed)  //  Sprawdzanie czy nie nastapilo zamkniecie okna
            window->close();

        for(unsigned int i = 0; i < star.size(); ++i) {  //  aktualizacja tla
            star[i].update();
            if(star[i].getPosition().y > t_Y)
                star[i].setPosition(rand()%t_X, 0);

            window->draw(star[i]);
        }

        battleShip->update();  //  aktualizacja oraz rysowanie statku gracza
        window->draw(*battleShip);

        for(auto& enemy : enemies) {  //  aktualizacja wrogich jednostek
            enemy.update();
            window->draw(enemy);
        }

        score->increment(10);
        score->update();
        window->draw(score->playerScore);

        window->display();
    }
}
