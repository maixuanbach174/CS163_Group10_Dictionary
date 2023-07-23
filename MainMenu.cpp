#include "MainMenu.hpp"

MainMenu::MainMenu() 
: mIsPaused(false)
, HomeTexture()
, HistoryTexture()
, MenuHistory()
, MenuHome()
, outofMenu(true)
, openedMenu(false)
, DarkGrey(30, 30, 30, 30)
, LightGrey(80, 80, 80, 80)
, MenButCol(250, 150, 100)
, menubuttons(350, 650, -250, 138)
, Menu(sf::Vector2f(350.f, 1000.f))
, movement(250, 0)
, LinesButton(100.f, 650.f / 6.f, 0, 138.f - 650.f / 6.f)
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
    MenuLines.setPosition(30.f, 65.f);

    if(!HomeTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/HomeButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuHome.setTexture(HomeTexture);
    MenuHome.setScale(sf::Vector2f(70.f /  HomeTexture.getSize().x * 0.75, 70.f / HomeTexture.getSize().y * 0.75));
    MenuHome.setPosition(22.f, 160.f);
    MenuTexts[0].setString("Home");
    MenuTexts[0].setPosition(145.f, 168.f);
    MenuHome.setColor(sf::Color(0, 0, 200, 255));

    if(!HistoryTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/HistoryButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuHistory.setTexture(HistoryTexture);
    MenuHistory.setScale(sf::Vector2f(58.f / HistoryTexture.getSize().x * 0.75, 50.f / HistoryTexture.getSize().y * 0.75));
    MenuHistory.setPosition(25.f, 280.f);
    MenuTexts[1].setString("History");
    MenuTexts[1].setPosition(145.f, 282.f);
    MenuHistory.setColor(sf::Color::Yellow);

    if(!FavoriteTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/FavoriteButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuFavorite.setTexture(FavoriteTexture);
    MenuFavorite.setScale(sf::Vector2f(60.f / FavoriteTexture.getSize().x * 0.75,  60.f / FavoriteTexture.getSize().y * 0.75));
    MenuFavorite.setPosition(25.f, 383.f);
    MenuTexts[2].setString("Favorite");
    MenuTexts[2].setPosition(145.f, 390.f);
    MenuFavorite.setColor(sf::Color(128, 0, 128, 255));

    if(!SettingTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/SettingButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuSetting.setTexture(SettingTexture);
    MenuSetting.setScale(sf::Vector2f(60.f / SettingTexture.getSize().x * 0.75,  60.f / SettingTexture.getSize().y * 0.75));
    MenuSetting.setPosition(25.f, 494.f);
    MenuTexts[3].setString("Setting");
    MenuTexts[3].setPosition(145.f, 500.f);
    MenuSetting.setColor(sf::Color(200, 200, 200, 255));

    if(!QuizTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/QuizButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuQuiz.setTexture(QuizTexture);
    MenuQuiz.setScale(sf::Vector2f(75.f / QuizTexture.getSize().x * 0.75,  75.f / QuizTexture.getSize().y * 0.75));
    MenuQuiz.setPosition(20.f, 594.f);
    MenuTexts[4].setString("Quiz");
    MenuTexts[4].setPosition(145.f, 600.f);
    MenuQuiz.setColor(sf::Color::Yellow);

    if(!AboutTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/AboutButton.png"))
    {
        cout << "Cannot load immage" << endl;
    }
    MenuAbout.setTexture(AboutTexture);
    MenuAbout.setScale(sf::Vector2f(60.f / AboutTexture.getSize().x * 0.75,  60.f / AboutTexture.getSize().y * 0.75));
    MenuAbout.setPosition(25.f, 710.f);
    MenuAbout.setColor(sf::Color::Cyan);

    MenuTexts[5].setString("About");
    MenuTexts[5].setPosition(145.f, 714.f);


    if(!MenuFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf"))
    {
        cout << "Cannot load Font" << endl;
    }

    Menu.setPosition(-250, 0);
}

MainMenu::~MainMenu() {}

void MainMenu::HandleUserInput(sf::Keyboard::Key key, sf::RenderWindow& App)
{
    if(key == sf::Keyboard::Escape) App.close();
}

void MainMenu::HandleMenuColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(LinesButton.isInBound(mousepos))
    {
        LinesButton.rect.setFillColor(sf::Color(170, 70, 0, 60));
    } else LinesButton.rect.setFillColor(sf::Color::Transparent);

    int index = menubuttons.isInBound(mousepos);

    if(index == -1 && menubuttons.selected == -1 && menubuttons.selectMove == -1) return;

    menubuttons.MoveColor(index);
}

void MainMenu::HandleMenuClick(sf::Vector2i mousepos)
{
    if(LinesButton.isInBound(mousepos))
    {
        openedMenu = !openedMenu;
        if(openedMenu)
        {
            Menu.move(movement);
            menubuttons.move(movement);
        }
        else
        {
            Menu.move(-1.f * movement);
            menubuttons.move(-1.f * movement);
        }
    }
                
    int index = menubuttons.isInBound(mousepos);
    if(mousepos.x > 350 && openedMenu == true) 
    { 
        openedMenu = false;
        Menu.move(-1.f * movement);
        menubuttons.move(-1.f * movement);
    }
    else
    {
        menubuttons.setColorButtons(index);
    }
}

void MainMenu::render(sf::RenderWindow& App)
{
    App.draw(Menu);
    for(int i = 0; i < 6; ++i) App.draw(menubuttons.buttons[i]);
    App.draw(LinesButton.rect);

    if(openedMenu)
        for(int i = 0; i < 6; ++i) App.draw(MenuTexts[i]);

    App.draw(MenuHome);
    App.draw(MenuHistory);
    App.draw(MenuFavorite);
    App.draw(MenuLines);
    App.draw(MenuSetting);
    App.draw(MenuQuiz);
    App.draw(MenuAbout);
}