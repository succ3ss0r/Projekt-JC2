#include "SFML/Graphics.hpp"
#include "sstream"

class Highscore : public sf::Drawable {
public:
    Highscore(float w_Width, float w_Height); // konstruktor
    Highscore() = delete; /*!< usuwa domyslny konstruktor*/
    ~Highscore() = default; /*!< ustawia domyslny destruktor*/

    void setHighscoreText(); // metoda zmienia napisy
    void printLeaderBoard(sf::RenderWindow& window); // metoda do wyswietlania napisow w oknie
    void draw(sf::RenderTarget& target, sf::RenderStates state) const; // odziedziczona metoda z sf::Drawable

    sf::Text playerScore[5]; /*!< zmienna przechowuje tekst ktory zostaje wyswietlony w oknie*/
    std::string score[3]; /*!< przechowuje wyniki pobrane z pliku*/
    std::string name[3]; /*!< przechowuje nazwy graczy pobrane z pliku*/
private:
    std::ostringstream ssScore[5]; // strumieñ dziedzicz¹cy po ostream, umo¿liwiaj¹cy jedynie zapis
    sf::Font openSans; // zmienna do przechowywania czcionki
    sf::RectangleShape shape; // ksztalt prostokata
    sf::Texture texture; // zmienna do przechowywania tekstury
};
