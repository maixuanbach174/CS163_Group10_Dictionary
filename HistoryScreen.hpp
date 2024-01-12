#ifndef HISTORYSCREEN_HPP
#define HISTORYSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include "TitleBar.hpp"
#include <string>
#include <vector>
#include "TextList.hpp"
using namespace std;

class HistoryScreen : public cscreen
{
public:
    TitleBar titleBar;
public:
    TextList textList;
public:
    HistoryScreen();
    ~HistoryScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
    void HandleScroll(int delta);
};


#endif