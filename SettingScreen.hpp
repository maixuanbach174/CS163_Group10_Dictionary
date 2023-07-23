#ifndef SETTINGSCREEN_HPP
#define SETTINGSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;

class SettingScreen : public cscreen
{
private:
    
public:
    SettingScreen();
    ~SettingScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input, sf::View& view);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
};

#endif