#ifndef CSCREEN_HPP
#define CSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "vector"
using namespace std;

class cscreen
{
public:
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& ScreenIndex, wstring& input) {}
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent) {}
    virtual void render(sf::RenderWindow& App) {}
};

#endif