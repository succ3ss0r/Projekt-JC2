#include "Shot.hpp"

Shot::Shot(float o_Width, float o_Height) {
    shotWidth = o_Width;
    shotHeight = o_Height;
    shotShape.setFillColor(sf::Color::Red);
    shotShape.setSize(sf::Vector2f{this->shotWidth, this->shotHeight});
    shotShape.setTexture(&texture);
    shotShape.setOrigin(shotWidth / 2, shotHeight / 2);
}

void Shot::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shotShape, state);
}

void Shot::setVelocity() {
    shotShape.move(this->velocity);
}

sf::Vector2f Shot::getPosition() {
    return shotShape.getPosition();
}

void Shot::setPosition(float o_Width, float o_Height) {
    return shotShape.setPosition(o_Width, o_Height);
}
