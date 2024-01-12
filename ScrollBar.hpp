#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include <SFML/Graphics.hpp>
using namespace std;

struct ScrollBar
{
    sf::RectangleShape railWay;
    sf::RectangleShape bar;
    float step;
    float remain;
};


#endif