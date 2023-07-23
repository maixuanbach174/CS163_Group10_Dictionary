#ifndef HISTORYSCREEN_HPP
#define HISTORYSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;

class HistoryScreen : public cscreen
{
private:
   
public:
    HistoryScreen();
    ~HistoryScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& mainmenu, wstring& passedContent);
    virtual void render(sf::RenderWindow& App);
};


#endif