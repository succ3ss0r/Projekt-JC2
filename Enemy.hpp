#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable
{
public:
    Enemy(float t_X, float t_Y, float t_Width, float t_Height);
    Enemy() = delete;
    ~Enemy() = default;

    void update();
    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

    bool isDestroyed();
    void destroy();
    sf::Vector2f getSize();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape shape;
    bool destroyed{ false };
    const float enemyShipVelocity{ 1.0f };
    sf::Vector2f velocity { enemyShipVelocity, 0.f };
};
