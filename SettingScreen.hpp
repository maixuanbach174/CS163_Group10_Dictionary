#ifndef SETTINGSCREEN_HPP
#define SETTINGSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "SelectButton.hpp"
#include "TitleBar.hpp"
#include "Button.h"
using namespace std;

class SettingScreen : public cscreen
{
public:
    int dataSet = 0;
    int mode = 0;
    int isReset = 0;
private:
    TitleBar titleBar;
    SelectButton selectButtons[4];
    SelectButton options[2];
    sf::Font titleFont;
    sf::Text titleText;
    sf::Font modeFont;
    sf::Text modeText;
    sf::Sprite resetSprite;
    sf::Texture resetTexture;
    sf::Text resetText;
    Button resetButton;
public:
    SettingScreen();
    ~SettingScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
    void HandleResetColor(sf::RenderWindow& App);
    int HandleResetClick(sf::Vector2i mousepos);
};

#endif