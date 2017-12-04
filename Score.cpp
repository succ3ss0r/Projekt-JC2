#include "Score.hpp"

Score::Score(float o_Position, float o_Size) {
        this->openSans.loadFromFile("OpenSans-Regular.ttf");
        this->playerScore.setFont(this->openSans);
        this->playerScore.setCharacterSize(o_Size);
        this->playerScore.setPosition({o_Position, o_Position});
}
void Score::update() {
    this->ssScore.str("");
    this->ssScore << "Score: " << this->score;
    this->playerScore.setString(this->ssScore.str());
}
void Score::increment(int pluss) {
    this->score += pluss;
}

