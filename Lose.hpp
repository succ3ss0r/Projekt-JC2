#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Lose : public sf::Drawable {
public:
    Lose(float w_Width, float w_Height);
    Lose() = delete;
    ~Lose() = default;

    void drawLoseOption(sf::RenderWindow& window); // metoda do wyswietlania napisow w Lose
    void draw(sf::RenderTarget& target, sf::RenderStates state) const; // metoda do rysowania, jest to metoda dziedziczona z sf::Drawable
    void moveUp();
    void moveDown();
    short getPressedItem() { return selectedItem; };
    void playLoseMusic();
    void stopLoseMusic();
private:
    short selectedItem;
    sf::Font openSans;
    sf::Text loseText;
    sf::Text lose[3];
    sf::Color color[2] = { sf::Color::White, sf::Color::Red };
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::SoundBuffer soundBuf;
    sf::Sound sound;
};



