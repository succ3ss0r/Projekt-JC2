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
    int o_health;
private:
    std::ostringstream ssHealth;
    sf::Font openSans;
};


