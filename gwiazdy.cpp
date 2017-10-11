#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "cstdlib"

class Star : public sf::Drawable
{
public:
    Star(unsigned short t_X, unsigned short t_Y);
    Star() = delete;
    ~Star() = default;

    void moveDown();
    void update();
private:
    sf::CircleShape shape;
    const float starRadius{ 2.0f };
    const float starVelocity{ 0.5f };
    sf::Vector2f velocity{ 0, starVelocity };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

};
Star::Star(unsigned short t_X, unsigned short t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->starRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(this->starRadius, this->starRadius);
}
void Star::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}
void Star::update()
{
    shape.move(this->velocity);
}
void Star::moveDown()
{
    this->velocity.y = starVelocity;
}

int main()
{
    sf::RenderWindow window( sf::VideoMode(800, 600), "Space Invaders by Serwicki & Siwon (BETA)" );
    window.setFramerateLimit(60);
    sf::Event event;

    srand(time(NULL));
    Star star(rand() % 800, 0);

    while(true)
    {
        window.pollEvent(event);
        window.clear(sf::Color::Blue);

        if(event.type == sf::Event::Closed){
            window.close();
            break;
        }

        star.update();

        window.draw(star);

        window.display();
    }
}
