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
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex);
    virtual void update(MainMenu& mainmenu);
    virtual void render(sf::RenderWindow& App);
};

#endif