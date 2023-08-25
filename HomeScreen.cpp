#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
: searchbox(450.f, 50.f, 8.f)
, searchbutton(50, 33, 1393.f, 65.f)
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, cursor(3.0f, 32.f)
,randomList(sf::Color(50, 50, 100, 255))
, reloadButton(50, 50, 800.f, 255.f)
{
     if(!SearchTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/SearchIcon.png"));
    {
        cout << "Cannot load search icon" << endl;
    }
    SearchSprite.setTexture(SearchTexture);
    SearchSprite.setPosition(1400.f, 65.f);

    searchbox.setPos(sf::Vector2f(1000, 58.f));
    searchbox.setColor(LightGrey, sf::Color::White);

    searchbutton.rect.setFillColor(sf::Color::White);

    if(!VieSearchFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf"))
    {
        cout << "Cannot load font" << endl;
    }

    VieSearchText.setFont(VieSearchFont);
    VieSearchText.setPosition(1040.f, 67.f);
    VieSearchText.setCharacterSize(24);
    VieSearchText.setString(L"Search");

    cursor.cursorShape.setFillColor(sf::Color::White);

    randomBox.setSize(sf::Vector2f(700.f, 500.f));
    randomBox.setPosition(200.f, 250.f);
    randomBox.setOutlineColor(sf::Color(100, 100, 255, 255));
    randomBox.setOutlineThickness(6.f);
    randomBox.setFillColor(sf::Color::Transparent);

    lineShade.setFillColor(sf::Color(100, 100, 255, 255));
    lineShade.setSize(sf::Vector2f(700.f, 6.f));
    lineShade.setPosition(200.f, 300.f);

    randomTitle.setFont(VieSearchFont);
    randomTitle.setFillColor(sf::Color::White);
    randomTitle.setCharacterSize(30);
    randomTitle.setString(L"Random words");
    randomTitle.setPosition(250.f, 260.f);

    reloadTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/Reload.png");
    reloadSprite.setTexture(reloadTexture);
    reloadSprite.setPosition(800.f, 255.f);
}

HomeScreen::~HomeScreen() {}

void HomeScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
{
    sf::Event event;
    while(App.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            App.close();
            break;
        case sf::Event::KeyReleased:
            mainmenu.HandleUserInput(event.key.code, App);
            isTyping = true;
            break;
        case sf::Event::GainedFocus:
            mainmenu.mIsPaused = false;
            break;
        case sf::Event::LostFocus : 
            mainmenu.mIsPaused = true;
            break;
        case sf::Event::MouseMoved :
            mainmenu.HandleMenuColor(App);
            HandleSearchColor(App);
            randomList.HandleTextList2Color(sf::Mouse::getPosition(App));
            HandleReloadColor(App);
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                screenIndex = HandleSearchClick(mousepos);
                if(screenIndex == 6 && isSearchDef == 0)
                {
                    input = InputText;
                } else if(screenIndex == 6)
                {
                    screenIndex = 7;
                    input = InputText;
                }
                if(randomList.inBound != -1)
                {
                    screenIndex = 6;
                    input = randomList.contents[randomList.inBound]->getString(); 
                    randomList.buttons[randomList.inBound]->setFillColor(sf::Color::Transparent);           
                }
                HandleReloadClick(mousepos);
            }
            break;
        case sf::Event::TextEntered:
            if(IsSearching)
            {
                if(event.text.unicode < 128 && event.text.unicode != '\b')
                {
                    InputText += wchar_t(event.text.unicode);
                } else if(event.text.unicode >= 128)
                {
                    InputText += event.text.unicode;
                } else if(!InputText.empty()) InputText.pop_back();

                int index = 0;
                VieSearchText.setString(InputText.substr(index, InputText.size() - index));
                while(VieSearchText.getLocalBounds().width > 322)
                {
                    index++;
                    VieSearchText.setString(InputText.substr(index, InputText.size() - index));
                }
            }
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Enter && IsSearching)
            {
                input = InputText;
                if(isSearchDef == 0)
                    screenIndex = 6;
                else
                    screenIndex = 7;
                InputText = L"";
                IsSearching = false;
                cursor.showCursor = false;
                isTyping = false;
            }
            isTyping = true;
            break;
        default:
            break;
        }
    }
}

void HomeScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent) {

    if(!IsSearching && InputText.empty()) 
    {
        VieSearchText.setString("Search");
        cursor.showCursor = false;
    }
    else if(!IsSearching) cursor.showCursor = false;
    else {
        if(InputText.empty())
        {
            cursor.cursorShape.setPosition(VieSearchText.findCharacterPos(0));
        } else {
            float cursor_x = VieSearchText.findCharacterPos(VieSearchText.getString().getSize()).x;
            float cursor_y = VieSearchText.findCharacterPos(VieSearchText.getString().getSize()).y;
            cursor.cursorShape.setPosition(sf::Vector2f(cursor_x, cursor_y));
        }

        if(isTyping) cursor.showCursor = true;
        else if(cursorTimer.getElapsedTime() >= cursor.cursorBlinkTime)
        {
            cursor.showCursor = !cursor.showCursor;
            cursorTimer.restart();
        }
        isTyping = false;
    }

    if(isNext)
    {
        randomList.clearAll();
        for(auto& w : words)
        {
            randomList.addText(w, 0);
        }
        isNext = false;
    }

    if(mainmenu.openedMenu != isMove)
    {
        if(mainmenu.openedMenu)
        {
            randomBox.move(mainmenu.movement);
            lineShade.move(mainmenu.movement);
            randomTitle.move(mainmenu.movement);
            reloadButton.position += mainmenu.movement;
            reloadSprite.move(mainmenu.movement);
            for(auto &i : randomList.contents)
            {
                i->move(mainmenu.movement);
            }

            for(auto &i : randomList.buttons)
            {
                i->move(mainmenu.movement);
            }
        } else
        {
            randomBox.move(-1.f * mainmenu.movement);
            lineShade.move(-1.f * mainmenu.movement);
            randomTitle.move(-1.f * mainmenu.movement);
            reloadButton.position -= mainmenu.movement;
            reloadSprite.move(-1.f * mainmenu.movement);
            for(auto &i : randomList.contents)
            {
                i->move(-1.f * mainmenu.movement);
            }

            for(auto &i : randomList.buttons)
            {
                i->move(-1.f * mainmenu.movement);
            }
        }

        isMove = mainmenu.openedMenu;
    }
}

void HomeScreen::render(sf::RenderWindow& App)
{
    App.draw(searchbox.box);
    App.draw(searchbox.line);
    App.draw(searchbutton.rect);
    App.draw(SearchSprite);
    App.draw(VieSearchText);
    for(auto &i : randomList.buttons)
    {
        App.draw(*i);
    }

    for(auto &i : randomList.contents)
    {
        App.draw(*i);
    }
    App.draw(reloadButton.rect);
    App.draw(randomBox);
    App.draw(lineShade);
    App.draw(randomTitle);
    if(cursor.showCursor) App.draw(cursor.cursorShape);
    App.draw(reloadSprite);
}

void HomeScreen::HandleSearchColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);
    if(searchbutton.isInBound(mousepos))
    {
        searchbutton.rect.setFillColor(sf::Color(100, 100, 100, 255));
    } else searchbutton.rect.setFillColor(sf::Color::Transparent);
}

int HomeScreen::HandleSearchClick(sf::Vector2i mousepos)
{
    if(searchbutton.isInBound(mousepos) && InputText != L"") return 6;

    if(searchbox.isInBound(mousepos))
    {
        searchbox.setColor(sf::Color(20, 20, 20, 255), sf::Color(200, 100, 0));
        IsSearching = true;
    } else
    {
        searchbox.setColor(LightGrey, sf::Color::White);
        IsSearching = false;
    }

    return 0;
}

void HomeScreen::HandleReloadColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(reloadButton.isInBound(mousepos))
    {
        reloadButton.rect.setFillColor(sf::Color(50, 50, 100, 255));
    } else reloadButton.rect.setFillColor(sf::Color::Transparent);
}

void HomeScreen::HandleReloadClick(sf::Vector2i mousepos)
{
    if(reloadButton.isInBound(mousepos))
    {
        isNext = true;
    }
}

