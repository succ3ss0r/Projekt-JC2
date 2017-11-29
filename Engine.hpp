#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Star.hpp"
#include "Score.hpp"

class Engine {
public:
    Engine(unsigned int t_X, unsigned int t_Y, std::string title);
    ~Engine();
    void loop();
private:
    unsigned int t_X, t_Y;
    sf::RenderWindow *window;
    std::vector<Star> star;
    SpaceShip *battleShip;
    std::vector<Enemy> enemies;
    sf::Event event;
    Score *score;
};
