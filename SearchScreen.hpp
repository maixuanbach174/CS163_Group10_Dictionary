#ifndef SEARCHSCREEN_HPP
#define SEARCHSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "cscreen.hpp"
#include "TitleBar.hpp"
#include "string"
#include "Button.h"
#include "ScrollBar.hpp"
#include "FavouriteButton.hpp"
#include "Announcement.hpp"
#include "TextList.hpp"
#include "Cursor.hpp"
using namespace std;

class SearchScreen : public cscreen
{
public:
    sf::Sprite closeSprite;
    FavouriteButton favouriteButton;
    bool isEdit = false;
    bool isDel = false;
    int isSearchDef = 0;
    vector<vector<wstring>*> content;
private:
    bool isLocked = false;
    TitleBar titleBar;
    Button closeButton;
    sf::Texture closeTexture;
    ScrollBar scrollBar;
    TextList textlist;
    TextList textlist_def;
    TextList textlist_ex;
    sf::Texture editTexture;
    sf::Sprite editSprite;
    Button editButton;
    Cursor cursor;
    sf::Clock cursorTimer;
    bool isTyping = false;
    sf::Texture binTexture;
    sf::Sprite binSprite;
    Button binButton;
public:
    SearchScreen();
    ~SearchScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
    void HandleCloseColor(sf::RenderWindow& App);
    int HandleCloseClick(sf::Vector2i mousepos);
    void HandleEditClick(sf::Vector2i mousepos);
    void HandleBinColor(sf::RenderWindow& App);
    int HandleBinClick(sf::Vector2i mousepos);
    void HandleScroll(int delta);
};



#endif