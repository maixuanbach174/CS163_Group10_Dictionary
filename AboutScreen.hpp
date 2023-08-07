#ifndef ABOUTSCREEN_HPP
#define ABOUTSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;
#include <vector>

class AboutScreen : public cscreen
{
private:
   
public:
    AboutScreen();
    ~AboutScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& MainMenu, vector<wstring>*& passedContent);
    virtual void render(sf::RenderWindow& App);
};


#endif