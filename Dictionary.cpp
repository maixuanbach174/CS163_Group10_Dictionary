#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
{
    screens.push_back(&homescreen);
    screens.push_back(&historyscreen);
    screens.push_back(&favouritescreen);
    screens.push_back(&settingscreen);
    screens.push_back(&quizscreen);
    screens.push_back(&aboutscreen);
}

Dictionary::~Dictionary() {}

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
    screens[CurScreen]->processEvent(mWindow, mainmenu);
}

void Dictionary::update()
{
    if(mainmenu.menubuttons.selected >= 0 && mainmenu.menubuttons.selected <= 6) CurScreen = mainmenu.menubuttons.selected;

    screens[CurScreen]->update();
}

void Dictionary::render()
{
    mWindow.clear(DarkGrey);
    mainmenu.render(mWindow);
    screens[CurScreen]->render(mWindow); 
    mWindow.display();
}
