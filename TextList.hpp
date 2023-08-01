#ifndef TEXTLIST_HPP
#define TEXTLIST_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace std;

struct TextList
{
    vector<sf::Text*> contents;
    vector<sf::RectangleShape*> buttons;
    sf::Font fontContents;
    sf::Color hover;
    int inBound = -1;
    void HandleTextListColor(sf::Vector2i mousepos);
    void addText(wstring newText);
    void removeText(wstring remText);
    int isInBound(sf::Vector2i mousepos);
    TextList();
    TextList(sf::Color color);
};


#endif