#include "SFML/Graphics.hpp"
#include "sstream"

class GetNickname : public sf::Drawable {
public:
    GetNickname(float w_Width, float w_Height);
    GetNickname() = delete;
    ~GetNickname() = default;

    void printText();
    void update(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

    unsigned short maxLength = 7;
    sf::Uint32 unicode;
    sf::Text text[5];
    sf::String str;
    std::string name;
private:
    std::ostringstream ssText[5];
    sf::Font openSans;
    sf::RectangleShape shape;
    sf::Texture texture;
};
