#include "Enemy.hpp"

Enemy::Enemy(float t_X, float t_Y, float t_Width, float t_Height)
{
    shape.setPosition(t_X, t_Y);
    shape.setSize(sf::Vector2f{t_Width, t_Height});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(t_Width/2.f, t_Height/2.f);
}
void Enemy::update()
{
    this->shape.move(this->velocity);

//    if(this->left() < SCREEN_WIDTH)
//    {
//        velocity.x = -enemyShipVelocity;
//    } else {
//        velocity.x = enemyShipVelocity;
//    }
}
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}
float Enemy::left()
{
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Enemy::right()
{
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Enemy::top()
{
    return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Enemy::bottom()
{
    return this->shape.getPosition().y + shape.getSize().y / 2.f;
}
sf::Vector2f Enemy::getPosition()
{
    return shape.getPosition();
}
bool Enemy::isDestroyed()
{
    return this->destroyed;
}
void Enemy::destroy()
{
    this->destroyed = true;
}
sf::Vector2f Enemy::getSize()
{
    return shape.getSize();
}
