#include "cstdlib"
#include "cstdio"
#include "iostream"
#include "vector"
#include "fstream"
#include "Engine.hpp"

Engine::Engine(unsigned int w_Width, unsigned int w_Height, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(w_Width, w_Height), title); //  Tworzenie okna
    window->setFramerateLimit(60); // zmiana limitu klatek
    this->w_Width = w_Width;  //  Przechwytywanie rozmiaru okna do obiektu
    this->w_Height = w_Height;

    oMenu = new Menu(window->getSize().x, window->getSize().y); // utworzenie obiektu klasy Menu
    oMenu->playMenuMusic(); // metoda odpowiedzialna za odtwarzanie dzwieku
    oLose = new Lose(window->getSize().x, window->getSize().y);
    oHighscore = new Highscore(window->getSize().x, window->getSize().y);
    oNick = new GetNickname(window->getSize().x, window->getSize().y);

    score = new Score(10.f, 30.f); // utworzenie obiektu klasy Score
    health = new Health(200.f, 10.f, 30.f);

    battleShip = new SpaceShip(w_Width, w_Height, 30, 50);  //  Stworzenie obiektu klasy SpaceShip

    for(int i = 0; i < w_Width * 0.1; i++) { //  Tworzenie obiekt�w klasy Background
        background.push_back(Background(rand()%w_Width, rand() % w_Height));
    }
}

Engine::~Engine() {
    delete battleShip;
    delete score;
    delete health;
    delete oLose;
    delete oMenu;
    delete oHighscore;
    delete oNick;
    delete window;
}

void Engine::getNickname() {
    if(oNick->fileExists("highscores")) {
        health->o_health = 100;
        score->score = 0;
        while(this->option == 1 && window->isOpen()) {
            oNick->unicode = 0;
            while(window->pollEvent(event)) {
                 if(event.type == sf::Event::Closed) {
                    window->close();
                    return;
                }
                if((oHighscore->name[this->which] = oNick->str).size() <= oNick->maxLength) {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        std::string tmpData[6];
                        std::ifstream ofile("highscores");
                        for(int i = 0; i < 6; ++i){
                            if(i >= 0 && i <= 2) {
                                getline(ofile, oHighscore->score[i]);
                                tmpData[i] = oHighscore->score[i];
                            } else {
                                getline(ofile, oHighscore->name[i-3]);
                                tmpData[i] = oHighscore->name[i-3];
                            }
                        }
                        ofile.close();
                        ofile.clear();
                        char tmp[4];
                        int tmpScore = this->eScore;
                        sprintf(tmp, "%d", tmpScore);
                        std::ofstream ifile("highscores", std::ofstream::trunc);
                        ifile.clear();
                        if(this->which == 0) {
                            ifile << tmp << "\n";
                            ifile << tmpData[0] << "\n";
                            ifile << tmpData[1] << "\n";
                            oHighscore->name[this->which] = oNick->str;
                            ifile << oHighscore->name[0] << "\n";
                            ifile << tmpData[3] << "\n";
                            ifile << tmpData[4] << "\n";
                        }
                        if(this->which == 1) {
                            fflush(stdin);
                            fflush(stdin);
                            ifile << tmpData[0] << "\n";
                            ifile << tmp << "\n";
                            ifile << tmpData[1] << "\n";
                            ifile << tmpData[3] << "\n";
                            oHighscore->name[this->which] = oNick->str;
                            ifile << oHighscore->name[1] << "\n";
                            ifile << tmpData[4] << "\n";
                        }
                        if(this->which == 2){
                            ifile << tmpData[0] << "\n";
                            ifile << tmpData[1] << "\n";
                            ifile << tmp << "\n";
                            ifile << tmpData[3] << "\n";
                            ifile << tmpData[4] << "\n";
                            oHighscore->name[this->which] = oNick->str;
                            ifile << oHighscore->name[2] << "\n";
                        }

                        ifile.close();

                        this->option = -1;
                        return;
                    }
                }
                if(event.type == sf::Event::TextEntered) {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                        oNick->name += static_cast<char>(oNick->unicode);
                        oNick->name.erase(oNick->name.size()-1, 1);
                        oNick->text[2].setString(oNick->name);
                    }

                    if((event.text.unicode < 58 && event.text.unicode > 47) || (event.text.unicode < 91 && event.text.unicode > 61) || (event.text.unicode < 123 && event.text.unicode > 96))
                        oNick->unicode = event.text.unicode;
                }
            }
            if(oNick->unicode) {
                oNick->str = oNick->text[2].getString();
                oNick->str += oNick->unicode;
                oNick->text[2].setString(oNick->str);
            }
            window->clear();
            oNick->printText(*window);
            window->draw(*oNick);
            oNick->setTextToPrint();
            window->display();
        }
    } else {
        this->option = -10;
        std::cout << "Plik 'highscores' nie istnieje\n";
    }
}

