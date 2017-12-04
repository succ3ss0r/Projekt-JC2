#include "SFML/Graphics.hpp"

class Shot : public sf::Drawable {
public:
    Shot(float o_Width, float o_Height);
    Shot() = delete;
    ~Shot() = default;

    void update();
    sf::Vector2f getPosition();
    void setPosition(float n_Width, float n_Height);
private:
    float shotWidth, shotHeight;
    sf::RectangleShape shotShape;
    sf::Texture texture;
    const float shotVelocity{ -10.0f };
    sf::Vector2f velocity{ 0, shotVelocity };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

