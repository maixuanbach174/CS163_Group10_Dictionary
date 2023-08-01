#include "TextList.hpp"
#include <iostream>

TextList::TextList()
{
    fontContents.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
}

TextList::TextList(sf::Color color)
{
    fontContents.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    hover = color;
}

void TextList::addText(wstring newText)
{
    sf::Text* textTemp = new sf::Text;
    textTemp->setFont(fontContents);
    textTemp->setCharacterSize(35);
    textTemp->setFillColor(sf::Color::White);
    textTemp->setString(newText);

    sf::RectangleShape* buttonTemp = new sf::RectangleShape;
    buttonTemp->setSize(sf::Vector2f(1450.f, 55.f));
    buttonTemp->setFillColor(sf::Color::Transparent);

    textTemp->setPosition(sf::Vector2f(150.f, 197.f));
    buttonTemp->setPosition(sf::Vector2f(100.f, 190.f));

    for(int i = 0; i < contents.size(); ++i)
    {
        contents[i]->move(sf::Vector2f(0.f, 55.f));
        buttons[i]->move(sf::Vector2f(0.f, 55.f));
    }

    contents.insert(contents.begin(), textTemp);
    buttons.insert(buttons.begin(), buttonTemp);
}

void TextList::HandleTextListColor(sf::Vector2i mousepos)
{
    if(inBound != -1) buttons[inBound]->setFillColor(sf::Color::Transparent);
    inBound = isInBound(mousepos);
    if(inBound == -1) return;
    cout << inBound << endl;
    buttons[inBound]->setFillColor(hover);
}

int TextList::isInBound(sf::Vector2i mousepos)
{
    if(buttons.empty()) return -1;

    if(mousepos.x < buttons[0]->getPosition().x || mousepos.x > buttons[0]->getPosition().x + buttons[0]->getLocalBounds().width
    || mousepos.y < buttons[0]->getPosition().y || mousepos.y >= buttons[buttons.size() - 1]->getPosition().y + buttons[buttons.size() - 1]->getLocalBounds().height)
    return -1;

    int index = (mousepos.y - buttons[0]->getPosition().y) / buttons[0]->getLocalBounds().height;
    return index;
}

void TextList::removeText(wstring remText)
{
    int i = 0;
    for(i; i < contents.size(); ++i)
    {
        if(contents[i]->getString() == remText)
        {
            delete contents[i];
            delete buttons[i];
            contents.erase(contents.begin() + i);
            buttons.erase(buttons.begin() + i);
            break;
        }
    }
    
    for(i; i < contents.size(); ++i)
    {
        contents[i]->move(sf::Vector2f(0.f, -55.f));
        buttons[i]->move(sf::Vector2f(0.f, -55.f));
    }
}