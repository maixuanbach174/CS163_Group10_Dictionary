#ifndef TITLEBAR_HPP
#define TITLEBAR_CPP

#include <SFML/Graphics.hpp>
using namespace std;

struct TitleBar
{
    sf::RectangleShape titleShape;
    sf::Text titleText;
    sf::Texture iconTexture;
    sf::Sprite iconSprite;
    sf::Font titleFont;
    sf::RectangleShape lineshape;
    bool isMove;
    void Move(sf::Vector2f movement)
{
    lineshape.move(movement);
    titleText.move(movement);
    titleShape.move(movement);
}
};





#endif