#include "SFML/Graphics.hpp"

class SpaceShip : public sf::Drawable {
public:
    SpaceShip(float t_X, float t_Y, float width, float height);
    SpaceShip() = delete;
    ~SpaceShip() = default;

    void update();
    sf::Vector2f getPosition();

    float left();
    float right();
private:
    float t_X, t_Y;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    float spaceShipWidth;
    float spaceShipHeight;
    const float spaceShipVelocity{ 10.0f };
    sf::Vector2f velocity { spaceShipVelocity, 0.f };
};
