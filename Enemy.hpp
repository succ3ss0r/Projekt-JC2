#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable {
public:
    Enemy(float w_Width, float w_Height, float o_Width, float o_Height, short type); // konstruktor
    Enemy() = delete; /*!< usuwa domyslny konstruktor*/
    ~Enemy() = default; /*!< ustawia domyslny destruktor*/

    void update(); // metoda odpowiadajaca za aktualizacje obiektu Enemy
    void setTexture(); // ustawienia teksture ksztaltu
    sf::Vector2f getPosition(); // ustala pozycje
    sf::Vector2f getSize(); // ustala rozmiar
private:
    short type; // zmienna przechowuje typ ruchu
    static sf::Vector2f setPath(float pos_X, short type); // metoda wykorzystywana w metodzie update do zmiany pozycji obiektu przeciwnika
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // odziedziczona z sf::Drawable umozliwia rysowanie ksztaltow w oknie
    sf::RectangleShape shape; // ksztalt prostokata
    sf::Texture texture; // zmienna do przechowywania tekstury
    float enemyShipVelocity = 1.5f; // wartosc wykorzystana do ustawienia predkosci
    sf::Vector2f velocity { enemyShipVelocity, 0.f }; // przechowuje domyslna predkosc
};

