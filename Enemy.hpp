#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable {
public:
    Enemy(float w_Width, float w_Height, float o_Width, float o_Height, short type); // short type okresla typ ruchu przeciwnika
    Enemy() = delete;
    ~Enemy() = default;

    void update(); // metoda odpowiadajaca za aktualizacje obiektu Enemy
    void setTexture();
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    //bool collisionTest(sf::RenderTarget& target, sf::RenderStates states);
private:
    short type;
    static sf::Vector2f chart(float pos_X, short type); // metoda wykorzystywana w metodzie update do zmiany pozycji obiektu przeciwnika
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape shape;
    sf::Texture texture;
    //bool destroyed = false ;
    float enemyShipVelocity = 1.5f;
    void deleteEnemy();
    sf::Vector2f velocity { enemyShipVelocity, 0.f };
};

