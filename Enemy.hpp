#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable {
public:
    Enemy(float w_Width, float w_Height, float o_Width, float o_Height, short type);
    Enemy() = delete;
    ~Enemy() = default;

    void update();
    sf::Vector2f getPosition();

    sf::Vector2f getSize();
    bool collisionTest(sf::RenderTarget& target, sf::RenderStates states);
private:
    short type;
    static sf::Vector2f chart(float X, short type);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape shape;
    sf::Texture texture;
    bool destroyed{ false };
    float enemyShipVelocity{ 1.5f };
    sf::Vector2f velocity { enemyShipVelocity, 0.f };
};
