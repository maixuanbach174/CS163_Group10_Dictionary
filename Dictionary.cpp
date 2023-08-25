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
    // loadTrie("DataSave/EEdata.txt", eewords, eedefs, eeexamples);
    // loadTrie("DataSave/EVdata.txt", evwords, evdefs, evexamples);
    // loadTrie("DataSave/VEdata.txt", vewords, vedefs, veexamples);
    readEmoji(emoji, emojiDef);

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

    for(int i = 0; i < emoji.size(); ++i)
    {
        VieInsert(emojiroot, emoji[i], i);
    }
    passedContent.resize(2);
    srand(time(0));
}

Dictionary::~Dictionary() {
    saveTrie("DataSave/EEdata.txt", eewords, eedefs, eeexamples);
    saveTrie("DataSave/EVdata.txt", evwords, evdefs, evexamples);
    saveTrie("DataSave/VEdata.txt", vewords, vedefs, veexamples);
    deallocate(EVroot);
    deallocate(EEroot);
    Viedeallocate(VEroot);
    deallocate(VErootdef);
    deallocate(EErootdef);
    Viedeallocate(EVrootdef);
    Viedeallocate(emojiroot);
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
    if(settingscreen.isReset)
    {
        deallocate(EVroot);
        deallocate(EEroot);
        Viedeallocate(VEroot);
        deallocate(VErootdef);
        deallocate(EErootdef);
        Viedeallocate(EVrootdef);
        Viedeallocate(emojiroot);
        eewords.clear();
        eedefs.clear();
        eeexamples.clear();
        evwords.clear();
        evdefs.clear();
        evexamples.clear();
        vewords.clear();
        vedefs.clear();
        veexamples.clear();
        emoji.clear();
        emojiDef.clear();
        readDatasetEngVie(evwords, evdefs, evexamples);
        readEngEng(eewords, eedefs, eeexamples);
        VieEng(vewords, vedefs, veexamples);
        readEmoji(emoji, emojiDef);
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
        
        settingscreen.isReset = 0;
    }
    if(mainmenu.menubuttons.selected == 4 && quizscreen.isNext)
    {
        quizscreen.index = settingscreen.mode;
        switch (settingscreen.mode)
        {
        case 0:
            switch (settingscreen.dataSet)
            {
            case 0:
                quizscreen.random = getRandomWord(eewords, eedefs, quizscreen.correct);
                break;
            case 1:
                quizscreen.random = getRandomWord(evwords, evdefs, quizscreen.correct);
                break;
            case 2:
                quizscreen.random = getRandomWord(vewords, vedefs, quizscreen.correct);
                break;
            }
            break;
        case 1:
            switch (settingscreen.dataSet)
            {
            case 0:
                quizscreen.random = getRandomDefintion(eedefs, eewords, quizscreen.correct);
                break;
            case 1:
                quizscreen.random = getRandomDefintion(evdefs, evwords, quizscreen.correct);
                break;
            case 2:
                quizscreen.random = getRandomDefintion(vedefs, vewords, quizscreen.correct);
                break;
            }
            break;
        
        default:
            break;
        }
    }

    if(mainmenu.menubuttons.selected == 0 && homescreen.isNext)
    {
        homescreen.words.clear();
        switch (settingscreen.dataSet)
        {
        case 0:
            randomEngEngWord();
            break;
        case 1:
            randomEngVieWord();
            break;
        case 2:
            randomVieEngWord();
            break;
        }
    }
    searchscreen.isSearchDef = homescreen.isSearchDef = settingscreen.mode;
    if(searchscreen.isDel)
    {
        switch (settingscreen.dataSet)
        {
        case 0:
            if(prev != L"")
            {
                EEroot = erase(EEroot, prev);
                for(auto &def : eedefs[prevIndex])
                {
                    EErootdef = eraseTrieDef(EErootdef, def, prevIndex);
                }
                eedefs.erase(eedefs.begin() + prevIndex);
                eewords.erase(eewords.begin() + prevIndex);
                eeexamples.erase(eeexamples.begin() + prevIndex);
            }
            break;
        case 1:
            if(prev != L"")
            {
                EVroot = erase(EVroot, prev);
                evdefs.erase(evdefs.begin() + prevIndex);
                evwords.erase(evwords.begin() + prevIndex);
                evexamples.erase(evexamples.begin() + prevIndex);
            }

            break;
        case 2:
            if(prev != L"")
            {
                VEroot = VieErase(VEroot, prev);
                for(auto &def : eedefs[prevIndex])
                {
                    VErootdef = eraseTrieDef(VErootdef, def, prevIndex);
                }
                vedefs.erase(vedefs.begin() + prevIndex);
                vewords.erase(vewords.begin() + prevIndex);
                veexamples.erase(veexamples.begin() + prevIndex);
            }
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
        screenIndex = -1;
        searchscreen.isSearchDef = false;
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
        case 3:
            handleEmojiSearch();
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
        screenIndex = -1;
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

void Dictionary::handleEmojiSearch()
{
    if(input != L"")
    {
        VieTrieNode* temp = VieFind(emojiroot, input);
        if(!temp) 
        {
            passedContent[0] = nullptr;
            passedContent[1] = nullptr;
            prevIndex = -1;
            prev = L"";
        } else 
        {
            prev = input;
            passedContent[0] = &emojiDef[temp->value[0]];
            passedContent[1] = nullptr;
            prevIndex = temp->value[0];
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
        CurScreen = screenIndex;
    }

    handleFavourite();
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
            prevIndex = -1;
            prev = L"";
        } else 
        {
            prev = input;
            passedContent[0] = &evdefs[temp->value[0]];
            passedContent[1] = &evexamples[temp->value[0]];
            prevIndex = temp->value[0];
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
            prevIndex = -1;
        }
        else 
        {
            prev = input;
            passedContent[0] = &eedefs[temp->value[0]];
            passedContent[1] = &eeexamples[temp->value[0]];
            prevIndex = temp->value[0];
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
            prevIndex = -1;
        }
        else 
        {
            prev = input;
            passedContent[0] = &vedefs[temp->value[0]];
            passedContent[1] = &veexamples[temp->value[0]];
            prevIndex = temp->value[0];
            handleHistory();
        }
        handleFavouriteColor();
        input = L"";
    }
    CurScreen = screenIndex;

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
        hintscreen.textList.clearAll();
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
    }
    CurScreen = screenIndex;
    
}

void Dictionary::handleVieEngDefSearch()
{
    if(input != L"")
    {
        vector<int> temp = finddef(VErootdef, input);
        hintscreen.textList.clearAll();
        if(temp.empty())
        {
            hintscreen.textList.addText(L"Not Found!", 0);
            prev = L"";
        } else
        {
            prev = input;
            for(int i = 0; i < temp.size(); i++)
            {
                hintscreen.textList.addText(vewords[temp[i]], i);
            }
            handleHistory();
        }
        input = L"";
        CurScreen = screenIndex;
      prevScreen = CurScreen;
    }
      
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

TrieNode * Dictionary::eraseTrieDef(TrieNode * root, wstring def, int index)
{
    vector<wstring> words = splitToWords(def);
     wcout << "hihi" << endl;
    for(auto &w : words)
    {
        root = eraseOneIndex(root, w, index);
    }
    return root;
}

void Dictionary::randomEngEngWord()
{
    for(int i = 0; i < 6; ++i)
    {
        int index = rand() % eewords.size();
        homescreen.words.push_back(eewords[index]);
    }
}

void Dictionary::randomEngVieWord()
{
    for(int i = 0; i < 6; ++i)
    {
        int index = rand() % evwords.size();
        homescreen.words.push_back(evwords[index]);
    }
}

void Dictionary::randomVieEngWord()
{
    for(int i = 0; i < 6; ++i)
    {
        int index = rand() % vewords.size();
        homescreen.words.push_back(vewords[index]);
    }
}
