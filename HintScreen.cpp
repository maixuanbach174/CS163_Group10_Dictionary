#include "HintScreen.hpp"

HintScreen::HintScreen() 
: textList(sf::Color(50, 50, 100, 255))
,closeButton(70, 50, 1180, 25)
{
    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color(100, 100, 255, 255));
    titleBar.lineshape.setFillColor(sf::Color(50, 50, 100, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Suggestions");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;
    closeTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/CloseButton.png");
    closeSprite.setTexture(closeTexture);
    closeSprite.setColor(sf::Color::Red);
    closeSprite.setPosition(1200, 35);
}

HintScreen::~HintScreen() {}

void HintScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
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
        case sf::Event::MouseWheelMoved:
            HandleScroll(event.mouseWheel.delta);
            break;
        case sf::Event::MouseMoved :
            mainmenu.HandleMenuColor(App);
            HandleCloseColor(App);
            textList.HandleTextListColor(sf::Mouse::getPosition(App));
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                if(screenIndex != -1) screenIndex = HandleCloseClick(mousepos);
                if(textList.inBound != -1 && textList.contents[0]->getString() != L"Not Found!")
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

void HintScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent)
{

    if(mainmenu.openedMenu != titleBar.isMove)
    {
        if(mainmenu.openedMenu)
        {
            titleBar.Move(mainmenu.movement);
            closeSprite.move(mainmenu.movement);
            closeButton.rect.move(mainmenu.movement);
            closeButton.position += mainmenu.movement;
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
            closeSprite.move(-1.f * mainmenu.movement);
            closeButton.rect.move(-1.f * mainmenu.movement);
            closeButton.position += -1.f * mainmenu.movement;
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

void HintScreen::render(sf::RenderWindow& App)
{

    for(auto &i : textList.buttons)
    {
        App.draw(*i);
    }

    for(auto &i : textList.contents)
    {
        App.draw(*i);
    }

    App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);
    App.draw(closeButton.rect);
    App.draw(closeSprite);
}

void HintScreen::HandleCloseColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(closeButton.isInBound(mousepos))
    {
        closeButton.rect.setFillColor(sf::Color(50, 50, 100, 255));
    } else closeButton.rect.setFillColor(sf::Color::Transparent);
}

int HintScreen::HandleCloseClick(sf::Vector2i mousepos)
{
    if(closeButton.isInBound(mousepos))
    {
        closeButton.rect.setFillColor(sf::Color::Transparent);
        if(textList.inBound != -1)
        {
            textList.buttons[textList.inBound]->setFillColor(sf::Color::Transparent);
            textList.inBound = -1;
        }
        return -1;
    }
    return 7;
}

void HintScreen::HandleScroll(int delta)
{
    if((delta > 0 && textList.contents[0]->getPosition().y < 197)
    || (delta < 0 && textList.contents[textList.contents.size() - 1]->getPosition().y + textList.contents[textList.contents.size() - 1]->getLocalBounds().height > 918))
    {
        textList.moveText(float(delta) * sf::Vector2f(0, 60));
    }
}