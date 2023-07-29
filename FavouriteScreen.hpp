#ifndef FAVOURITESCREEN_HPP
#define FAVOURITESCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "TitleBar.hpp"
#include "TextList.hpp"
using namespace std;

class FavouriteScreen : public cscreen
{
public:
    TitleBar titleBar;
public:
    TextList textList;
public:
    FavouriteScreen();
    ~FavouriteScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
};

#endif