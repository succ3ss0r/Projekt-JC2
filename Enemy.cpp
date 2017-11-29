#include "Enemy.hpp"

Enemy::Enemy(float t_X, float t_Y, float t_Width, float t_Height, short type) {
    this->type = type;
    shape.setPosition(t_X, t_Y);
    shape.setSize(sf::Vector2f{t_Width, t_Height});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(t_Width/2.f, t_Height/2.f);
}
void Enemy::update() {
    this->shape.move(this->velocity);

    if(this->shape.getPosition().x < 820) {
        velocity.x = enemyShipVelocity;
        shape.setPosition(chart(this->shape.getPosition().x, this->type));
    }
}
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
float Enemy::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Enemy::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Enemy::top() {
    return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Enemy::bottom() {
    return this->shape.getPosition().y + shape.getSize().y / 2.f;
}
sf::Vector2f Enemy::getPosition() {
    return shape.getPosition();
}
sf::Vector2f Enemy::getSize() {
    return shape.getSize();
}
sf::Vector2f Enemy::chart(float X, short type) {
    float Y = X;
    if(type == 1){
        enemyShipVelocity = 1.7f;
        if(X < 400)
            Y = X * X * 0.003;
        else
            Y = (X - 800) * (X - 800) * 0.003;
    }
    sf::Vector2f v = {X, Y};

    return v;
}
