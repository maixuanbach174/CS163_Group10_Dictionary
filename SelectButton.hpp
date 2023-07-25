#ifndef SELECTBUTTON_HPP
#define SELECTBUTTON_HPP

#include <SFML/Graphics.hpp>
using namespace std;

struct SelectButton
{
    sf::CircleShape border;
    sf::Font selectFont;
    sf::Text selectText;

    SelectButton();
    bool IsInBound(sf::Vector2i mousepos);
    void reset();
    void set();
};


#endif