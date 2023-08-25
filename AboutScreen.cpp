#include "AboutScreen.hpp"

AboutScreen::AboutScreen() 
: cursor(5.0f, 45.f)
, textList(sf::Color(50, 50, 100, 255))
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
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                textList.HandleTextList3Color(mousepos);
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
}