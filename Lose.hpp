#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Lose : public sf::Drawable {
public:
    Lose(float w_Width, float w_Height); // konstruktor
    Lose() = delete; /*!< usuwa domyslny konstruktor*/
    ~Lose() = default; /*!< ustawia domyslny destruktor*/

    void drawLoseOption(sf::RenderWindow& window); // metoda do wyswietlania napisow
    void draw(sf::RenderTarget& target, sf::RenderStates state) const; // metoda do rysowania, jest to metoda dziedziczona z sf::Drawable
    void moveUp(); // przesowanie "wskaznika" do gory
    void moveDown(); // przesuwanie "wskaznika" na dol
    short getPressedItem(); // zwraca ktory element zostal wybrany
    void playLoseMusic(); // metoda pozwalajaca odtwarzanie muzyki
    void stopLoseMusic(); // metoda pozwalajaca zatrzymanie odtwarzania
private:
    short selectedItem; // zmienna potrzebna do oznaczenia elementu na ktorym znajduje sie "wskaznik"
    sf::Font openSans; // zmienna z czcionki
    sf::Text lose[3]; // zmienne ktore przechowuja tekst
    sf::Color color[2] = { sf::Color::White, sf::Color::Red }; // zmienne wykorzystywane do ustawienia koloru textu
    sf::RectangleShape shape; // ksztalt prostokata
    sf::Texture texture; // przechowuje teksture
    sf::SoundBuffer soundBuf; // bufor dzwieku
    sf::Sound sound; // zmienna przechowujaca dzwiek z bufora
};



