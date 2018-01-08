#include "Health.hpp"

Health::Health(float o_posX, float o_posY, float o_strSize) {
        this->openSans.loadFromFile("OpenSans-Regular.ttf");
        this->playerHealth.setFont(this->openSans);
        this->playerHealth.setCharacterSize(o_strSize);
        this->playerHealth.setPosition({o_posX, o_posY});
}
void Health::update() {
    this->ssHealth.str("");
    this->ssHealth << "Health: " << this->health;
    this->playerHealth.setString(this->ssHealth.str());
}
void Health::increment(int pluss) {
    this->health += pluss;
}
void Health::decrement(int minuss) {
    this->health -= minuss;
}
