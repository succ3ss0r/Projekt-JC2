#include "cstdlib"
#include "vector"
#include "Engine.hpp"

Engine::Engine(unsigned int w_Width, unsigned int w_Height, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(w_Width, w_Height), title); //  Tworzenie okna
    window->setFramerateLimit(60); // zmiana limitu klatek
    this->w_Width = w_Width;  //  Przechwytywanie rozmiaru okna do obiektu
    this->w_Height = w_Height;

    oMenu = new Menu(window->getSize().x, window->getSize().y); // utworzenie obiektu klasy Menu

    score = new Score(10.f, 30.f); // utworzenie obiektu klasy Score

    battleShip = new SpaceShip(w_Width, w_Height, 30, 50);  //  Stworzenie obiektu klasy SpaceShip

    for(int i = 0; i < w_Width * 0.1; i++) { //  Tworzenie obiektów klasy Background
        background.push_back(Background(rand()%w_Width, rand() % w_Height));
    }

    int enemyX{ 1 }, enemyY{ 1 }, enemyWidth{ 40 }, enemyHeight{ 40 };  //  Zmienne wykorzystywane podczas tworzenia wrogich jednostek
    for(int i = 0; i < enemyY; i++)  //  Tworzenie obiektów wrogich jednostek
    {
        for(int j = 0; j < enemyX; j++)
        {
            enemies.emplace_back(-enemyWidth, -enemyHeight, enemyWidth, enemyHeight, 1);
        }
    }
}
Engine::~Engine() {
    delete battleShip;
    delete score;
    delete oMenu;
    delete window;
}
void Engine::gameMenu() {
    oMenu->playMenuMusic(); // metoda odpowiedzialna za odtwarzanie dzwieku
    while(true && this->option == -1) {
        while(window->pollEvent(event) && this->option == -1) {
            if(event.type == sf::Event::Closed){
                    window->close();
                    return;
            }
            if(event.type == sf::Event::KeyReleased){
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
        oMenu->drawMenu(*window);
        window->draw(*oMenu);
        window->display();
    }
}
void Engine::game() {
    while(true) {
        window->clear(sf::Color::Black);  //  czyszczenie okna kolor czarny
        window->pollEvent(event);  //  przechwytywanie zdarzen

        if(event.type == sf::Event::Closed) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna
            window->close();
            return;
        }

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Space) {
                if(shot.size() != 0)
                    if(shot[shot.size() - 1].getPosition().y >= 400)
                        continue;

                Shot pocisk(4.f, 10.f);
                pocisk.setPosition(battleShip->getPosition().x, battleShip->getPosition().y);
                shot.push_back(pocisk);
            }
        }

        for(unsigned short i = 0; i < shot.size(); ++i) {
            shot[i].update();
//            if(shot[i].getPosition().y < -20)
//                shot.pop_back();
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

