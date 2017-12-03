#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Menu : public sf::Drawable {
public:
    Menu(float w_Width, float w_Height);
    Menu() = delete;
    ~Menu() = default;

    void drawMenu(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    void moveUp();
    void moveDown();
    short getPressedItem() { return selectedItem; };
    void playMenuMusic();
    void stopMenuMusic();
private:
    short selectedItem;
    sf::Font openSans;
    sf::Text menu[3];
    sf::Color color[2] = { sf::Color::White, sf::Color::Red };
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::SoundBuffer soundBuf;
    sf::Sound sound;
};

