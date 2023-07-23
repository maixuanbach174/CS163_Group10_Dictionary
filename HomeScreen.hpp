#ifndef HOMESCREEN_HPP
#define HOMESCREEN_HPP

#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Button.h"
#include <iostream>
#include "MainMenu.hpp"
#include "cscreen.hpp"
#include <string>
#include "Cursor.hpp"
using namespace std;

class HomeScreen : public cscreen
{
private:
    sf::Texture SearchTexture;
    sf::Sprite SearchSprite;
    TextBox searchbox;
    sf::Text searchtext;
    sf::Font searchfont;
    Button searchbutton;
    sf::Font VieSearchFont;
    sf::Text VieSearchText;
    sf::Color DarkGrey;
    sf::Color LightGrey;
    bool IsSearching = false;
    wstring InputText;
    Cursor cursor;
    sf::Clock cursorTimer;
    bool isTyping = false;
private:
    void HandleSearchColor(sf::RenderWindow& App);
    int HandleSearchClick(sf::Vector2i mousepos);
public:
    HomeScreen();
    ~HomeScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input, sf::View& view);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
   
};

#endif