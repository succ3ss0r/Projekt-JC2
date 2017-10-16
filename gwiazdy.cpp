#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "cstdlib"
#include "vector"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SHIP_WIDTH 30
#define SHIP_HEIGHT 50
#define NUMBER_OF_STARS 50

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
    const float spaceShipVelocity{ 15.0f };
    sf::Vector2f velocity { spaceShipVelocity, 0.f };
};
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

Star::Star(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->starRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(this->starRadius, this->starRadius);
}
void Star::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}
void Star::update()
{
    shape.move(this->velocity);
}
sf::Vector2f Star::getPosition()
{
    return shape.getPosition();
}
void Star::setPosition(float t_X, float t_Y)
{
    return shape.setPosition(t_X, t_Y);
}
void Star::fall()
{
    this->velocity.y = starVelocity;
}

SpaceShip::SpaceShip(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setSize(sf::Vector2f{this->spaceShipWidth, this->spaceShipHeight});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(spaceShipWidth/2.f, spaceShipHeight/2.f);
}
void SpaceShip::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}
void SpaceShip::update()
{
    this->shape.move(this->velocity);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0)
    {
        velocity.x = -spaceShipVelocity;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < SCREEN_WIDTH)
    {
        velocity.x = spaceShipVelocity;
    }else
    {
        velocity.x = 0;
    }
}
sf::Vector2f SpaceShip::getPosition()
{
    return shape.getPosition();
}
float SpaceShip::left()
{
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float SpaceShip::right()
{
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float SpaceShip::top()
{
    return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float SpaceShip::bottom()
{
    return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

int main()
{
    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invaders by Serwicki & Siwon (BETA)" );
    window.setFramerateLimit(60);
    sf::Event event;

    SpaceShip battleShip(SCREEN_WIDTH/2-SHIP_WIDTH/2, SCREEN_HEIGHT-60);

    std::vector<Star> star;   //  Tworzenie obiektów gwiazd
    for(int i = 0; i < NUMBER_OF_STARS; i++)
    {
        star.push_back(Star(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT));
    }

    while(true)
    {
        window.pollEvent(event);
        window.clear(sf::Color::Black);

        if(event.type == sf::Event::Closed){
            window.close();
            break;
        }

        battleShip.update();

        for(int i = 0; i < NUMBER_OF_STARS; ++i)
        {
            star[i].update();

            if(star[i].getPosition().y > SCREEN_HEIGHT)
                star[i].setPosition(rand()%SCREEN_WIDTH, 0);

            window.draw(star[i]);
        }

        window.draw(battleShip);

        window.display();
    }
}
