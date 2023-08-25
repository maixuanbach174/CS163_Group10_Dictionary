#include "TextList2.hpp"
#include <iostream>

TextList2::TextList2()
{
    fontContents.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
}

TextList2::TextList2(sf::Color color)
{
    fontContents.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    hover = color;
}

void TextList2::addText(wstring newText, int pos)
{
    sf::Text* textTemp = new sf::Text;
    textTemp->setFont(fontContents);
    textTemp->setCharacterSize(35);
    textTemp->setFillColor(sf::Color::White);
    textTemp->setString(newText);

    sf::RectangleShape* buttonTemp = new sf::RectangleShape;
    buttonTemp->setSize(sf::Vector2f(700.f, 55.f));
    buttonTemp->setFillColor(sf::Color::Transparent);

    textTemp->setPosition(sf::Vector2f(250.f, 357.f));
    buttonTemp->setPosition(sf::Vector2f(200.f, 350.f));

    for(int i = pos; i < contents.size(); ++i)
    {
        contents[i]->move(sf::Vector2f(0.f, 55.f));
        buttons[i]->move(sf::Vector2f(0.f, 55.f));
    }

    textTemp->move(sf::Vector2f(0.f, 55.f * pos));
    buttonTemp->move(sf::Vector2f(0.f, 55.f * pos));

    contents.insert(contents.begin() + pos, textTemp);
    buttons.insert(buttons.begin() + pos, buttonTemp);
}

void TextList2::HandleTextList2Color(sf::Vector2i mousepos)
{
    if(inBound != -1) buttons[inBound]->setFillColor(sf::Color::Transparent);
    inBound = isInBound(mousepos);
    if(inBound == -1) return;
    buttons[inBound]->setFillColor(hover);
}

int TextList2::isInBound(sf::Vector2i mousepos)
{
    if(buttons.empty()) return -1;

    if(mousepos.y <= 115) return -1;

    if(mousepos.x < buttons[0]->getPosition().x || mousepos.x > buttons[0]->getPosition().x + buttons[0]->getLocalBounds().width
    || mousepos.y < buttons[0]->getPosition().y || mousepos.y >= buttons[buttons.size() - 1]->getPosition().y + buttons[buttons.size() - 1]->getLocalBounds().height)
    return -1;

    int index = (mousepos.y - buttons[0]->getPosition().y) / buttons[0]->getLocalBounds().height;
    return index;
}

void TextList2::removePos(int pos)
{
    if(pos < 0 || pos >= contents.size()) return;

    delete contents[pos];
    delete buttons[pos];
    contents.erase(contents.begin() + pos);
    buttons.erase(buttons.begin() + pos);
    
    for(pos; pos < contents.size(); ++pos)
    {
        contents[pos]->move(sf::Vector2f(0.f, -55.f));
        buttons[pos]->move(sf::Vector2f(0.f, -55.f));
    }
}

void TextList2::clearAll()
{
    contents.clear();
    buttons.clear();
}

void TextList2::moveText(sf::Vector2f delta)
{
    for(int i = 0; i < contents.size(); ++i)
    {
        contents[i]->move(delta);
        buttons[i]->move(delta);
    }
}

int TextList2::findText(wstring text)
{
    for(int i = 0; i < contents.size(); ++i)
    {
        if(contents[i]->getString() == text) return i;
    }
    return -1;
}

void TextList2::removeText(wstring text)
{
    int pos = findText(text);
    if(pos == -1) return;
    removePos(pos);
}


