#ifndef SETTINGSCREEN_HPP
#define SETTINGSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "SelectButton.hpp"
#include "TitleBar.hpp"
using namespace std;

class SettingScreen : public cscreen
{
public:
    int dataSet = 0;
private:
    TitleBar titleBar;
    SelectButton selectButtons[3];
    sf::Font titleFont;
    sf::Text titleText;
public:
    SettingScreen();
    ~SettingScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
};

#endif