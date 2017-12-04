#include "SpaceShip.hpp"

SpaceShip::SpaceShip(float w_Width, float w_Height, float o_Width, float o_Height) {
    this->spaceShipWidth = o_Width;
    this->spaceShipHeight = o_Height;
    this->w_Width = w_Width;
    this->w_Height = w_Height;
    texture.loadFromFile("images/SpaceShip.png");
    shape.setTexture(&texture);
    shape.setPosition(w_Width/2-o_Width/2, w_Height-60);
    shape.setSize(sf::Vector2f{this->spaceShipWidth, this->spaceShipHeight});
    shape.setOrigin(spaceShipWidth/2.f, spaceShipHeight/2.f);
}
void SpaceShip::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
void SpaceShip::update() {
    this->shape.move(this->velocity);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
        velocity.x = -spaceShipVelocity;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < w_Width) {
        velocity.x = spaceShipVelocity;
    } else {
        velocity.x = 0;
    }
}
sf::Vector2f SpaceShip::getPosition() {
    return shape.getPosition();
}
float SpaceShip::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float SpaceShip::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

