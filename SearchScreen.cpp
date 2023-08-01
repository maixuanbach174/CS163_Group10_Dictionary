#include "SearchScreen.hpp"

SearchScreen::SearchScreen()
: closeButton(70, 50, 1180, 25)
{
    titleBar.lineshape.setSize(sf::Vector2f(1450.f, 15.f));
    titleBar.titleShape.setSize(sf::Vector2f(1450.f, 100.f));
    titleBar.titleShape.setFillColor(sf::Color(100, 100, 255, 255));
    titleBar.lineshape.setFillColor(sf::Color(50, 50, 100, 255));
    titleBar.titleShape.setPosition(sf::Vector2f(100.f, 0.f));
    titleBar.lineshape.setPosition(sf::Vector2f(100.f, 100.f));
    titleBar.titleFont.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/menuFont.ttf");
    titleBar.titleText.setFont(titleBar.titleFont);
    titleBar.titleText.setString("Search");
    titleBar.titleText.setCharacterSize(40);
    titleBar.titleText.setFillColor(sf::Color::White);
    titleBar.titleText.setPosition(sf::Vector2f(250.f, 25.f));
    titleBar.isMove = false;
    FontContent.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Fonts/arial.ttf");
    textContent.setCharacterSize(35);
    textContent.setFillColor(sf::Color::White);
    textContent.setFont(FontContent);
    textContent.setPosition(sf::Vector2f(150.f, 210.f));
    closeTexture.loadFromFile("D:/SE/GroupProject/CS163_Group10_Dictionary/Images/CloseButton.png");
    closeSprite.setTexture(closeTexture);
    closeSprite.setColor(sf::Color::Red);
    closeSprite.setPosition(1200, 35);
    scrollBar.railWay.setSize(sf::Vector2f(20.f, 885.f));
    scrollBar.railWay.setFillColor(sf::Color(sf::Color(80, 80, 80, 80)));
    scrollBar.railWay.setPosition(sf::Vector2f(1530, 115));
    scrollBar.bar.setSize(sf::Vector2f(20.f, 885.f));
    scrollBar.bar.setFillColor(sf::Color(sf::Color(128, 128, 128, 255)));
    scrollBar.bar.setPosition(sf::Vector2f(1530, 115));

    favouriteButton.heartSprite.setPosition(sf::Vector2f(1110.f, 34.f));
}

SearchScreen::~SearchScreen() {}

void SearchScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex, wstring& input)
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
            HandleCloseColor(App);
            favouriteButton.isInBound(sf::Mouse::getPosition(App));
            break;
        case sf::Event::MouseButtonPressed : 
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(App);
                mainmenu.HandleMenuClick(mousepos);
                screenIndex = HandleCloseClick(mousepos);
                if(favouriteButton.isInBound(mousepos))
                {
                    favouriteButton.isFavourite = !favouriteButton.isFavourite;
                    if(favouriteButton.isFavourite) favouriteButton.heartSprite.setColor(sf::Color::Red);
                    else favouriteButton.heartSprite.setColor(sf::Color::White);
                }
            }

            break;
        case sf::Event::MouseWheelMoved:
            HandleScroll(event.mouseWheel.delta);
            break;
        default:
            break;
        }
    }
}

void SearchScreen::update(MainMenu& mainmenu, wstring& passedContent)
{

    if(mainmenu.openedMenu != titleBar.isMove)
    {
        if(mainmenu.openedMenu)
        {
            titleBar.Move(mainmenu.movement);
            textContent.move(mainmenu.movement);
            closeSprite.move(mainmenu.movement);
            closeButton.rect.move(mainmenu.movement);
            closeButton.position += mainmenu.movement;
            favouriteButton.heartSprite.move(mainmenu.movement);
        } else
        {
            titleBar.Move(-1.f * mainmenu.movement);
            textContent.move(-1.f * mainmenu.movement);
            closeSprite.move(-1.f * mainmenu.movement);
            closeButton.rect.move(-1.f * mainmenu.movement);
            closeButton.position += -1.f * mainmenu.movement;
            favouriteButton.heartSprite.move(-1.f * mainmenu.movement);
        }

        titleBar.isMove = mainmenu.openedMenu;
    }

    if(content != passedContent)
    {
        content = passedContent;
        textContent.setString(content);
        scrollBar.remain = textContent.getPosition().y + textContent.getLocalBounds().height - 1000;
        scrollBar.bar.setSize(sf::Vector2f(20.f, 885.f - scrollBar.remain));
    }

}

void SearchScreen::render(sf::RenderWindow& App)
{
    App.draw(textContent);
    App.draw(titleBar.titleShape);
    App.draw(titleBar.titleText);
    App.draw(titleBar.lineshape);
    App.draw(closeButton.rect);
    App.draw(closeSprite);
    App.draw(scrollBar.railWay);
    App.draw(scrollBar.bar);
    App.draw(favouriteButton.heartSprite);
}

void SearchScreen::HandleCloseColor(sf::RenderWindow& App)
{
    sf::Vector2i mousepos= sf::Mouse::getPosition(App);

    if(closeButton.isInBound(mousepos))
    {
        closeButton.rect.setFillColor(sf::Color(50, 50, 100, 255));
    } else closeButton.rect.setFillColor(sf::Color::Transparent);
}

int SearchScreen::HandleCloseClick(sf::Vector2i mousepos)
{
    if(closeButton.isInBound(mousepos))
    {
        closeButton.rect.setFillColor(sf::Color::Transparent);
        textContent.setPosition(sf::Vector2f(textContent.getPosition().x, 210.f));
        scrollBar.bar.setPosition(sf::Vector2f(1530, 115));
        return -1;
    }
    return 6;
}

void SearchScreen::HandleScroll(int delta)
{
    if((delta > 0 && textContent.getPosition().y < 210)
    || (delta < 0 && textContent.getPosition().y + textContent.getLocalBounds().height > 1000))
    {
        textContent.move(float(delta) * sf::Vector2f(0, 70));
        scrollBar.bar.move(-1.f * float(delta) * sf::Vector2f(0, 70));
    }
}
