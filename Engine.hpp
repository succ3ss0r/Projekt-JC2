#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Background.hpp"
#include "Score.hpp"
#include "Menu.hpp"
#include "Shot.hpp"
#include "Health.hpp"

class Engine {
public:
    Engine(unsigned int w_Width, unsigned int w_Height, std::string title);
    Engine() = delete;
    ~Engine();

    short option = -1; // zmienna wykorzystywana w metodzie gameMenu() do okreœlenia wyboru gracza

    void game(); // g³ówna pêtla gry
    void gameMenu(); // pêtla menu
private:
    unsigned int w_Width, w_Height;
    sf::RenderWindow *window;
    std::vector<Background> background;
    SpaceShip *battleShip;
    std::vector<Enemy> enemies;
    std::vector<Shot> shot;
    sf::Event event;
    Score *score;
    Menu *oMenu;
    Health *health;
};


