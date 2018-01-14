#include "Enemy.hpp"

Enemy::Enemy(float w_Width, float w_Height, float o_Width, float o_Height, short type) {
    this->type = type;
    shape.setSize(sf::Vector2f{o_Width, o_Height});
    shape.setOrigin(o_Width/2.f, o_Height/2.f);
}

void Enemy::update() {
    this->shape.move(this->velocity);

    if(this->shape.getPosition().x < 820) {
        velocity.x = enemyShipVelocity;
        shape.setPosition(setPath(this->shape.getPosition().x, this->type));
    }
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

sf::Vector2f Enemy::getPosition() {
    return shape.getPosition();
}

sf::Vector2f Enemy::getSize() {
    return shape.getSize();
}
sf::Vector2f Enemy::setPath(float pos_X, short type) {
    float pos_Y = pos_X;
    sf::Vector2f v = {pos_X, pos_Y};
    if(type == 1) {
        if(pos_X < 400)
            pos_Y = pos_X * pos_X * 0.003;
        else
            pos_Y = (pos_X - 800) * (pos_X - 800) * 0.003;

        pos_X += 1.f;
    }
    if(type == 2) {
        int r = 100, znak = 1;

        int positionInType = pos_X / 50;
        int chartType = positionInType % 4;// 0 1 2 3

        positionInType = positionInType / 2 + positionInType % 2;

        positionInType = positionInType * 100;

        if(chartType == 1 || chartType == 2){
            r += 159;
            znak = -1;
        }

        pos_Y = znak * (pos_X - positionInType) * (pos_X - positionInType) * 2 / 63 + r;
        pos_X += 1.0f;
    }

    v = {pos_X, pos_Y};

    return v;
}

void Enemy::setTexture() {
    texture.loadFromFile("images/kosmita.png");
    shape.setTexture(&texture);
}

