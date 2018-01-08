#include "cstdlib"
#include "vector"
#include "Engine.hpp"
#include "iostream"

Engine::Engine(unsigned int w_Width, unsigned int w_Height, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(w_Width, w_Height), title); //  Tworzenie okna
    window->setFramerateLimit(60); // zmiana limitu klatek
    this->w_Width = w_Width;  //  Przechwytywanie rozmiaru okna do obiektu
    this->w_Height = w_Height;

    oMenu = new Menu(window->getSize().x, window->getSize().y); // utworzenie obiektu klasy Menu

    score = new Score(10.f, 30.f); // utworzenie obiektu klasy Score
    health = new Health(200.f, 10.f, 30.f);

    battleShip = new SpaceShip(w_Width, w_Height, 30, 50);  //  Stworzenie obiektu klasy SpaceShip

    for(int i = 0; i < w_Width * 0.1; i++) { //  Tworzenie obiektów klasy Background
        background.push_back(Background(rand()%w_Width, rand() % w_Height));
    }
}
Engine::~Engine() {
    delete battleShip;
    delete score;
    delete health;
    delete oMenu;
    delete window;
}
void Engine::gameMenu() {
    oMenu->playMenuMusic(); // metoda odpowiedzialna za odtwarzanie dzwieku
    while(true && this->option == -1) {
        while(window->pollEvent(event) && this->option == -1) {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna przez 'X' lub Esc
                window->close();
                return;
            }
            if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Up)
                    oMenu->moveUp();
                if(event.key.code == sf::Keyboard::Down)
                    oMenu->moveDown();
                if(event.key.code == sf::Keyboard::Return) {
                    this->option = oMenu->getPressedItem();
                    break;
                }
            }
        }
        if(this->option == 2)
                window->close();

        window->clear();
        oMenu->drawMenuList(*window);
        window->draw(*oMenu);
        window->display();
    }
}
void Engine::game() {
    unsigned int enemyNum = 5, enemyWidth = 40, enemyHeight = 40, movementType = 1, createdEnemies = 0, destroyedEnemies = 0, forGuard = 0;  //  Zmienne wykorzystywane podczas tworzenia wrogich jednostek
    while(true) {
        window->clear(sf::Color::Black);  //  czyszczenie okna kolor czarny
        window->pollEvent(event);  //  przechwytywanie zdarzen

        if(enemies.size() != 0) {
            for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
                it->setTexture();
                if(it->getPosition().x > 830) {
                    health->decrement(10);
                    enemies.erase(it);
                    destroyedEnemies++;
                    break;
                }
            }
        }

        movementType = (destroyedEnemies / enemyNum) % 2 + 1;

        if(createdEnemies != enemyNum - 1)
            if(enemies.size() < enemyNum) {
                if(enemies.size() == 0)
                    enemies.emplace_back(-enemyWidth, -enemyHeight, enemyWidth, enemyHeight, movementType);
                else if(enemies[enemies.size() - 1].getPosition().x > 100) {
                    enemies.emplace_back(-enemyWidth, -enemyHeight, enemyWidth, enemyHeight, movementType);
                    createdEnemies++;
                }
            }

        if(enemies.size() != 0)
            for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {  //  aktualizacja wrogich jednostek
                for(std::vector<Shot>::iterator sit = shot.begin(); sit != shot.end(); ++sit) {
                    if(sit->getPosition().y - 5 >= it->getPosition().y - 20 && sit->getPosition().y - 5 <= it->getPosition().y + 20 && sit->getPosition().x - 2 >= it->getPosition().x - 20 && sit->getPosition().x + 2 <= it->getPosition().x +20) {
                        score->increment(10);
                        enemies.erase(it);
                        destroyedEnemies++;
                        forGuard = 1;
                        break;
                    }
                }
                if(forGuard == 1) {
                    forGuard = 0;
                    break;
                }
                it->update();
                window->draw(*it);
            }

        if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna przez 'X' lub Esc
            window->close();
            return;
        }

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Space) {
                if(shot.size() != 0)
                    if(shot[shot.size() - 1].getPosition().y >= 400)
                        continue;

                shot.push_back(Shot(4.f, 10.f));
                if(shot.size() > 0)
                    shot[shot.size() - 1].setPosition(battleShip->getPosition().x, battleShip->getPosition().y);
            }
        }

        for(unsigned short i = 0; i < shot.size(); ++i) {
            shot[i].update();
            window->draw(shot[i]);
        }

        for(unsigned int i = 0; i < background.size(); ++i) {  //  aktualizacja tla
            background[i].update();
            if(background[i].getPosition().y > w_Height)
                background[i].setPosition(rand()%w_Width, 0);

            window->draw(background[i]);
        }

        battleShip->update();  //  aktualizacja oraz rysowanie statku gracza
        window->draw(*battleShip);

        if(destroyedEnemies == enemyNum) {
            createdEnemies = 0;
        }

        score->update();
        window->draw(score->playerScore);

        health->update();
        window->draw(health->playerHealth);

        window->display();
    }
}

