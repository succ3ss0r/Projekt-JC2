#include "SFML/Graphics.hpp"
#include "sstream"

class Health {
public:
    Health(float o_posX, float o_posY, float o_strSize); // konstruktor
    Health() = delete; /*!< usuwa domyslny konstruktor*/
    ~Health() = default; /*!< ustawia domyslny destruktor*/

    void textUpdate(); // Metoda do aktualizacji tekstu
    void increment(int pluss); // Metoda do zwiekszania punktow zycia
    void decrement(int minuss); // Metoda do zmniejszania punktow zycia
    sf::Text playerHealth; // przechowuje tekst ktory bedzie wyswietlony w oknie
    int o_health; /*!< przechowuje punkty zycia*/
private:
    std::ostringstream ssHealth; // przechowuje tekst do wyswietlenia w oknie za pomoca playerHealth
    sf::Font openSans; // zmienna przechowuje czcionke
};


