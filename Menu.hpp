#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Menu : public sf::Drawable {
public:
    Menu(float w_Width, float w_Height);
    Menu() = delete;
    ~Menu() = default;

    void drawMenu(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    void moveUp(); // przesowanie "wskaznika" do gory
    void moveDown(); // przesuwanie "wskaznika" na dol
    short getPressedItem() { return selectedItem; }; // metoda zwraca ktory element zostal wybrany
    void playMenuMusic();
    void stopMenuMusic();
private:
    short selectedItem; // zmienna potrzebna do oznaczenia elementu na ktorym znajduje sie "wskaznik"
    sf::Font openSans;
    sf::Text menu[3];
    sf::Color color[2] = { sf::Color::White, sf::Color::Red };
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::SoundBuffer soundBuf;
    sf::Sound sound;
};


