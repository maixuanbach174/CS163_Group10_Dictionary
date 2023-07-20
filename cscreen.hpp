#ifndef CSCREEN_HPP
#define CSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
using namespace std;

class cscreen
{
public:
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& ScreenIndex) {}
    virtual void update(MainMenu& mainmenu) {}
    virtual void render(sf::RenderWindow& App) {}
};

#endif