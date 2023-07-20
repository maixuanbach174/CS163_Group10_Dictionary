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
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex);
    virtual void update(MainMenu& mainmenu);
    virtual void render(sf::RenderWindow& App);
};


#endif