#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Star.hpp"

class Engine {
public:
    void initializeWindow();
    void initializeBackground();
    void initializeBattleShip();
    void initializeEnemies();
    void catchEvent(sf::RenderWindow window, sf::Event event);
    void starUpdate(sf::RenderWindow window, std::vector<Star> star);
    void battleShipUpdate(sf::RenderWindow window, SpaceShip battleShip);
    void enemiesUpdate(sf::RenderWindow window, std::vector<Enemy> enemies);
    void windowUpdate(sf::RenderWindow window);
    bool cancelWindow(sf::RenderWindow window, sf::Event event);
};
