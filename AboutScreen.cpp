#include "AboutScreen.hpp"

AboutScreen::AboutScreen() 
: cursor(5.0f, 45.f)
, textList(sf::Color(50, 50, 100, 255))
, tickButton(70, 50, 1180, 25)
{
    font.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    content.resize(3);  
    text.resize(3);
    for(int i = 0; i < 3; i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(35);
        text[i].setFillColor(sf::Color::White);
    }

    text[0].setString(L"Words:");
    text[1].setString(L"Definition:");
    text[2].setString(L"Example:");

    text[0].setPosition(150.f, 197);
    text[1].setPosition(150.f, 197 + 55);
    text[2].setPosition(150.f, 197 + 55 + 55);

    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color(100, 100, 255, 255));
    titleBar.lineshape.setFillColor(sf::Color(50, 50, 100, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Contribution");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;
    tickTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/TickIcon.png");
    tickSprite.setTexture(tickTexture);
    tickSprite.setPosition(1195, 31);
}

AboutScreen::~AboutScreen() {}

void AboutScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
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
            HandleTickColor(App);
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                textList.HandleTextList3Color(mousepos);
                HandleTickClick(mousepos);
            }
            break;
        case sf::Event::TextEntered:
             if(textList.inBound != -1)
            {
                if(event.text.unicode < 128 && event.text.unicode != '\b')
                {
                    content[textList.inBound] += wchar_t(event.text.unicode);
                } else if(event.text.unicode >= 128)
                {
                    content[textList.inBound] += event.text.unicode;
                } else if(!content[textList.inBound].empty()) content[textList.inBound].pop_back();

                int index = 0;
                textList.contents[textList.inBound]->setString(content[textList.inBound].substr(index, content[textList.inBound].size() - index));
                while( textList.contents[textList.inBound]->getLocalBounds().width > 1390)
                {
                    index++;
                    textList.contents[textList.inBound]->setString(content[textList.inBound].substr(index, content[textList.inBound].size() - index));
                }
                isTyping = true;
            }
        default:
            break;
        }
    }
}

void AboutScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent)
{
    if(init)
    {
        init = false;
        textList.clearAll();
        textList.addText(L"", 0);
        textList.addText(L"", 1);
        textList.addText(L"", 2);
    }

    if(textList.inBound != -1)
    {
        int si = textList.contents[textList.inBound]->getString().getSize();
        cursor.cursorShape.setPosition(textList.contents[textList.inBound]->findCharacterPos(si));
        if(isTyping) cursor.showCursor = true;
        else if(cursorTimer.getElapsedTime() >= cursor.cursorBlinkTime)
        {
            cursor.showCursor = !cursor.showCursor;
            cursorTimer.restart();
        }
        isTyping = false;
    } 

    if(textList.inBound == -1)
    {
        cursor.showCursor = false;
    }

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
            text[0].move(mainmenu.movement);
            text[1].move(mainmenu.movement);
            text[2].move(mainmenu.movement);
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
            text[0].move(-1.f * mainmenu.movement);
            text[1].move(-1.f * mainmenu.movement);
            text[2].move(-1.f * mainmenu.movement);
        }

        titleBar.isMove = mainmenu.openedMenu;
    }


}

void AboutScreen::render(sf::RenderWindow& App)
{
    for(auto &i : textList.buttons)
    {
        App.draw(*i);
    }

    for(auto &i : textList.contents)
    {
        App.draw(*i);
    }
     if(cursor.showCursor) App.draw(cursor.cursorShape);
      App.draw(text[0]);
    App.draw(text[1]);
    App.draw(text[2]);
     App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);
    App.draw(tickButton.rect);
    App.draw(tickSprite);
}

void AboutScreen::HandleTickColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(tickButton.isInBound(mousepos))
    {
        tickButton.rect.setFillColor(sf::Color(50, 50, 100, 255));
    } else tickButton.rect.setFillColor(sf::Color::Transparent);
}

void AboutScreen::HandleTickClick(sf::Vector2i mousepos)
{
    if(tickButton.isInBound(mousepos))
    {
        tickButton.rect.setFillColor(sf::Color::Transparent);
        isSave = true;
    }
}