#include "FavouriteScreen.hpp"

FavouriteScreen::FavouriteScreen() 
: textList(sf::Color(100, 0, 0, 255))
{
    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color::Red);
    titleBar.lineshape.setFillColor(sf::Color(100, 0, 0, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Favourite");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;
}

FavouriteScreen::~FavouriteScreen() {}

void FavouriteScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
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
            break;
        case sf::Event::GainedFocus:
            mainmenu.mIsPaused = false;
            break;
        case sf::Event::LostFocus : 
            mainmenu.mIsPaused = true;
            break;
        case sf::Event::MouseMoved :
            mainmenu.HandleMenuColor(App);
            textList.HandleTextListColor(sf::Mouse::getPosition(App));
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                if(textList.inBound != -1)
                {
                    screenIndex = 6;
                    input = textList.contents[textList.inBound]->getString(); 
                    textList.buttons[textList.inBound]->setFillColor(sf::Color::Transparent);           
                }
            }
            break;
        default:
            break;
        }
    }
}

void FavouriteScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent)
{
    if(mainmenu.openedMenu != titleBar.isMove)
    {
        if(mainmenu.openedMenu)
        {
            titleBar.Move(mainmenu.movement);
            for(auto &i : textList.contents)
            {
                i->move(mainmenu.movement);
            }

            for(auto &i : textList.buttons)
            {
                i->move(mainmenu.movement);
            }
        } else
        {
            titleBar.Move(-1.f * mainmenu.movement);

            for(auto &i : textList.contents)
            {
                i->move(-1.f * mainmenu.movement);
            }

            for(auto &i : textList.buttons)
            {
                i->move(-1.f * mainmenu.movement);
            }
        }

        titleBar.isMove = mainmenu.openedMenu;
    }
}

void FavouriteScreen::render(sf::RenderWindow& App)
{
    App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);

    for(auto &i : textList.buttons)
    {
        App.draw(*i);
    }

    for(auto &i : textList.contents)
    {
        App.draw(*i);
    }
}