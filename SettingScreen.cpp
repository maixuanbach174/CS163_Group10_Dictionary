#include "SettingScreen.hpp"

SettingScreen::SettingScreen() 
{
    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color(100, 100, 255, 255));
    titleBar.lineshape.setFillColor(sf::Color(50, 50, 100, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Setting");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;
    
    for(int i = 0; i < 3; ++i)
    {
        selectButtons[i].border.setRadius(15);
        selectButtons[i].reset();
    }

    selectButtons[0].border.setRadius(13);
    selectButtons[0].border.setOutlineThickness(5);
    selectButtons[0].border.setOutlineColor(sf::Color(100, 100, 255, 255));
    selectButtons[0].border.setFillColor(sf::Color(30, 30, 75, 255));

    selectButtons[0].border.setPosition(150.f, 280.f);
    selectButtons[1].border.setPosition(150.f, 380.f);
    selectButtons[2].border.setPosition(150.f, 480.f);

    selectButtons[0].border.setPosition(150.f + 2.f, 280.f + 2.f);

    selectButtons[0].selectText.setString("English-English");
    selectButtons[1].selectText.setString("English-Vietnamese");
    selectButtons[2].selectText.setString("Vietnamese-English");

    selectButtons[0].selectText.setPosition(200.f, 278.f);
    selectButtons[1].selectText.setPosition(200.f, 378.f);
    selectButtons[2].selectText.setPosition(200.f, 478.f);

    titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    titleText.setFont(titleFont);
    titleText.setFillColor(sf::Color::White);
    titleText.setCharacterSize(30);
    titleText.setString("Swap languages:");
    titleText.setPosition(150.f, 178);

    modeFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    modeText.setFont(modeFont);
    modeText.setFillColor(sf::Color::White);
    modeText.setCharacterSize(30);
    modeText.setString("Swap mode:");
    modeText.setPosition(150.f, 578.f);

    for(int i = 0; i < 2; ++i)
    {
       options[i].border.setRadius(15);
       options[i].reset();
    }

   options[0].border.setRadius(13);
   options[0].border.setOutlineThickness(5);
   options[0].border.setOutlineColor(sf::Color(100, 100, 255, 255));
   options[0].border.setFillColor(sf::Color(30, 30, 75, 255));

   options[0].border.setPosition(150.f, 680.f);
   options[1].border.setPosition(150.f, 780.f);

   options[0].border.setPosition(150.f + 2.f, 680.f + 2.f);

   options[0].selectText.setString("Search for a keyword");
   options[1].selectText.setString("Search for a definition");

   options[0].selectText.setPosition(200.f, 678.f);
   options[1].selectText.setPosition(200.f, 778.f);
}

SettingScreen::~SettingScreen() {}

void SettingScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
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
                for(int i = 0; i < 3; ++i)
                {
                    if(selectButtons[i].IsInBound(mousepos))
                    {
                        if(i != dataSet)
                        {
                            selectButtons[dataSet].reset();
                            selectButtons[i].set();
                            dataSet = i;
                        }

                        break;
                    }
                }

                for(int i = 0; i < 2; ++i)
                {
                    if(options[i].IsInBound(mousepos))
                    {
                        if(i != mode)
                        {
                            options[mode].reset();
                            options[i].set();
                            mode = i;
                        }

                        break;
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}

void SettingScreen::update(MainMenu& mainmenu, vector<vector<wstring>*>& passedContent)
{
     if(mainmenu.openedMenu != titleBar.isMove)
    {
        if(mainmenu.openedMenu)
        {
            titleBar.Move(mainmenu.movement);
            titleText.move(mainmenu.movement);
            for(int i = 0; i < 3; ++i)
            {
                selectButtons[i].border.move(mainmenu.movement);
                selectButtons[i].selectText.move(mainmenu.movement);
            }

            modeText.move(mainmenu.movement);
            for(int i = 0; i < 2; ++i)
            {
                options[i].border.move(mainmenu.movement);
                options[i].selectText.move(mainmenu.movement);
            }
        } else
        {
            titleBar.Move(-1.f * mainmenu.movement);
            titleText.move(-1.f * mainmenu.movement);
             for(int i = 0; i < 3; ++i)
            {
                selectButtons[i].border.move(-1.f * mainmenu.movement);
                selectButtons[i].selectText.move(-1.f * mainmenu.movement);
            }
            modeText.move(-1.f * mainmenu.movement);
            for(int i = 0; i < 2; ++i)
            {
                options[i].border.move(-1.f * mainmenu.movement);
                options[i].selectText.move(-1.f * mainmenu.movement);
            }
        }

        titleBar.isMove = mainmenu.openedMenu;
    }
}

void SettingScreen::render(sf::RenderWindow& App)
{
    App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);
    
    App.draw(titleText);
    for(int i = 0; i < 3; ++i)
    {
        App.draw(selectButtons[i].border);
        App.draw(selectButtons[i].selectText);
    }

    App.draw(modeText);

    for(int i = 0; i < 2; ++i)
    {
        App.draw(options[i].border);
        App.draw(options[i].selectText);
    }
}