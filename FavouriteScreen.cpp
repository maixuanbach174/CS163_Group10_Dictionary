#include "FavouriteScreen.hpp"

FavouriteScreen::FavouriteScreen() {}

FavouriteScreen::~FavouriteScreen() {}

void FavouriteScreen::processEvent(sf::RenderWindow& App, MainMenu& mainmenu, int& screenIndex)
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
            }
            break;
        default:
            break;
        }
    }
}

void FavouriteScreen::update(MainMenu& mainmenu)
{

}

void FavouriteScreen::render(sf::RenderWindow& App)
{

}