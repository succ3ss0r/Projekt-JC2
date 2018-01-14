#include "SFML/Graphics.hpp"

class Background : public sf::Drawable {
public:
    Background(float w_Width, float w_Height); // konstruktor
    Background() = delete; /*!< usuwa domyslny konstruktor*/
    ~Background() = default; /*!< ustawia domyslny destruktor*/

    void setMoveVelocity(); // Metoda zmienia predkosc ruchu ksztaltu
    sf::Vector2f getPosition(); // Metoda do ustalenia pozycji
    void setPosition(float w_Width, float w_Height); // Metoda do zmiany pozycji
private:
    sf::CircleShape shape; // ksztalt kola
    const float BackgroundRadius = 2.0f; // promien ksztaltu
    const float BackgroundVelocity = 2.f; // zmienna wykorzystywana do ustawienia predkosci
    sf::Vector2f velocity{ 0, BackgroundVelocity }; // wektor predkosci
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // Metoda jest odziedziczona z sf::Drawable umozliwia rysowanie ksztaltow w oknie
};

