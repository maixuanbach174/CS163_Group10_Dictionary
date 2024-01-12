#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "SFML/Graphics.hpp"
using namespace std;

struct Cursor
{
    sf::RectangleShape cursorShape;
    bool showCursor;
    sf::Time cursorBlinkTime;
    Cursor(float width, float height)
    {
        cursorShape.setSize(sf::Vector2f(width, height));
        showCursor = true;
        cursorBlinkTime = sf::seconds(0.5f);
    }
};

#endif