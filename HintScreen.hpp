#ifndef HINTSCREEN_HPP
#define HINTSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "TitleBar.hpp"
#include <string>
#include <vector>
#include "TextList.hpp"
using namespace std;

class HintScreen : public cscreen
{
public:
    TitleBar titleBar;
public:
    TextList textList;
private:
    Button closeButton;
    sf::Texture closeTexture;
    sf::Sprite closeSprite;
public:
    HintScreen();
    ~HintScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
    void HandleCloseColor(sf::RenderWindow& App);
    int HandleCloseClick(sf::Vector2i mousepos);
    void HandleScroll(int delta);
};

#endif