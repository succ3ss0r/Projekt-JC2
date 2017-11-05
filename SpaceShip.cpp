#include "SpaceShip.hpp"

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 600
#endif

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
