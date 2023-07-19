#ifndef FAVOURITESCREEN_HPP
#define FAVOURITESCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;

class FavouriteScreen : public cscreen
{
private:
    
public:
    FavouriteScreen();
    ~FavouriteScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu);
    virtual void update();
    virtual void render(sf::RenderWindow& App);
};

#endif