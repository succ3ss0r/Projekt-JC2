#include <SFML/Graphics.hpp>
#include <sstream>

class Score {
public:
    Score(float t_Position, float t_Size);
    Score() = delete;
    ~Score() = default;

    void update();
    void increment(int pluss);
    int print();
    sf::Text playerScore;
private:
    std::ostringstream ssScore;
    int score = 0;
    sf::Font openSans;
};

