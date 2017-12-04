#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Background.hpp"
#include "Score.hpp"
#include "Menu.hpp"
#include "Shot.hpp"

class Engine {
public:
    Engine(unsigned int w_Width, unsigned int w_Height, std::string title);
    ~Engine();

    short option = -1;

    void game();
    void gameMenu();
private:
    unsigned int w_Width, w_Height;
    sf::RenderWindow *window;
    std::vector<Background> background;
    SpaceShip *battleShip;
    std::vector<Enemy> enemies;
    std::vector<Enemy>::iterator it;
    std::vector<Shot> shot;
    sf::Event event;
    Score *score;
    Menu *oMenu;
};


