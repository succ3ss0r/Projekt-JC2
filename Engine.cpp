#include "cstdlib"
#include "vector"
#include "Engine.hpp"

Engine::Engine(unsigned int t_X, unsigned int t_Y, std::string title) {
    window = new sf::RenderWindow( sf::VideoMode(t_X, t_Y), title);
    window->setFramerateLimit(60);
    this->t_X = t_X;
    this->t_Y = t_Y;

    for(int i = 0; i < t_X * 0.1; i++)
    {
        star.push_back(Star(rand()%t_X, rand()%t_Y));
    }
}
Engine::~Engine() {
    delete window;
}
void Engine::loop() {
    while(true) {
        window->clear(sf::Color::Black);

        for(unsigned int i = 0; i < star.size(); ++i) {
            star[i].update();
            if(star[i].getPosition().y > t_Y)
                star[i].setPosition(rand()%t_X, 0);

            window->draw(star[i]);
        }

        window->display();
    }
}
bool Engine::cancelWindow(sf::RenderWindow window, sf::Event event) {
    if(event.type == sf::Event::Closed){
        window.close();
        return true;
    } else return false;
}
