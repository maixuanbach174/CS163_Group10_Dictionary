#include "HomeScreen.hpp"

HomeScreen::HomeScreen()
: searchbox(450.f, 50.f, 8.f)
, searchbutton(50, 33, 1393.f, 65.f)
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, cursor(3.0f, 32.f)
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
}

HomeScreen::~HomeScreen() {}

void HomeScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu)
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
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                HandleSearchClick(mousepos);
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
            isTyping = true;
            break;
        default:
            break;
        }
    }
}

void HomeScreen::update() {

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
}

void HomeScreen::render(sf::RenderWindow& App)
{
    App.draw(searchbox.box);
    App.draw(searchbox.line);
    App.draw(searchbutton.rect);
    App.draw(SearchSprite);
    App.draw(VieSearchText);
    if(cursor.showCursor) App.draw(cursor.cursorShape);
}

void HomeScreen::HandleSearchColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);
    if(searchbutton.isInBound(mousepos))
    {
        searchbutton.rect.setFillColor(sf::Color(100, 100, 100, 255));
    } else searchbutton.rect.setFillColor(sf::Color::Transparent);
}

void HomeScreen::HandleSearchClick(sf::Vector2i mousepos)
{
    if(searchbox.isInBound(mousepos))
    {
        searchbox.setColor(sf::Color(20, 20, 20, 255), sf::Color(200, 100, 0));
        IsSearching = true;
    } else
    {
        searchbox.setColor(LightGrey, sf::Color::White);
        IsSearching = false;
    }
}

