#include "Health.hpp"

Health::Health(float o_posX, float o_posY, float o_strSize) {
        this->openSans.loadFromFile("OpenSans-Regular.ttf");
        this->playerHealth.setFont(this->openSans);
        this->playerHealth.setCharacterSize(o_strSize);
        this->playerHealth.setPosition({o_posX, o_posY});
        this->o_health = 100;
}

void Health::textUpdate() {
    this->ssHealth.str("");
    this->ssHealth << "Health: " << this->o_health;
    this->playerHealth.setString(this->ssHealth.str());
}

void Health::increment(int pluss) {
    this->o_health += pluss;
}

void Health::decrement(int minuss) {
    this->o_health -= minuss;
}

