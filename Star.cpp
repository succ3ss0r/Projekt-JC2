#include "Star.hpp"

Star::Star(float t_X, float t_Y) {
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->starRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(this->starRadius, this->starRadius);
}
void Star::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
void Star::update() {
    shape.move(this->velocity);
}
sf::Vector2f Star::getPosition() {
    return shape.getPosition();
}
void Star::setPosition(float t_X, float t_Y) {
    return shape.setPosition(t_X, t_Y);
}
void Star::fall() {
    this->velocity.y = starVelocity;
}
