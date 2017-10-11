/*********************************************
********* Siwoń Paweł, Serwicki Jakub ********
***** PROJEKT Z PODSTAW PROGRAMOWANIA C2 *****
**************** SPACE INVADERS **************
******* POLITECHNIKA ŚWIĘTOKRZYSKA 2017 ******
*********************************************/

#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1000, 700), "Space Invaders");
  window.setPosition(sf::Vector2i(10,50));
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::MouseButtonPressed:
          sf::CircleShape shape(50);
          shape.setFillColor(sf::Color(100, 250, 50));
          window.draw(shape);
          break;
      }
    }
    window.display();
  }

  return 0;
}
