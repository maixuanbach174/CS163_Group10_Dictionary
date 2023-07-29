#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, myHashMap(100000)
{
    root = new TrieNode();
    readDatasetEngVie(root);
    // readEngEng(root);
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
    if(mainmenu.menubuttons.selected != prevScreen)
    {
        CurScreen = mainmenu.menubuttons.selected;
        prevScreen = mainmenu.menubuttons.selected;
    } else if(screenIndex == 6)
    {
        if(input != L"")
        {
            TrieNode* temp = find(root, input);
            if(!temp) passedContent = L"Not found!";
            else 
            {
                passedContent = temp->definition;
                if(prevScreen == 0 && myHashMap.find(input) == nullptr) 
                {
                    historyscreen.textList.addText(input);
                    myHashMap.insert(input, 1);
                    if(historyscreen.titleBar.isMove && historyscreen.textList.contents.size() == 1) 
                    {
                        historyscreen.textList.contents.back()->move(mainmenu.movement);
                        historyscreen.textList.buttons.back()->move(mainmenu.movement);
                    }
                }
            }
            input = L"";
            CurScreen = screenIndex;
        }
    } else
    {
        CurScreen = prevScreen;
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
