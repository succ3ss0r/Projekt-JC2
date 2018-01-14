#include "SFML/Graphics.hpp"
#include "sstream"

class Score {
public:
    Score(float o_Position, float o_Size); // konstruktor
    Score() = delete; /*!< usuwa domyslny konstruktor*/
    ~Score() = default; /*!< ustawia domyslny destruktor*/

    void textUpdate(); // Aktualizacja tekstu ktory bedzie wyswietlony w oknie
    void increment(int pluss); // Metoda inkrementuje wynik gracza
    sf::Text playerScore; /*!< tekst ktory bedzie wyswietlony w oknie*/
    int score = 0; /*!< ustawia poczatkowa ilosc punktow*/
private:
    std::ostringstream ssScore; // przechowuje tekst ktory bedzie wyswietlony w oknie za pomoca playerScore
    sf::Font openSans; // zmienna do przechowywania czcionki
};


