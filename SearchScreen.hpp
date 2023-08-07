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
using namespace std;

class SearchScreen : public cscreen
{
public:
    sf::Sprite closeSprite;
    FavouriteButton favouriteButton;
private:
    TitleBar titleBar;
    vector<wstring>* content = nullptr;
    Button closeButton;
    sf::Texture closeTexture;
    ScrollBar scrollBar;
    TextList textlist;
    sf::Texture editTexture;
    sf::Sprite editSprite;
    Button editButton;
    bool isEdit = false;
public:
    SearchScreen();
    ~SearchScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<wstring>*& passedContent);
    virtual void render(sf::RenderWindow& App);
    void HandleCloseColor(sf::RenderWindow& App);
    int HandleCloseClick(sf::Vector2i mousepos);
    void HandleEditClick(sf::Vector2i mousepos);
    void HandleScroll(int delta);
};



#endif