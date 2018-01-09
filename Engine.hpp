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

class Engine {
public:
    Engine(unsigned int w_Width, unsigned int w_Height, std::string title);
    Engine() = delete;
    ~Engine();

    short option = -1; // zmienna wykorzystywana w metodzie gameMenu() oraz lose() do okreœlenia wyboru gracza

    void game(); // g³ówna pêtla gry
    void gameMenu(); // pêtla menu
    void lose();
private:
    unsigned int w_Width, w_Height;
    sf::RenderWindow *window;
    std::vector<Background> background;
    SpaceShip *battleShip;
    sf::Event event;
    Score *score;
    Menu *oMenu;
    Lose *oLose;
    Health *health;
};


