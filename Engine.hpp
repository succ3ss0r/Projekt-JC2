#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Star.hpp"
#include "Score.hpp"
#include "Menu.hpp"

class Engine {
public:
    Engine(unsigned int w_Width, unsigned int w_Height, std::string title);
    ~Engine();

    short option = -1;

    void game();
    void eMenu();
private:
    unsigned int w_Width, w_Height;
    sf::RenderWindow *window;
    std::vector<Star> star;
    SpaceShip *battleShip;
    std::vector<Enemy> enemies;
    std::vector<Enemy>::iterator it;
    sf::Event event;
    Score *score;
    Menu *oMenu;
};
