#include "Highscore.hpp"

Highscore::Highscore(float w_Width, float w_Height) {
    this->openSans.loadFromFile("OpenSans-Regular.ttf");

    texture.loadFromFile("images/kosmita.png"); // zaladuj texture kosmity
    shape.setTexture(&texture, true); // zmien texture
    shape.setSize(sf::Vector2f{w_Width / 4, w_Height / 3}); // zmien wymiary ksztaltu w ktorym znajduje sie wyswietlana textura
    shape.setPosition(sf::Vector2f{w_Width / 1.5f, w_Height / 3}); // zmien pozycje wyswietlania ksztaltu

    for(int i = 0; i < 3; ++i) {
        this->playerScore[i].setFont(this->openSans);
        this->playerScore[i].setCharacterSize(25);
        this->playerScore[i].setPosition(sf::Vector2f{30.f, (w_Height / 4 * 0.5f * i + 200)});
    }

    this->playerScore[3].setFont(this->openSans);
    this->playerScore[3].setCharacterSize(50);
    this->playerScore[3].setPosition(sf::Vector2f{w_Width / 4.5f + 60, 50});

    this->playerScore[4].setFont(this->openSans);
    this->playerScore[4].setCharacterSize(10);
    this->playerScore[4].setPosition(sf::Vector2f{w_Width/3 + 30, w_Height - 50});

    this->playerScore[0].setFillColor(sf::Color(255, 215, 0, 255));
    this->playerScore[1].setFillColor(sf::Color(192, 192, 192, 255));
    this->playerScore[2].setFillColor(sf::Color(139, 69, 19, 255));
    this->playerScore[3].setFillColor(sf::Color::Red);
}

void Highscore::setHighscoreText() {
    for(int j = 0; j < 3; ++j) {
        this->ssScore[j].str("");
        this->ssScore[j] << "Name: " << this->name[j] << " Score: " << this->score[j];
        this->playerScore[j].setString(this->ssScore[j].str());
    }

    this->ssScore[3].str("");
    this->ssScore[3] << "Leader board";;
    this->playerScore[3].setString(this->ssScore[3].str());

    this->ssScore[4].str("");
    this->ssScore[4] << "Pres space to go back to menu";
    this->playerScore[4].setString(this->ssScore[4].str());
}

void Highscore::printLeaderBoard(sf::RenderWindow& window) {
    for(int i = 0; i < 5; ++i)
        window.draw(playerScore[i]);
}

void Highscore::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
