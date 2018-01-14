#include "SFML/Graphics.hpp"
#include "sstream"

class GetNickname : public sf::Drawable {
public:
    GetNickname(float w_Width, float w_Height); // konstruktor
    GetNickname() = delete; /*!< usuwa domyslny konstruktor*/
    ~GetNickname() = default; /*!< ustawia domyslny destruktor*/

    void setTextToPrint(); // zmienia napisy ktore maja zostac wyswietlone w oknie
    void printText(sf::RenderWindow& window); // umozliwia rysowanie napisow w oknie
    void draw(sf::RenderTarget& target, sf::RenderStates state) const; // Metoda umozliwia narysowanie ksztaltu, jest to metoda dziedziczona z sf::Drawable
    bool fileExists(const char* fileName); // sprawdza czy plik istnieje

    unsigned short maxLength = 8; /*!< okresla maksymalna dlugosc nazwy gracza*/
    sf::Uint32 unicode; /*!< zmienna int o stalym rozmiarze*/
    sf::Text text[5]; /*!< zmienna do skonfigurowania tekstu*/
    sf::String str; /*!< zmienna ktora przechowuje lancuch znakow*/
    std::string name; /*!< zmienna ktora przyjmie lancuch znakow podany przez uzytkowanika aby wpisac go do pliku*/
private:
    std::ostringstream ssText[5]; // strumieñ dziedzicz¹cy po ostream, umo¿liwiaj¹cy jedynie zapis
    sf::Font openSans; // zmienna do przechowywania czcionki
    sf::RectangleShape shape; // ksztalt prostokata
    sf::Texture texture; // zmienna do przechowywania tekstury
};
