#include "SFML/Graphics.hpp"

class Star : public sf::Drawable
{
public:
    Star(float t_X, float t_Y);
    Star() = delete;
    ~Star() = default;

    void update();
    sf::Vector2f getPosition();
    void setPosition(float t_X, float t_Y);

    void fall();
private:
    sf::CircleShape shape;
    const float starRadius{ 2.0f };
    const float starVelocity{ 0.5f };
    sf::Vector2f velocity{ 0, starVelocity };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

};
