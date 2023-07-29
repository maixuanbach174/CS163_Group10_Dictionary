#ifndef FAVOURITEBUTTON_HPP
#define FAVOURITEBUTTON_HPP

#include <SFML/Graphics.hpp>
using namespace std;
struct FavouriteButton
{
    sf::Texture heartTexture;
    sf::Sprite heartSprite;
    bool isFavourite = false;
    bool isInBound(sf::Vector2i mousepos)
    {
        if(mousepos.x >= heartSprite.getPosition().x && mousepos.x <= heartSprite.getPosition().x + heartSprite.getLocalBounds().width
        && mousepos.y >= heartSprite.getPosition().y && mousepos.y <= heartSprite.getPosition().y + heartSprite.getLocalBounds().height)
        {
            heartSprite.setColor(sf::Color::Red);
            return true;
        }
    
        if(heartSprite.getColor() != sf::Color::White)
        {
            heartSprite.setColor(sf::Color::White);
        }
        return false;
    }
    FavouriteButton()
    {
        heartTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/HeartButton.png");
        heartSprite.setTexture(heartTexture);
    }
};


#endif