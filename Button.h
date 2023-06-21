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

    bool isInBound(sf::Vector2i mousepos);
};

#endif