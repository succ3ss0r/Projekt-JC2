#include "Star.hpp"

Star::Star(float w_Width, float w_Height) {
    shape.setPosition(w_Width, w_Height);
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
void Star::setPosition(float w_Width, float w_Height) {
    return shape.setPosition(w_Width, w_Height);
}
void Star::fall() {
    this->velocity.y = starVelocity;
}
