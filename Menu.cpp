#include "Menu.hpp"

Menu::Menu(float w_Width, float w_Height) {
    openSans.loadFromFile("OpenSans-Regular.ttf");

    texture.loadFromFile("images/kosmita.png");
    shape.setTexture(&texture, true);
    shape.setSize(sf::Vector2f{w_Width / 4, w_Height / 3});
    shape.setPosition(sf::Vector2f{400, 200});

    menu[0].setFont(openSans);
    menu[0].setString("Play");
    menu[0].setFillColor(color[1]);
    menu[0].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 1});

    menu[1].setFont(openSans);
    menu[1].setString("High Score");
    menu[1].setFillColor(color[0]);
    menu[1].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 2});

    menu[2].setFont(openSans);
    menu[2].setString("Exit");
    menu[2].setFillColor(color[0]);
    menu[2].setPosition(sf::Vector2f{100, w_Height / (3 + 1) * 3});

    selectedItem = 0;
}
void Menu::drawMenu(sf::RenderWindow& window) {
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
