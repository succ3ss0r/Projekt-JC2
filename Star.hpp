#include "SFML/Graphics.hpp"

class Star : public sf::Drawable {
public:
    Star(float w_Width, float w_Height);
    Star() = delete;
    ~Star() = default;

    void update();
    sf::Vector2f getPosition();
    void setPosition(float w_Width, float w_Height);
    void fall();
private:
    sf::CircleShape shape;
    const float starRadius{ 2.0f };
    const float starVelocity{ 2.f };
    sf::Vector2f velocity{ 0, starVelocity };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
