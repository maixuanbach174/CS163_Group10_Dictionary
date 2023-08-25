#ifndef ABOUTSCREEN_HPP
#define ABOUTSCREEN_HPP

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
using namespace std;
#include <vector>
#include <string>
#include "Cursor.hpp"
#include "TextList.hpp"
#include "TextList3.hpp"

class AboutScreen : public cscreen
{
public:
    vector<wstring> content;
    bool init = true;
private:
    Cursor cursor;
    sf::Clock cursorTimer;
    bool isTyping = false;
    TextList3 textList;
    sf::Font font;
    vector<sf::Text> text;
public:
    AboutScreen();
    ~AboutScreen();
    virtual void processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input);
    virtual void update(MainMenu& MainMenu, vector<vector<wstring>*>& passedContent);
    virtual void render(sf::RenderWindow& App);
};


#endif