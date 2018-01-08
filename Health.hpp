#include "SFML/Graphics.hpp"
#include "sstream"

class Health {
public:
    Health(float o_posX, float o_posY, float o_strSize);
    Health() = delete;
    ~Health() = default;

    void update();
    void increment(int pluss);
    void decrement(int minuss);
    sf::Text playerHealth;
private:
    std::ostringstream ssHealth;
    int health = 1000;
    sf::Font openSans;
};