void Engine::gameMenu() {
    while(window->isOpen()) {
        if(!oNick->fileExists("highscores")) {
            std::ofstream file("highscores");
            file << 0 << "\n";
            file << 0 << "\n";
            file << 0 << "\n";
            file << "Unknown\n";
            file << "Unknown\n";
            file << "Unknown\n";
            file.close();
        } else {
            while(this->option == -1) {
                while(window->pollEvent(event)) {
                    if(event.type == sf::Event::Closed) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna przez 'X' lub Esc
                        oMenu->stopMenuMusic();
                        oLose->stopLoseMusic();
                        this->option = 2;
                        return;
                    }
                    if(event.type == sf::Event::KeyReleased) {
                        if(event.key.code == sf::Keyboard::Up)
                            oMenu->moveUp();
                        if(event.key.code == sf::Keyboard::Down)
                            oMenu->moveDown();
                        if(event.key.code == sf::Keyboard::Return) {
                            this->option = oMenu->getPressedItem();
                            if(this->option == 1)  {
                                oLose->stopLoseMusic();
                                this->option = -3;
                                return;
                            }
                            return;
                        }
                    }
                }
                window->clear();
                oMenu->drawMenuList(*window);
                window->draw(*oMenu);
                window->display();
            }
        }
    }
}

void Engine::leaderBoard() {
    if(oNick->fileExists("highscores")) {
        std::ifstream file("highscores");
        for(int i = 0; i < 6; ++i){
            if(i >= 0 && i <= 2)
                getline(file, oHighscore->score[i]);
            else
                getline(file, oHighscore->name[i-3]);
        }
        file.close();
        window->clear();
        oHighscore->setHighscoreText();
        oHighscore->printLeaderBoard(*window);
        window->draw(*oHighscore);
        window->display();
        while(this->option == -3 && window->isOpen()) {
            while(window->pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    window->close();
                    return;
                }
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Space) {
                        this->option = -1;
                        return;
                    }
                }
            }
        }
    } else {
        this->option = -10;
        std::cout << "Plik 'highscores' nie istnieje\n";
    }
}

void Engine::lose() {
    oLose->playLoseMusic(); // metoda odpowiedzialna za odtwarzanie dzwieku
    while(this->option == -2 && window->isOpen()) {
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna przez 'X' lub Esc
                window->close();
                oLose->stopLoseMusic();
                oMenu->stopMenuMusic();
                this->option = 2;
                return;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                this->option = -1;
                return;
            }
            if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Up)
                    oLose->moveUp();
                if(event.key.code == sf::Keyboard::Down)
                    oLose->moveDown();
                if(event.key.code == sf::Keyboard::Return) {
                    this->option = oLose->getPressedItem();
                    health->o_health = 100;
                    score->score = 0;
                    if(this->option == 1)
                        this->option = -1;
                    if(this->option == 2) {
                        window->close();
                        this->option = 2;
                        return;
                    }
                    break;
                }
            }
        }

        window->clear();
        oLose->drawLoseOption(*window);
        window->draw(*oLose);
        window->display();
    }
}

