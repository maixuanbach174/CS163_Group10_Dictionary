#include "TextBox.h"

TextBox::TextBox(int w, int h, float d)
{
    distance = d;
    width = w;
    height = h;
    box.setSize(sf::Vector2f(width, height));
    line.setSize(sf::Vector2f(width, 4.f));
}

void TextBox::setPos(sf::Vector2f pos)
{
    position = pos;
    line.setPosition(sf::Vector2f(position.x, position.y + height + 4.f - distance));
    box.setPosition(position);
}

void TextBox::setColor(sf::Color boxcolor, sf::Color linecolor)
{
    box.setFillColor(boxcolor);
    line.setFillColor(linecolor);
    line.setFillColor(linecolor);
}

bool TextBox::isInBound(sf::Vector2i pos)
{
    if(pos.x < position.x || pos.y < position.y || pos.x > position.x + width || pos.y > position.y + height)
    {
        return false;
    }

    return true;
}