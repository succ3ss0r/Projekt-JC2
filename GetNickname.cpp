#include "GetNickname.hpp"
#include "sys/stat.h"

GetNickname::GetNickname(float w_Width, float w_Height) {
    this->openSans.loadFromFile("OpenSans-Regular.ttf");

    texture.loadFromFile("images/kosmita.png"); // zaladuj texture kosmity
    shape.setTexture(&texture, true); // zmien texture
    shape.setSize(sf::Vector2f{w_Width / 8, w_Height / 6}); // zmien wymiary ksztaltu w ktorym znajduje sie wyswietlana textura
    shape.setPosition(sf::Vector2f{70, 70}); // zmien pozycje wyswietlania ksztaltu

    this->text[0].setFont(this->openSans);
    this->text[0].setCharacterSize(70);
    this->text[0].setPosition(sf::Vector2f{190, 70});
    this->text[0].setFillColor(sf::Color::Red);

    this->text[1].setFont(this->openSans);
    this->text[1].setCharacterSize(35);
    this->text[1].setPosition(sf::Vector2f{w_Width / 10, w_Height / 3 * 1.7f - 70});
    this->text[1].setFillColor(sf::Color::White);

    this->text[2].setFont(this->openSans);
    this->text[2].setCharacterSize(35);
    this->text[2].setPosition(sf::Vector2f{w_Width / 10 + 300, w_Height / 3 * 1.7f - 70});
    this->text[2].setFillColor(sf::Color::White);

    this->text[3].setFont(this->openSans);
    this->text[3].setCharacterSize(20);
    this->text[3].setPosition(sf::Vector2f{w_Width / 10, w_Height / 3 * 1.7f + 20});
    this->text[3].setFillColor(sf::Color::Red);

    this->text[4].setFont(this->openSans);
    this->text[4].setCharacterSize(15);
    this->text[4].setPosition(sf::Vector2f{w_Width/3 + 15, w_Height - 50});
    this->text[4].setFillColor(sf::Color::White);
}

void GetNickname::setTextToPrint() {
    this->ssText[0].str("");
    this->ssText[0] << "Space Invaders";
    this->text[0].setString(this->ssText[0].str());

    this->ssText[1].str("");
    this->ssText[1] << "Enter your name: ";
    this->text[1].setString(this->ssText[1].str());

    this->ssText[3].str("");
    this->ssText[3] << "Name should have from 1 to 8 characters!";
    this->text[3].setString(this->ssText[3].str());

    this->ssText[4].str("");
    this->ssText[4] << "Press space to complete";
    this->text[4].setString(this->ssText[4].str());
}

void GetNickname::printText(sf::RenderWindow& window) {
    for(int i = 0; i < 5; ++i)
        window.draw(text[i]);
}

void GetNickname::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
bool GetNickname::fileExists (const char* fileName) {
    struct stat buf;
    if (stat(fileName, &buf) == 0)
        return true;
    else
        return false;
}

