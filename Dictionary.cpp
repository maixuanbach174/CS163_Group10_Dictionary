#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, EVHistory(100000)
, EVFavourite(100000)
{
    EVroot = new TrieNode();
    readDatasetEngVie(EVroot);
    EEroot = new TrieNode();
    readEngEng(EEroot);
    VEroot = new VieTrieNode();
    VieEng(VEroot);
    screens.push_back(&homescreen);
    screens.push_back(&historyscreen);
    screens.push_back(&favouritescreen);
    screens.push_back(&settingscreen);
    screens.push_back(&quizscreen);
    screens.push_back(&aboutscreen);
    screens.push_back(&searchscreen);
}

Dictionary::~Dictionary() {
    // deallocate(EVroot);
    // deallocate(EEroot);
    // VieDeallocate(VEroot);
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
    if(searchscreen.isDel)
    {
        switch (settingscreen.dataSet)
        {
        case 0:
            if(prev != L"")
            EEroot = erase(EEroot, prev);
            break;
        case 1:
            if(prev != L"")
            EVroot = erase(EVroot, prev);
            break;
        case 2:
            if(prev != L"")
            VEroot = VieErase(VEroot, prev);
            break;
        
        default:
            break;
        }
        searchscreen.isDel = false;
    }

    if(mainmenu.menubuttons.selected != prevScreen)
    {
        CurScreen = mainmenu.menubuttons.selected;
        prevScreen = mainmenu.menubuttons.selected;
        if(searchscreen.isEdit)
        searchscreen.isEdit = false;
    } else if(screenIndex == 6)
    {
        switch (settingscreen.dataSet)
        {
        case 0:
            handleEngEngSearch();
            break;
        case 1:
            handleEngVieSearch();
            break;
        case 2:
            handleVieEngSearch();
        default:
            break;
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

void Dictionary::handleEngVieSearch()
{
    if(input != L"")
    {
        TrieNode* temp = find(EVroot, input);
        if(!temp) 
        {
            passedContent = nullptr;
            prev = L"";
        }
        else 
        {
            prev = input;
            passedContent = &temp->definition;
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
        CurScreen = screenIndex;
    }

    handleFavourite();
}

void Dictionary::handleEngEngSearch()
{
    if(input != L"")
    {
        TrieNode* temp = find(EEroot, input);
        if(!temp) 
        {
            passedContent = nullptr;
            prev = L"";
        }
        else 
        {
            prev = input;
            passedContent = &temp->definition;
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
        CurScreen = screenIndex;
    }

    handleFavourite();
}

void Dictionary::handleVieEngSearch()
{
    if(input != L"")
    {
        VieTrieNode* temp = VieFind(VEroot, input);
        if(!temp) 
        {
            passedContent = nullptr;
            prev = L"";
        }
        else 
        {
            prev = input;
            passedContent = &temp->definition;
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
        CurScreen = screenIndex;
    }

    handleFavourite();
}

void Dictionary::handleHistory()
{
    if(prevScreen == 0 && EVHistory.find(input) == nullptr) 
    {
        historyscreen.textList.addText(input);
        EVHistory.insert(input, 1);
        if(historyscreen.titleBar.isMove) 
        {
            historyscreen.textList.contents[0]->move(mainmenu.movement);
            historyscreen.textList.buttons[0]->move(mainmenu.movement);
        }
    }
}

void Dictionary::handleFavouriteColor()
{
    if(EVFavourite.find(input)) 
    {
        searchscreen.favouriteButton.isFavourite = true;
        searchscreen.favouriteButton.heartSprite.setColor(sf::Color::Red);
    } else
    {
        searchscreen.favouriteButton.isFavourite = false;
        searchscreen.favouriteButton.heartSprite.setColor(sf::Color::White);
    }
}

void Dictionary::handleFavourite()
{
    if(prev != L"" && searchscreen.favouriteButton.isFavourite && EVFavourite.find(prev) == nullptr)
    {
        EVFavourite.insert(prev, 1);
        favouritescreen.textList.addText(prev);
        if(favouritescreen.titleBar.isMove) 
        {
            favouritescreen.textList.contents[0]->move(mainmenu.movement);
            favouritescreen.textList.buttons[0]->move(mainmenu.movement);
        }
    }

    if(prev != L"" && !searchscreen.favouriteButton.isFavourite && EVFavourite.find(prev))
    {
        EVFavourite.erase(prev);
        favouritescreen.textList.removeText(prev);
    }
}


