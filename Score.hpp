#include "SFML/Graphics.hpp"
#include "sstream"

class Score {
public:
    Score(float o_Position, float o_Size);
    Score() = delete;
    ~Score() = default;

    void update();
    void increment(int pluss);
    sf::Text playerScore;
private:
    std::ostringstream ssScore;
    int score = 0;
    sf::Font openSans;
};

