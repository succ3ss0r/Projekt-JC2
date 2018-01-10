#include "SFML/Graphics.hpp"
#include "sstream"

class Highscore : public sf::Drawable {
public:
    Highscore(float w_Width, float w_Height);
    Highscore() = delete;
    ~Highscore() = default;

    void printHighscores();
    void printLeaderBoard(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    void playMusic();
    void stopMusic();

    sf::Text playerScore[5];
    int score[3];
    std::string name[3];
private:
    std::ostringstream ssScore[5];
    sf::Font openSans;
    sf::RectangleShape shape;
    sf::Texture texture;
};
