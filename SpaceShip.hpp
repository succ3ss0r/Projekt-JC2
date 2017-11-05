#include "SFML/Graphics.hpp"

#define SHIP_WIDTH 30
#define SHIP_HEIGHT 50

class SpaceShip : public sf::Drawable
{
public:
    SpaceShip(float t_X, float t_Y);
    SpaceShip() = delete;
    ~SpaceShip() = default;

    void update();
    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    const float spaceShipWidth{ SHIP_WIDTH };
    const float spaceShipHeight{ SHIP_HEIGHT };
    const float spaceShipVelocity{ 10.0f };
    sf::Vector2f velocity { spaceShipVelocity, 0.f };
};
