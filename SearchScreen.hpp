#ifndef SEARCHSCREEN_HPP
#define SEARCHSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "cscreen.hpp"
#include "TitleBar.hpp"
using namespace std;

class SearchScreen : public cscreen
{
private:
    TitleBar titleBar;
public:
    SearchScreen();
    ~SearchScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex);
    virtual void update(MainMenu& mainmenu);
    virtual void render(sf::RenderWindow& App);
};



#endif