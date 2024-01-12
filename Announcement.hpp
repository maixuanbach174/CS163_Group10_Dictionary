#ifndef ANOUNCEMENT_HPP
#define ANOUNCEMENT_HPP

#include <SFML/Graphics.hpp>
using namespace std;

struct Announcement
{
    sf::RectangleShape box;
    sf::Font mFont;
    sf::Text mText;
    sf::Vector2i topBound;
    sf::Vector2i botBound;
    bool isOn = false;
    Announcement()
    {
        mFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    }

    Announcement(wstring str)
    {
        mFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
        mText.setFont(mFont);
        mText.setString(str);
        mText.setCharacterSize(20);
        mText.setFillColor(sf::Color::White);
        box.setSize(sf::Vector2f(mText.getLocalBounds().width, mText.getLocalBounds().width + 10.f));
        box.setFillColor(sf::Color::Black);
    }

    void isInBound(sf::Vector2i mousepos)
    {
        if(mousepos.x >= topBound.x && mousepos.x <= botBound.x && mousepos.y >= topBound.y
        && mousepos.y <= botBound.y)
        {
            isOn = true;
            sf::Vector2f temp(float(mousepos.x), float(mousepos.y));
            box.setPosition(temp + sf::Vector2f(0, 50.f));
            mText.setPosition(box.getPosition() + sf::Vector2f(0, 5.f));
        }
        isOn =false;
    }
};



#endif