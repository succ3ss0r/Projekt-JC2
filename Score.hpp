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
    int score = 0;
private:
    std::ostringstream ssScore;
    sf::Font openSans;
};