void Engine::game() {
    if(oNick->fileExists("highscores")) {
        std::vector<Enemy> enemies;
        std::vector<Shot> shot;
        shot.emplace_back(Shot(4.f, 10.f));
        shot[0].setPosition(-100, -100);
        unsigned int enemyNum = 8, enemyWidth = 40, enemyHeight = 40, movementType = 1, createdEnemies = 0, destroyedEnemies = 0, forGuard = 0;  //  Zmienne wykorzystywane podczas tworzenia wrogich jednostek
        // forGuard to zmienna ktora jest potrzebna do wyjscia z zagniezdzonych petli for
        while(this->option == 0 && window->isOpen()) {
            window->clear(sf::Color::Black);  //  czyszczenie okna kolor czarny
            window->pollEvent(event);  //  przechwytywanie zdarzen

            for(unsigned int i = 0; i < background.size(); ++i) {  //  aktualizacja tla
                background[i].setMoveVelocity();
                if(background[i].getPosition().y > w_Height)
                    background[i].setPosition(rand()%w_Width, 0);

                window->draw(background[i]);
            }

            if(health->o_health <= 0) {
                int e_scores[3];
                std::ifstream file("highscores");
                for(int i = 0; i < 6; ++i){
                    if(i >= 0 && i <= 2) {
                        getline(file, oHighscore->score[i]);
                        e_scores[i] = atoi(oHighscore->score[i].c_str());
                    } else
                        getline(file, oHighscore->name[i-3]);
                }
                file.close();
                if(score->score >= e_scores[2] && score->score < e_scores[1] && score->score < e_scores[0]) {
                    this->eScore = score->score;
                    this->which = 2;
                    this->option = 1;
                    return;
                } else if(score->score >= e_scores[2] && score->score >= e_scores[1] && score->score < e_scores[0]) {
                    this->eScore = score->score;
                    this->which = 1;
                    this->option = 1;
                    return;
                } else if(score->score >= e_scores[2] && score->score >= e_scores[1] && score->score >= e_scores[0]) {
                    this->eScore = score->score;
                    this->which = 0;
                    this->option = 1;
                    return;
                } else {
                    this->option = -2;
                    return;
                }
            }

            if(event.type == sf::Event::Closed) {  //  Sprawdzanie czy nie nastapilo zamkniecie okna przez 'X' lub Esc
                window->close();
                return;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                this->option = -1;
                health->o_health = 100;
                score->score = 0;
                return;
            }

            if(enemies.size() != 0) {
                for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
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

            if(enemies.size() != 0) {
                for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {  //  aktualizacja wrogich jednostek
                    it->setTexture();
                    if(shot.size() != 0) {
                        for(std::vector<Shot>::iterator it2 = shot.begin(); it2 != shot.end(); ++it2) {
                            if(it2->getPosition().y - 5 >= it->getPosition().y - 20 && it2->getPosition().y - 5 <= it->getPosition().y + 20 && it2->getPosition().x - 2 >= it->getPosition().x - 20 && it2->getPosition().x + 2 <= it->getPosition().x +20) {
                                score->increment(10);
                                enemies.erase(it);
                                it2->setPosition(it2->getPosition().x,-10);
                                health->increment(1);
                                destroyedEnemies++;
                                forGuard = 1;
                                break;
                            }
                        }
                    }
                    if(forGuard == 1) {
                        forGuard = 0;
                        break;
                    }
                    it->update();
                    window->draw(*it);
                }
            }

            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space)
                    if(shot.size() != 0)
                        if(shot[shot.size() - 1].getPosition().y <= 300) {
                            shot.emplace_back(4.f, 10.f);
                            if(shot.size() > 0)
                                shot[shot.size() - 1].setPosition(battleShip->getPosition().x, battleShip->getPosition().y);
                        }
            }

            for(unsigned short i = 0; i < shot.size(); ++i) {
                shot[i].setVelocity();
                window->draw(shot[i]);
            }

            battleShip->update();  //  aktualizacja oraz rysowanie statku gracza
            window->draw(*battleShip);

            if(destroyedEnemies == enemyNum) {
                createdEnemies = 0;
            }

            score->textUpdate();
            window->draw(score->playerScore);

            health->textUpdate();
            window->draw(health->playerHealth);

            window->display();
        }
    } else {
        this->option = -10;
        std::cout << "Plik 'highscores' nie istnieje\n";
    }
}
