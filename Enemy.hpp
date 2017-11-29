#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable {
public:
    Enemy(float t_X, float t_Y, float t_Width, float t_Height, short type);
    Enemy() = delete;
    ~Enemy() = default;

    void update();
    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

    sf::Vector2f getSize();
    bool collisionTest(sf::RenderTarget& target, sf::RenderStates states);
private:
    short type;
    sf::Vector2f chart(float X, short type);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape shape;
    bool destroyed{ false };
    float enemyShipVelocity{ 1.0f };
    sf::Vector2f velocity { enemyShipVelocity, 0.f };
};
