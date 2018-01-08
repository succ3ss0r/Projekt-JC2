#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Menu : public sf::Drawable {
public:
    Menu(float w_Width, float w_Height);
    Menu() = delete;
    ~Menu() = default;

    void drawMenuList(sf::RenderWindow& window); // metoda do wyswietlania napisow w menu
    void draw(sf::RenderTarget& target, sf::RenderStates state) const; // metoda do rysowania, jest to metoda dziedziczona z sf::Drawable
    void moveUp(); // przesowanie "wskaznika" do gory
    void moveDown(); // przesuwanie "wskaznika" na dol
    short getPressedItem() { return selectedItem; }; // metoda zwraca ktory element zostal wybrany
    void playMenuMusic(); // metoda pozwalaj¹ca odtwarzanie muzyki
    void stopMenuMusic(); // metoda pozwalaj¹ca zatrzymanie odtwarzania
private:
    short selectedItem; // zmienna potrzebna do oznaczenia elementu na ktorym znajduje sie "wskaznik"
    sf::Font openSans; // zmienna z czcionk¹
    sf::Text menu[3]; // zmienne wykorzystywane w liscie menu (napisy)
    sf::Color color[2] = { sf::Color::White, sf::Color::Red }; // zmienne wykorzystywane do ustawienia koloru textu
    sf::RectangleShape shape; // w tym kszta³cie jest logo kosmity w menu
    sf::Texture texture; // textura kosmity w menu
    sf::SoundBuffer soundBuf; // bufor dzwieku
    sf::Sound sound; //
};


