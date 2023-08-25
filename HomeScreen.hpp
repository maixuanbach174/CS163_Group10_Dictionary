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
#include "TextList2.hpp"
using namespace std;

class HomeScreen : public cscreen
{
public:
    int isSearchDef = 0;
    vector<wstring> words;
    bool isNext = true;
    bool isMove = false;
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
    sf::Sprite resetSprite;
    sf::Texture resetTexture;
    sf::RectangleShape randomBox;
    sf::Text randomTitle;
    sf::RectangleShape lineShade;
    TextList2 randomList;
    sf::Sprite reloadSprite;
    sf::Texture reloadTexture;
    Button reloadButton;
private:
    void HandleSearchColor(sf::RenderWindow& App);
    int HandleSearchClick(sf::Vector2i mousepos);
    void HandleReloadColor(sf::RenderWindow& App);
    void HandleReloadClick(sf::Vector2i mousepos);

public:
    HomeScreen();
    ~HomeScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
   
};

#endif