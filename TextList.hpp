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
    void addText(wstring newText, int pos);
    void removePos(int pos);
    int isInBound(sf::Vector2i mousepos);
    void clearAll();
    TextList();
    TextList(sf::Color color);
    void moveText(sf::Vector2f delta);
    void splitText(float maxSize);
    int findText(wstring text);
    void removeText(wstring text);
};


#endif