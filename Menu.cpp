#include "Menu.hpp"


Menu::Menu(float w_Width, float w_Height) {
    openSans.loadFromFile("OpenSans-Regular.ttf");  // za3adowanie czcionki

    soundBuf.loadFromFile("music/battle.ogg"); // zaladowanie sciezki dzwiekowej
    sound.setBuffer(soundBuf); // zbuforowanie sciezki dzwiekowej
    sound.setLoop(true); // zmien odtwarzanie dzwieku w petli na true

    texture.loadFromFile("images/kosmita.png"); // zaladuj texture kosmity
    shape.setTexture(&texture, true); // zmien texture
    shape.setSize(sf::Vector2f{w_Width / 4, w_Height / 3}); // zmien wymiary ksztaltu w ktorym znajduje sie wyswietlana textura
    shape.setPosition(sf::Vector2f{w_Width / 2, w_Height / 3}); // zmien pozycje wyswietlania ksztaltu

    // menu[0] to 3 elementowa tablica typu sf::Text
    menu[0].setFont(openSans); // ustaw czcionke
    menu[0].setString("Play"); // zmien ci1g znak�w
    // zmienna tablicowa color oznacza kolor 0 to White, 1 to Red
    menu[0].setFillColor(color[1]); // ustaw wypelnienie koloru Red
    menu[0].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 1}); // zmien pozycje wyswietlanego tekstu
    // w ponizszych odpowiednio jak w menu[0]
    menu[1].setFont(openSans);
    menu[1].setString("High Score");
    menu[1].setFillColor(color[0]);
    menu[1].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 2});

    menu[2].setFont(openSans);
    menu[2].setString("Exit");
    menu[2].setFillColor(color[0]);
    menu[2].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 3});

    selectedItem = 0; // opcja na ktorej obecnie jest wskaznik
}

void Menu::drawMenuList(sf::RenderWindow& window) {
    for(int i = 0; i < 3; ++i)
        window.draw(menu[i]);
}

void Menu::moveUp() {
    if(selectedItem - 1 >= 0) {
        menu[selectedItem].setFillColor(color[0]);
        selectedItem--;
        menu[selectedItem].setFillColor(color[1]);
    }
}

void Menu::moveDown() {
    if(selectedItem + 1 < 3) {
        menu[selectedItem].setFillColor(color[0]);
        selectedItem++;
        menu[selectedItem].setFillColor(color[1]);
    }
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Menu::playMenuMusic() {
    sound.play(); // odtwarzaj muzyke
}

void Menu::stopMenuMusic() {
    sound.stop(); // przestan odtwarzac muzyke
}

short Menu::getPressedItem() {
    return selectedItem;
}
