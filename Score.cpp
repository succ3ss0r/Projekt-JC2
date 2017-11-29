#include "Score.hpp"

Score::Score(float t_Position, float t_Size) {
        this->openSans.loadFromFile("OpenSans-Regular.ttf");
        this->playerScore.setFont(this->openSans);
        this->playerScore.setCharacterSize(t_Size);
        this->playerScore.setPosition({t_Position, t_Position});
}
void Score::update() {
    this->ssScore.str("");
    this->ssScore << "Score: " << this->score;
    this->playerScore.setString(this->ssScore.str());
}
void Score::increment(int pluss) {
    this->score += pluss;
}
int Score::print() {
    return this->score;
}
