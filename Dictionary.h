#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "MenuButtons.h"
using namespace std;

class Dictionary
{
private:
    bool mIsPaused;
    bool openedMenu;
    bool outofMenu;
    MenuButtons menubuttons;
private:
    sf::RenderWindow mWindow;
    sf::Texture HomeTexture;
    sf::Sprite MenuHome;
    sf::Texture HistoryTexture;
    sf::Sprite MenuHistory;
    sf::Texture FavoriteTexture;
    sf::Sprite MenuFavorite;
    sf::Texture LinesTexture;
    sf::Sprite MenuLines;
    Button LinesButton;
    sf::Texture SettingTexture;
    sf::Sprite MenuSetting;
    sf::Texture QuizTexture;
    sf::Sprite MenuQuiz;
    sf::Texture AboutTexture;
    sf::Sprite MenuAbout;
    sf::Color DarkGrey;
    sf::RectangleShape Menu;
    sf::Color LightGrey;
    sf::Font MenuFont;
    sf::Text MenuTexts[6];
    sf::Color MenButCol;
private:
    sf::Vector2f movement;
private:
    void processEvent();
    void update();
    void render();
    void HandleUserInput(sf::Keyboard::Key key);
    void HandleMenuColor();
    void HandleMenuClick(sf::Vector2i mousepos);
public:
    Dictionary();
    ~Dictionary();
    void run();

};


#endif