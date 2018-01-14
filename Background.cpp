#include "Background.hpp"

Background::Background(float w_Width, float w_Height) {
    shape.setPosition(w_Width, w_Height);
    shape.setRadius(this->BackgroundRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(this->BackgroundRadius, this->BackgroundRadius);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Background::setMoveVelocity() {
    shape.move(this->velocity);
}

sf::Vector2f Background::getPosition() {
    return shape.getPosition();
}

void Background::setPosition(float w_Width, float w_Height) {
    return shape.setPosition(w_Width, w_Height);
}

