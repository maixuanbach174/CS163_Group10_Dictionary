#include "Button.h"

Button::Button(float w, float h, float X, float Y)
: width(w)
, height(h)
, position(X, Y)
{
    rect.setSize(sf::Vector2f(width, height));
    rect.setPosition(X, Y);
    rect.setFillColor(sf::Color::Transparent);
}

bool Button::isInBound(sf::Vector2i mousepos)
{
    if(mousepos.x >= position.x && mousepos.y >= position.y 
    && mousepos.x <= position.x + width && mousepos.y <= position.y + height) 
    {
        return true;
    }
    return false;
}