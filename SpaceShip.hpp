#include "SFML/Graphics.hpp"

class SpaceShip : public sf::Drawable {
public:
    SpaceShip(float w_Width, float w_Height, float width, float height);
    SpaceShip() = delete;
    ~SpaceShip() = default;

    void update();
    sf::Vector2f getPosition();

    float left();
    float right();
private:
    float w_Width, w_Height;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    sf::Texture texture;
    float spaceShipWidth;
    float spaceShipHeight;
    const float spaceShipVelocity{ 10.0f };
    sf::Vector2f velocity { spaceShipVelocity, 0.f };
};
