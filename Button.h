#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace std;

struct Button
{
    sf::Vector2f position;
    float width;
    float height;
    sf::RectangleShape rect;

    Button(float w, float h, float X, float Y);
    bool isInBound(sf::Vector2i mousepos);

};

#endif