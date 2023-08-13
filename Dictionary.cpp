#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, EVHistory(100000)
, EVFavourite(100000)
{
    readDatasetEngVie(evwords, evdefs, evexamples);
    readEngEng(eewords, eedefs, eeexamples);
    VieEng(vewords, vedefs, veexamples);
    screens.push_back(&homescreen);
    screens.push_back(&historyscreen);
    screens.push_back(&favouritescreen);
    screens.push_back(&settingscreen);
    screens.push_back(&quizscreen);
    screens.push_back(&aboutscreen);
    screens.push_back(&searchscreen);
    screens.push_back(&hintscreen);

    for(int i = 0; i < eewords.size(); i++)
    {
        insert(EEroot, eewords[i], i);
        for(int j = 0; j < eedefs[i].size(); j++)
        {
            insertdef(EErootdef, eedefs[i][j], i);
        }
    }

    for(int i = 0; i < vewords.size(); i++)
    {
        VieInsert(VEroot, vewords[i], i);
        for(int j = 0; j < vedefs[i].size(); ++j)
        {
            insertdef(VErootdef, vedefs[i][j], i);
        }
    }

    for(int i = 0; i < evwords.size(); i++)
    {
        insert(EVroot, evwords[i], i);
        // for(int j = 0; j < evdefs[i].size(); j++)
        // {
        //     Vieinsertdef(EVrootdef, evdefs[i][j], i);
        // }
    }
    passedContent.resize(2);
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
            break;
        default:
            break;
        }

    } else if(screenIndex == 7)
    {
        switch (settingscreen.dataSet)
        {
        case 0:
            handleEngEngDefSearch();
            break;
        case 1:
            handleEngVieDefSearch();
            break;
        case 2:
            handleVieEngDefSearch();
            break;
        default:
            break;
        }
    } 
    else
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
            passedContent[0] = nullptr;
            passedContent[1] = nullptr;
            prev = L"";
        } else 
        {
            prev = input;
            passedContent[0] = &evdefs[temp->value[0]];
            passedContent[1] = &evexamples[temp->value[0]];
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
            passedContent[0] = nullptr;
            passedContent[1] = nullptr;
            prev = L"";
        }
        else 
        {
            prev = input;
            passedContent[0] = &eedefs[temp->value[0]];
            passedContent[1] = &eeexamples[temp->value[0]];
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
            passedContent[0] = nullptr;
            passedContent[1] = nullptr;
            prev = L"";
        }
        else 
        {
            prev = input;
            passedContent[0] = &vedefs[temp->value[0]];
            passedContent[1] = &veexamples[temp->value[0]];
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
        CurScreen = screenIndex;
    }

    handleFavourite();
}

void Dictionary::handleEngVieDefSearch()
{
    
}

void Dictionary::handleEngEngDefSearch()
{
    if(input != L"")
    {
        vector<int> temp = finddef(EErootdef, input);
        if(temp.empty())
        {
            hintscreen.textList.addText(L"Not Found!", 0);
            prev = L"";
        } else
        {
            prev = input;
            for(int i = 0; i < temp.size(); i++)
            {
                hintscreen.textList.addText(eewords[temp[i]], i);
            }
            handleHistory();
        }
        input = L"";
        CurScreen = screenIndex;
    }
}

void Dictionary::handleVieEngDefSearch()
{
    // if(input != L"")
    // {
    //     vector<int> temp = finddef(VErootdef, input);
    //       if(passedContent) 
    //     {
    //         delete passedContent;
    //         passedContent = nullptr;
    //         searchscreen.content = nullptr;
    //     }
    //     if(temp.empty()) 
    //     {
    //         passedContent = nullptr;
    //         prev = L"";
    //     }
    //     else 
    //     {
    //         prev = input;
    //         passedContent = new vector<wstring>;
    //         for(int i = 0; i < temp.size(); i++)
    //         {
    //             passedContent->push_back(vewords[temp[i]]);        
    //         }
    //         handleHistory();
    //     }
    //     handleFavouriteColor();
    //     input = L"";
    //     CurScreen = screenIndex;
    // }

    // handleFavourite();
}

void Dictionary::handleHistory()
{
    if(prevScreen == 0 && EVHistory.find(input) == nullptr) 
    {
        historyscreen.textList.addText(input, 0);
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
        favouritescreen.textList.addText(prev, 0);
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


