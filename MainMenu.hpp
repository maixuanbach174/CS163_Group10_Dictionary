#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "MenuButtons.h"
#include "TextBox.h"
using namespace std;

class MainMenu
{
public:
    bool mIsPaused;
    bool openedMenu;
    bool outofMenu;
    MenuButtons menubuttons;
private:
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
public:
    void render(sf::RenderWindow& App);
    void HandleUserInput(sf::Keyboard::Key key, sf::RenderWindow& App);
    void HandleMenuColor(sf::RenderWindow& App);
    void HandleMenuClick(sf::Vector2i mousepos);
public:
    MainMenu();
    ~MainMenu();
};

#endif