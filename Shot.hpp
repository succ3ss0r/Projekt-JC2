#include "SFML/Graphics.hpp"

class Shot : public sf::Drawable {
public:
    Shot(float o_Width, float o_Height); // konstruktor
    Shot() = delete; /*!< usuwa domyslny konstruktor*/
    ~Shot() = default; /*!< ustawia domyslny destruktor*/

    void setVelocity(); // zmienia predkosc ruchu
    sf::Vector2f getPosition(); // ustala pozycje obiektu
    void setPosition(float o_Width, float o_Height); // zmienia pozycje ksztaltu
private:
    float shotWidth, shotHeight; // przechowuja szerokosc oraz wysokosc ksztaltu
    sf::RectangleShape shotShape; // ksztalt prostokata
    sf::Texture texture; // zmienna do przechowywania tekstury
    const float shotVelocity = -10.0f; // zmienna wykorzystywana do ustalenia zmiany predkosci
    sf::Vector2f velocity{ 0, shotVelocity }; // taka predkosc ma pocisk
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // Metoda jest odziedziczona z sf::Drawable umozliwia rysowanie ksztaltow w oknie
};

