#include "Dictionary.h"

Dictionary::Dictionary() 
: mWindow(sf::VideoMode(1550, 1000), "Better Than Cambridge")
, mIsPaused(false)
, HomeTexture()
, HistoryTexture()
, MenuHistory()
, MenuHome()
, outofMenu(true)
, openedMenu(false)
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, MenButCol(250, 150, 100)
, menubuttons(350, 650, 0, 138)
, Menu(sf::Vector2f(350.f, 1000.f))
{
    Menu.setFillColor(LightGrey);
    for(int i = 0; i < 6; ++i)
    {
        MenuTexts[i].setFont(MenuFont);
        MenuTexts[i].setCharacterSize(30);
    }

    if(!LinesTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/LinesButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuLines.setTexture(LinesTexture);
    MenuLines.setScale(sf::Vector2f(50.f / LinesTexture.getSize().x * 0.75, 50.f / LinesTexture.getSize().y * 0.75));
    MenuLines.setPosition(30.f, 70.f);

    LinesButton.position = MenuLines.getPosition();
    LinesButton.width = 50 * 0.75;
    LinesButton.height = 50 * 0.75;

    if(!HomeTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/HomeButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuHome.setTexture(HomeTexture);
    MenuHome.setScale(sf::Vector2f(70.f /  HomeTexture.getSize().x * 0.75, 70.f / HomeTexture.getSize().y * 0.75));
    MenuHome.setPosition(22.f, 160.f);
    MenuTexts[0].setString("Home");
    MenuTexts[0].setPosition(145.f, 168.f);

    if(!HistoryTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/HistoryButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuHistory.setTexture(HistoryTexture);
    MenuHistory.setScale(sf::Vector2f(58.f / HistoryTexture.getSize().x * 0.75, 50.f / HistoryTexture.getSize().y * 0.75));
    MenuHistory.setPosition(25.f, 270.f);
    MenuTexts[1].setString("History");
    MenuTexts[1].setPosition(145.f, 272.f);

    if(!FavoriteTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/FavoriteButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuFavorite.setTexture(FavoriteTexture);
    MenuFavorite.setScale(sf::Vector2f(60.f / FavoriteTexture.getSize().x * 0.75,  60.f / FavoriteTexture.getSize().y * 0.75));
    MenuFavorite.setPosition(25.f, 370.f);
    MenuTexts[2].setString("Favorite");
    MenuTexts[2].setPosition(145.f, 377.f);

    if(!SettingTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/SettingButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuSetting.setTexture(SettingTexture);
    MenuSetting.setScale(sf::Vector2f(60.f / SettingTexture.getSize().x * 0.75,  60.f / SettingTexture.getSize().y * 0.75));
    MenuSetting.setPosition(25.f, 480.f);
    MenuTexts[3].setString("Setting");
    MenuTexts[3].setPosition(145.f, 486.f);

    if(!QuizTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/QuizButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuQuiz.setTexture(QuizTexture);
    MenuQuiz.setScale(sf::Vector2f(75.f / QuizTexture.getSize().x * 0.75,  75.f / QuizTexture.getSize().y * 0.75));
    MenuQuiz.setPosition(20.f, 590.f);
    MenuTexts[4].setString("Quiz");
    MenuTexts[4].setPosition(145.f, 596.f);

    if(!AboutTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/AboutButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuAbout.setTexture(AboutTexture);
    MenuAbout.setScale(sf::Vector2f(60.f / AboutTexture.getSize().x * 0.75,  60.f / AboutTexture.getSize().y * 0.75));
    MenuAbout.setPosition(25.f, 710.f);

    MenuTexts[5].setString("About");
    MenuTexts[5].setPosition(145.f, 714.f);


    if(!MenuFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf"))
    {
        cout << "Cannot load Font" << endl;
    }
    
}

Dictionary::~Dictionary() {}

void Dictionary::run()
{
    while (mWindow.isOpen())
    {
        processEvent();
        
        if(!mIsPaused)
        update();

        render();
    }
}

void Dictionary::processEvent()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::KeyReleased:
            HandleUserInput(event.key.code);
            break;
        case sf::Event::GainedFocus:
            mIsPaused = false;
            break;
        case sf::Event::LostFocus : 
            mIsPaused = true;
            break;
        case sf::Event::MouseMoved :
            if(openedMenu) HandleMenuColor();
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(mWindow);
                HandleMenuClick(mousepos);
            }
            break;
        default:
            break;
        }
    }
}

void Dictionary::update()
{

}

void Dictionary::render()
{
    mWindow.clear(DarkGrey);

    if(openedMenu) 
    {
        mWindow.draw(Menu);
        for(int i = 0; i < 6; ++i) mWindow.draw(menubuttons.buttons[i]);
        for(int i = 0; i < 6; ++i) mWindow.draw(MenuTexts[i]);
    }

    mWindow.draw(MenuHome);
    mWindow.draw(MenuHistory);
    mWindow.draw(MenuFavorite);
    mWindow.draw(MenuLines);
    mWindow.draw(MenuSetting);
    mWindow.draw(MenuQuiz);
    mWindow.draw(MenuAbout);
   
    mWindow.display();
}

void Dictionary::HandleUserInput(sf::Keyboard::Key key)
{
    if(key == sf::Keyboard::Escape) mWindow.close();
}

void Dictionary::HandleMenuColor()
{
    int index = menubuttons.isInBound(sf::Mouse::getPosition(mWindow));

    if(index == -1 && menubuttons.selected == -1 && menubuttons.selectMove == -1) return;

    menubuttons.MoveColor(index);
}

void Dictionary::HandleMenuClick(sf::Vector2i mousepos)
{
    if(LinesButton.isInBound(mousepos))
    {
        openedMenu = !openedMenu;
    }
                
    if(openedMenu)
    {
        int index = menubuttons.isInBound(mousepos);
        if(mousepos.x > 350) openedMenu = false;
        else
        {
            menubuttons.setColorButtons(index);
        }
    } 
}

