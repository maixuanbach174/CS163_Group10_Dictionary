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
#include "MyHashMap.h"
#include "ReadEngEng.hpp"
#include "VieTrie.h"
#include "ReadVieEng.hpp"
#include "SearchByDef.hpp"
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
    HintScreen hintscreen;
    vector<cscreen*> screens;
    int CurScreen = 0;
    int screenIndex = -1;
    int prevScreen = 0;
    TrieNode * EVroot = nullptr;
    TrieNode * EEroot = nullptr;
    VieTrieNode * VEroot = nullptr;
    TrieNode * VErootdef = nullptr;
    TrieNode * EErootdef = nullptr;
    VieTrieNode * EVrootdef = nullptr;
    wstring input;
    wstring prev;
    vector<vector<wstring>*> passedContent;
    MyHashMap <wstring, int> EVHistory;
    MyHashMap <wstring, int> EVFavourite;
    vector<wstring> eewords;
    vector<vector<wstring>> eedefs;
    vector<vector<wstring>> eeexamples;
    vector<vector<wstring>> vedefs;
    vector<wstring> vewords;
    vector<vector<wstring>> veexamples;
    vector<wstring> evwords;
    vector<vector<wstring>> evdefs;
    vector<vector<wstring>> evexamples;
private:
    void processEvent();
    void update();
    void render();
    void handleEngVieSearch();
    void handleEngEngSearch();
    void handleVieEngSearch();
    void handleEngVieDefSearch();
    void handleEngEngDefSearch();
    void handleVieEngDefSearch();
    void handleHistory();
    void handleFavourite();
    void handleFavouriteColor();
public:
    Dictionary();
    ~Dictionary();
    void run();
    

};


#endif