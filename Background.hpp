#include "SFML/Graphics.hpp"

class Background : public sf::Drawable {
public:
    Background(float w_Width, float w_Height);
    Background() = delete;
    ~Background() = default;

    void update();
    sf::Vector2f getPosition();
    void setPosition(float w_Width, float w_Height);
private:
    sf::CircleShape shape;
    const float BackgroundRadius{ 2.0f };
    const float BackgroundVelocity{ 2.f };
    sf::Vector2f velocity{ 0, BackgroundVelocity };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

