#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
using namespace std;

struct TextBox
{
    int width;
    int height;
    sf::RectangleShape box;
    sf::RectangleShape line;
    sf::Vector2f position;
    float distance;
    TextBox(int w, int h, float d);
    void setPos(sf::Vector2f pos);
    void setColor(sf::Color boxcolor, sf::Color linecolor);
    bool isInBound(sf::Vector2i pos);
};

#endif