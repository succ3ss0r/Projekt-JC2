#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Background.hpp"
#include "Score.hpp"
#include "Menu.hpp"
#include "Shot.hpp"
#include "Health.hpp"
#include "Lose.hpp"
#include "Highscore.hpp"
#include "GetNickname.hpp"

class Engine {
public:
    Engine(unsigned int w_Width, unsigned int w_Height, std::string title); // konstruktor
    Engine() = delete;  /*!< usuwa domyslny konstruktor*/
    ~Engine(); /*!< ustawia domyslny destruktor*/

    short option = -1; /*!< zmienna wykorzystywana w metodzie gameMenu() oraz lose() do okreslenia wyboru gracza*/

    void game(); // glówna petla gry
    void gameMenu(); // petla menu
    void lose(); // petla ekranu przegranej
    void leaderBoard(); // petla ekranu highscore
    void getNickname(); // petla ekranu do pobrania nazwy gracza aby wpisac go do leaderBoard
    sf::RenderWindow *window; /*!< okno programu*/
private:
    int which = -1; // zmienna do okreslenia ktory element powinien byc podmieniony wykorzystywana do GetNickname
    int eScore; // przechwytuje wynik, ten wynik zostanie wpisany do highscores
    unsigned int w_Width, w_Height; // szerokosc oraz wysokosc okna
    std::vector<Background> background; // vector obiektow background
    SpaceShip *battleShip; // wskaznik na obiekt battleship
    sf::Event event; // zmienna typu event do obslugi eventow
    Score *score; // wskaznik na obiekt score
    Menu *oMenu; // wskaznik na obiekt oMenu
    Lose *oLose; // wskaznik na obiekt oLose
    Health *health; // wskaznik na obiekt health
    Highscore *oHighscore; // wskaznik na obiekt oHighscore
    GetNickname *oNick; // wskaznik na obiekt oNcik
};


