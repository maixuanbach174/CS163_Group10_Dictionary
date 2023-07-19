#include "MenuButtons.h"

MenuButtons::MenuButtons(float w, float h, float X, float Y)
: lightGrey(50, 50, 50, 50)
, DarkOrange(220, 110, 0, 100)
, LightOrange(200, 100, 0)
, selected(0)
, selectMove(-1)
{
    width = w;
    height = h;
    position.x = X;
    position.y = Y;
    for(int i = 0; i < 6; ++i)
    {
        buttons[i].setSize(sf::Vector2f(width, height / 6));
        buttons[i].setPosition(position.x, position.y + i * height / 6);
        buttons[i].setFillColor(sf::Color::Transparent);
    }

    buttons[0].setFillColor(LightOrange);
}

int MenuButtons::isInBound(sf::Vector2i mousepos)
{
    if(mousepos.x < 0 || mousepos.y < position.y || 
    mousepos.x > position.x + width || mousepos.y >= position.y + height) return -1;
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
    if(index == -1)
    {
        if(selectMove == -1 || selectMove == selected) return;
        buttons[selectMove].setFillColor(sf::Color::Transparent);
        selectMove = -1;
        return;
    }
  
    if(index == selectMove) return;

    if(selectMove != -1 && selectMove != selected) buttons[selectMove].setFillColor(sf::Color::Transparent);
    if(index == selected) 
    {
        selectMove = -1;
        return;
    }
    buttons[index].setFillColor(DarkOrange);
    selectMove = index;
}

void MenuButtons::move(sf::Vector2f movement)
{
    if(movement.x < 0) position.x = movement.x;
    else position.x = 0;

    for(int i = 0; i < 6; ++i)
    {
        buttons[i].move(movement);
    }
}


