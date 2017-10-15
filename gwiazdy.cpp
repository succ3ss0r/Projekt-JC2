#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "cstdlib"
#include "vector"

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
    const float spaceShipWidth{ 30.0f };
    const float spaceShipHeight{ 50.0f };
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
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800)
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
    sf::RenderWindow window( sf::VideoMode(800, 600), "Space Invaders by Serwicki & Siwon (BETA)" );
    window.setFramerateLimit(60);
    sf::Event event;

    SpaceShip battleShip(385, 540);

    std::vector<Star> star;   //  Tworzenie obiektów gwiazd
    for(int i = 0; i < 30; i++)
    {
        star.push_back(Star(rand()%800, rand()%600));
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

        for(int i = 0; i < 30; ++i)
        {
            star[i].update();

            if(star[i].getPosition().y > 600)
                star[i].setPosition(rand()%800, 0);

            window.draw(star[i]);
        }

        window.draw(battleShip);

        window.display();
    }
}
