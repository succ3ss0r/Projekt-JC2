#include "Lose.hpp"

Lose::Lose(float w_Width, float w_Height) {
    openSans.loadFromFile("OpenSans-Regular.ttf");  // za³adowanie czcionki

    soundBuf.loadFromFile("music/lose.ogg"); // zaladowanie sciezki dzwiekowej
    sound.setBuffer(soundBuf); // zbuforowanie sciezki dzwiekowej
    //sound.setLoop(true); // zmien odtwarzanie dzwieku w petli na true

    texture.loadFromFile("images/lose.png"); // zaladuj texture kosmity
    shape.setTexture(&texture, true); // zmien texture
    shape.setSize(sf::Vector2f{w_Width / 4, w_Height / 3}); // zmien wymiary ksztaltu w ktorym znajduje sie wyswietlana textura
    shape.setPosition(sf::Vector2f{w_Width / 2, w_Height / 3}); // zmien pozycje wyswietlania ksztaltu

    // Lose[0] to 3 elementowa tablica typu sf::Text
    lose[0].setFont(openSans); // ustaw czcionke
    lose[0].setString("Play again"); // zmieñ ci¹g znaków
    // zmienna tablicowa color oznacza kolor 0 to White, 1 to Red
    lose[0].setFillColor(color[1]); // ustaw wypelnienie koloru Red
    lose[0].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 1}); // zmien pozycje wyswietlanego tekstu
    // w ponizszych odpowiednio jak w Lose[0]
    lose[1].setFont(openSans);
    lose[1].setString("Back to menu");
    lose[1].setFillColor(color[0]);
    lose[1].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 2});

    lose[2].setFont(openSans);
    lose[2].setString("Exit");
    lose[2].setFillColor(color[0]);
    lose[2].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 3});

    selectedItem = 0; // opcja na ktorej obecnie jest wskaznik
}
void Lose::drawLoseOption(sf::RenderWindow& window) {
    window.draw(loseText);
    for(int i = 0; i < 3; ++i)
        window.draw(lose[i]);
}
void Lose::moveUp() {
    if(selectedItem - 1 >= 0) {
        lose[selectedItem].setFillColor(color[0]); // ustaw kolor na White
        selectedItem--;
        lose[selectedItem].setFillColor(color[1]); // ustaw kolor na Red
    }
}
void Lose::moveDown() {
    if(selectedItem + 1 < 3) {
        lose[selectedItem].setFillColor(color[0]);
        selectedItem++;
        lose[selectedItem].setFillColor(color[1]);
    }
}
void Lose::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}
void Lose::playLoseMusic() {
    sound.play(); // odtwarzaj muzyke
}
void Lose::stopLoseMusic() {
    sound.stop(); // przestan odtwarzac muzyke
}
