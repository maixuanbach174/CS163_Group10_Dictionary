#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "MenuButtons.h"
#include "TextBox.h"
#include "screens.hpp"
#include "readDatasetEngVie.hpp"
using namespace std;

class Dictionary
{
private:
    sf::RenderWindow mWindow;
    sf::Color DarkGrey;
    sf::Color LightGrey;
    MainMenu mainmenu;
    HomeScreen homescreen;
    HistoryScreen historyscreen;
    FavouriteScreen favouritescreen;
    SettingScreen settingscreen;
    QuizScreen quizscreen;
    AboutScreen aboutscreen;
    SearchScreen searchscreen;
    vector<cscreen*> screens;
    int CurScreen = 0;
    int screenIndex = -1;
    TrieNode * root;
    wstring input;
    wstring passedContent;
private:
    void processEvent();
    void update();
    void render();
public:
    Dictionary();
    ~Dictionary();
    void run();

};


#endif