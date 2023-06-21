#include "Button.h"

bool Button::isInBound(sf::Vector2i mousepos)
{
    if(mousepos.x >= position.x && mousepos.y >= position.y 
    && mousepos.x <= position.x + width && mousepos.y <= position.y + height) return true;
    return false;
}