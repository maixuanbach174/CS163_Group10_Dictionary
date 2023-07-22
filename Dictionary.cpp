#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
{
    root = new TrieNode();
    readDatasetEngVie(root);
    screens.push_back(&homescreen);
    screens.push_back(&historyscreen);
    screens.push_back(&favouritescreen);
    screens.push_back(&settingscreen);
    screens.push_back(&quizscreen);
    screens.push_back(&aboutscreen);
    screens.push_back(&searchscreen);
}

Dictionary::~Dictionary() {
    deallocate(root);
}

void Dictionary::run()
{
    while (mWindow.isOpen())
    {
        processEvent();
        
        if(!mainmenu.mIsPaused)
        update();

        render();
    }
}

void Dictionary::processEvent()
{
    screens[CurScreen]->processEvent(mWindow, mainmenu, screenIndex, input);
}

void Dictionary::update()
{
    if(mainmenu.menubuttons.selected == 0 && screenIndex != -1) 
    {
        if(screenIndex == 6)
        {
            TrieNode* temp = find(root, input);
            if(!temp) passedContent = L"Not found!";
            else passedContent = temp->definition;
        }
        CurScreen = screenIndex;
    }
    else 
    {
        screenIndex = -1;
        CurScreen = mainmenu.menubuttons.selected;
    } 

    screens[CurScreen]->update(mainmenu, passedContent);
}

void Dictionary::render()
{
    mWindow.clear(DarkGrey);
    mainmenu.render(mWindow);
    screens[CurScreen]->render(mWindow); 
    mWindow.display();
}
