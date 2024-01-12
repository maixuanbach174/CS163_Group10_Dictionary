#include "SelectButton.hpp"

SelectButton::SelectButton()
{
    selectFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    selectText.setFont(selectFont);
    selectText.setCharacterSize(30);
    selectText.setFillColor(sf::Color::White);
}

bool SelectButton::IsInBound(sf::Vector2i mousepos)
{
    if(mousepos.x >= border.getPosition().x && mousepos.x <= selectText.getPosition().x + selectText.getLocalBounds().width
    && mousepos.y >= border.getPosition().y && mousepos.y <= border.getPosition().y + border.getLocalBounds().height)
    {
        return true;
    }

    return false;
}

void SelectButton::reset()
{
    border.setRadius(15);
    border.setOutlineThickness(3);
    border.setOutlineColor(sf::Color(80, 80, 80, 255));
    border.setFillColor(sf::Color::Transparent);
     border.setPosition(border.getPosition().x - 2.f, border.getPosition().y - 2.f);
}

void SelectButton::set()
{
    border.setRadius(13);
    border.setOutlineThickness(5);
    border.setOutlineColor(sf::Color(100, 100, 255, 255));
    border.setFillColor(sf::Color(30, 30, 75, 255));
    border.setPosition(border.getPosition().x + 2.f, border.getPosition().y + 2.f);
}
