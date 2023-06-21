#include "MenuButtons.h"

MenuButtons::MenuButtons(float w, float h, float X, float Y)
: lightGrey(50, 50, 50, 50)
, DarkOrange(200, 100, 0, 100)
, LightOrange(200, 100, 0)
, selected(-1)
, selectMove(-1)
{
    width = w;
    height = h;
    position.x = X;
    position.y = Y;
    for(int i = 0; i < 6; ++i)
    {
        buttons[i].setSize(sf::Vector2f(width, height / 6));
        buttons[i].setPosition(0, position.y + i * height / 6);
        buttons[i].setFillColor(lightGrey);
    }
}

int MenuButtons::isInBound(sf::Vector2i mousepos)
{
    if(mousepos.x < 0 || mousepos.y < position.y || 
    mousepos.x > width || mousepos.y >= position.y + height) return -1;
    return floor((mousepos.y - position.y) / height * 6);  
}

void MenuButtons::setColorButtons(int index)
{
    if(index == -1) return;

    if(index == selected) return;

    if(selected != -1) buttons[selected].setFillColor(sf::Color::Transparent);

    buttons[index].setFillColor(LightOrange);

    selected = index;
}

void MenuButtons::MoveColor(int index)
{
    if(index == selected) return;

    if(index == -1)
    {
        if(selectMove == -1 || selectMove == selected) return;
        buttons[selectMove].setFillColor(sf::Color::Transparent);
        selectMove = -1;
        return;
    }
  
    if(index == selectMove) return;

    if(selectMove != -1 && selectMove != selected) buttons[selectMove].setFillColor(sf::Color::Transparent);
    buttons[index].setFillColor(DarkOrange);
    selectMove = index;
}

