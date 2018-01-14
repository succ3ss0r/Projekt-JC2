#include "SFML/Graphics.hpp"

class SpaceShip : public sf::Drawable {
public:
    SpaceShip(float w_Width, float w_Height, float o_Width, float o_Height); // konstruktor
    SpaceShip() = delete; /*!< usuwa domyslny konstruktor*/
    ~SpaceShip() = default; /*!< ustawia domyslny destruktor*/

    void update(); // Metoda do aktualizacji
    sf::Vector2f getPosition(); // ustala pozycje

    float left();
    float right();
private:
    float w_Width, w_Height; // przechowuja rozmiary okna
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // Metoda jest odziedziczona z sf::Drawable umozliwia rysowanie ksztaltow w oknie
    sf::RectangleShape shape; // ksztalt prostokata
    sf::Texture texture; // zmienna przechowuje teksture
    float spaceShipWidth, spaceShipHeight; // przechowuja rozmiary ksztaltu
    const float spaceShipVelocity = 10.0f; // uzywane do ustawienia predkosci statku
    sf::Vector2f velocity { spaceShipVelocity, 0.f }; // ustawia predkosc statku
};

