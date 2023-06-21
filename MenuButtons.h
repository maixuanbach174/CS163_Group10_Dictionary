#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;

struct MenuButtons
{
    sf::Vector2f position;
    float width;
    float height;
    sf::RectangleShape buttons[6];
    int selected;
    int selectMove;

    sf::Color lightGrey;
    sf::Color DarkOrange;
    sf::Color LightOrange;

    MenuButtons(float w, float h, float X, float Y);

    int isInBound(sf::Vector2i mousepos);

    void setColorButtons(int index);

    void MoveColor(int index);

    void move(sf::Vector2f movement);
};

#endif